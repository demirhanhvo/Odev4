#ifndef SENSOR_H
#define SENSOR_H

#include "main.h" // gives access to HAL types like ADC_HandleTypeDef

// Function prototypes
uint16_t Sensor_ReadRawADC(ADC_HandleTypeDef *hadc);
float Sensor_ConvertToVoltage(uint16_t raw_value);
float Sensor_ConvertToPercentage(uint16_t raw_value);

#endif