#include <functions.h>

void my_setup()
{
    // stop watchdog timer
    WDTCTL = WDTPW | WDTHOLD;

    /*
     * P1.3 as Inputs (0)
     * P1.0, P1.1, P1.2, P1.4, P1.5, P1.6 as Outputs (1)
     * P1DIR = 01110111
     */
    P1DIR |= 0x077;

    //Turning off all the LEDs
    turn_off_LED();

    //Enable the pull up resistor to P1.3
    P1REN |= 0x08;
    P1OUT |= 0x08;
}

void delay(volatile unsigned int time)
{
    for(time; time>0; time--);     // delay
}

void turn_off_LED()
{
    P1OUT &= 0x00;
}

void blink_all(volatile unsigned int time)
{
    P1OUT ^= 0x077;
    delay(time);
}


void slide(volatile unsigned int time)
{
    P1OUT ^= 0x01;
    delay(time);
    P1OUT ^= 0x01;

    P1OUT ^= 0x02;
    delay(time);
    P1OUT ^= 0x02;

    P1OUT ^= 0x04;
    delay(time);
    P1OUT ^= 0x04;

    P1OUT ^= 0x040;
    delay(time);
    P1OUT ^= 0x040;

    P1OUT ^= 0x010;
    delay(time);
    P1OUT ^= 0x010;

    P1OUT ^= 0x20;
    delay(time);
    P1OUT ^= 0x20;

    //end of the slide, now going back

    P1OUT ^= 0x20;
    delay(time);
    P1OUT ^= 0x20;

    P1OUT ^= 0x010;
    delay(time);
    P1OUT ^= 0x010;

    P1OUT ^= 0x040;
    delay(time);
    P1OUT ^= 0x040;

    P1OUT ^= 0x04;
    delay(time);
    P1OUT ^= 0x04;

    P1OUT ^= 0x02;
    delay(time);
    P1OUT ^= 0x02;

    P1OUT ^= 0x01;
    delay(time);
    P1OUT ^= 0x01;
}

void slide2(volatile unsigned int time)
{
    int i;
    int j;
    int a =7;
    for(j =1; j<7; j++)
    {
        for(i =1; i<a; i++)
        {
            switch(i)
            {
            case 1:
                P1OUT ^= 0x01;
                delay(time);
                break;

            case 2:
                P1OUT ^= 0x01;
                P1OUT ^= 0x02;
                delay(time);
                break;

            case 3:
                P1OUT ^= 0x02;
                P1OUT ^= 0x04;
                delay(time);
                break;

            case 4:
                P1OUT ^= 0x04;
                P1OUT ^= 0x040;
                delay(time);
                break;

            case 5:
                P1OUT ^= 0x040;
                P1OUT ^= 0x010;
                delay(time);
                break;

            case 6:
                P1OUT ^= 0x010;
                P1OUT ^= 0x020;
                delay(time);
                break;
            }
        }
        a--;
    }
    //Turning off the LEDs

    delay(time);
    P1OUT ^= 0x020;
    delay(time);
    P1OUT ^= 0x010;
    delay(time);
    P1OUT ^= 0x040;
    delay(time);
    P1OUT ^= 0x04;
    delay(time);
    P1OUT ^= 0x02;
    delay(time);
    P1OUT ^= 0x01;
}

void switch_mode(int *mode)
{
    switch(*mode)
    {
    case 1:
        blink_all(SLOW);
        break;

    case 2:
        slide(MEDIUM);
        break;

    case 3:
        slide2(QUICK);
        break;

    default:
        *mode =1;
        break;
    }
}

void button_read(int *mode)
{
    if((P1IN & 0x08) != 0x08)
    {
        (*mode)++;
        delay(SLOW);
    }
    if(*mode == 4)
    {
        *mode =1;
        delay(SLOW);
    }
}
