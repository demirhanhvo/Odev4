#include "uart_log.h"
#include <stdio.h>
#include <string.h>

// transmits a simple string message over UART 
void UART_Print(UART_HandleTypeDef *huart, const char *msg) {
    // HAL_UART_Transmit requires the byte array, size, and a timeout 
    HAL_UART_Transmit(huart, (uint8_t*)msg, strlen(msg), 100);
}

// formats a float with a label and transmits it 
void UART_PrintFloat(UART_HandleTypeDef *huart, const char *label, float val, uint8_t decimals) {
    char buffer[100];
    char format_str[20];
    sprintf(format_str, "%%s: %%.%df\r\n", decimals); 
    
    // apply the formatting to our buffer 
    sprintf(buffer, format_str, label, val);
    
    // transmit the buffer
    UART_Print(huart, buffer);
}