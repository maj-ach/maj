#include <stdio.h>
#include <errno.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#include "structs.h"
#include "defines.h"
#include "addl_funcs.h"

/**
 * Call open file
 * @param char *address
 * @return void
*/
void call_open_file(char *address)
{
    FILE *file_pointer = NULL;

    *(address + (strlen(address) - 1)) = '\0';

    if ((file_pointer = fopen(address, "rb")) != NULL)
    {
        if (fclose(file_pointer) != 0)
            die(strerror(errno));

        char command[100] = {'\0'};
        snprintf(command, sizeof(command), "%s %s", NANO, address);

        if (system(command) == -1)
            die(strerror(errno));
    }

    *(address + (strlen(address) - 1)) = '/';
}