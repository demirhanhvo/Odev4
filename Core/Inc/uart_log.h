#ifndef UART_LOG_H
#define UART_LOG_H

#include "main.h"

// prototypes specified in the assignment 
void UART_Print(UART_HandleTypeDef *huart, const char *msg); 
void UART_PrintFloat(UART_HandleTypeDef *huart, const char *label, float val, uint8_t decimals); 

#endif 