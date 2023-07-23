#define _DEFAULT_SOURCE // -D_DEFAULT_SOURCE

#include <dirent.h>
#include <string.h>

#include "structs.h"
#include "defines.h"
#include "openfile.h"
#include "addl_funcs.h"

/**
 * Write in array
 * @param unsigned int *count
 * @param const unsigned int length
 * @param char array [][length]
 * @param const char *string;
 * @return void
*/
void write_in_array(unsigned int *count, const unsigned int length, char array[][length], const char *string)
{
    unsigned int string_length = strlen(string);

    if (string_length < (length - 1) && *count < ELEMENTS_TOTAL_AMOUNT)
    {
        for (unsigned int i = 0; i < string_length; i++)
            array[*count][i] = *(string + i);

        ++(*count);
    }
}

/**
 * Read directory
 * @param DIR *directory_pointer
 * @return void
*/
void read_directory(DIR *directory_pointer)
{
    struct dirent *entry = NULL;
    while ((entry = readdir(directory_pointer)) != NULL)
    {
        if (entry->d_type == DT_DIR)
        {
            write_in_array(&od.directories_count, NAME_LENGTH, od.directories, entry->d_name);
            od.directories[od.directories_count - 1][strlen(entry->d_name)] = '/';
        }

        else if (entry->d_type == DT_REG)
            write_in_array(&od.files_count, NAME_LENGTH, od.files, entry->d_name);
    }
}

/**
 * Open directory
 * @param void
 * @return void
*/
void open_directory(char *address)
{
    DIR *directory_pointer = NULL;

    reset_values();

    if ((directory_pointer = opendir(address)) != NULL)
    {
        con.directory_state = 1;

        read_directory(directory_pointer);

        // sort_directories();
        // sort_files();

        concatenate_arrays(NAME_LENGTH, od.directories, od.files);

        closedir(directory_pointer);
    }
    else
    {
        // con.directory_state = 0;
        call_open_file(address);
    }
}

/**
 * Call open directory
 * @param void
 * @return void
*/
void call_open_directory(void)
{
    address_bar_update(LENGTH, od.address_bar, od.buffer);

    if (con.commit_directory_change == 1)
    {
        con.commit_directory_change = 0;
        open_directory(od.address_bar);
    }
}