#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <msp430.h>

#define SLOW   55000
#define QUICK  15000
#define MEDIUM 35000

/**
 * \brief Setup
 */
void my_setup();

/**
 * \brief Delay function
 *
 * \param[in] time integer that is proportional to the time delay
 *
 */
void delay(volatile unsigned int time);

/**
 * \brief Turns off all LEDs
 */
void turn_off_LED();

/**
 * \brief Blink all LEDs function
 *
 * \param[in] time integer that is proportional to the time delay
 *
 */
void blink_all(volatile unsigned int time);

/**
 * \brief Slide animation
 *
 * \param[in] time integer that is proportional to the time delay
 *
 */
void slide(volatile unsigned int time);

/**
 * \brief Slide2 animation
 *
 * \param[in] time integer that is proportional to the time delay
 *
 */
void slide2(volatile unsigned int time);

/**
 * \brief Function that switch between all the modes
 *
 * \param[in] mode Keeps track of the current mode
 *
 */
void switch_mode(int *mode);

/**
 * \brief Function that reads the button input to change modes
 *
 * \param[in] mode Keeps track of the current mode
 *
 */
void button_read(int *mode);

#endif /* FUNCTIONS_H */
