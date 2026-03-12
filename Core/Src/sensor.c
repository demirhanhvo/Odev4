#include "sensor.h"

// Reads the 12-bit ADC value using polling [cite: 44, 45]
uint16_t Sensor_ReadRawADC(ADC_HandleTypeDef *hadc) {
    uint16_t raw_val = 0xFFFF; // Default error value
    
    HAL_ADC_Start(hadc); [cite: 44]
    
    // Wait up to 100ms for conversion to finish 
    if (HAL_ADC_PollForConversion(hadc, 100) == HAL_OK) { [cite: 45, 60]
        raw_val = HAL_ADC_GetValue(hadc); [cite: 45]
    }
    
    return raw_val;
}

// Converts 0-4095 range to 0.0V - 3.3V [cite: 46, 47]
float Sensor_ConvertToVoltage(uint16_t raw_value) {
    return ((float)raw_value / 4095.0f) * 3.3f; [cite: 47]
}

// Converts 0-4095 range to 0.0% - 100.0% [cite: 46, 48]
float Sensor_ConvertToPercentage(uint16_t raw_value) {
    return ((float)raw_value / 4095.0f) * 100.0f; [cite: 48, 51]
}