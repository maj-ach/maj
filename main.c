#include <stdio.h>
#include <stdlib.h>

#include "header.h"
#include "opendir.h"

/**
 * Main
 * @param void
 * @return int
*/
int main(void)
{
    determine_program_status();
    init_values();
    enable_raw_mode();

    while (1)
    {
        call_open_directory();
        call_refresh_screen();
        call_input();
    }

    return EXIT_SUCCESS;
}