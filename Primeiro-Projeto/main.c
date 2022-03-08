/**
 * \brief Primeiro-Projeto MSP430
 *
 * \author Bruno Benedetti <brunobenedetti45@gmail.com>
 *
 * \version 1.0.0
 *
 * \date 02/03/2022
 *
 */

#include <functions.h>

int current_mode =1;

void main(void)
{
    my_setup();

    while(1)
    {
        button_read(&current_mode);
        switch_mode(&current_mode);
    }
}
