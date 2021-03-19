/*
 * i2c-lcd.h
 *
 *  Created on: Mar 14, 2021
 *      Author: Bilge
 */
#include "stm32f1xx_hal.h"

void lcd_init (void);   // initialize lcd

void lcd_send_cmd (char cmd);  // send command to the lcd

void lcd_send_data (char data);  // send data to the lcd

void lcd_send_string (char *str);  // send string to the lcd

void lcd_clear (void);
