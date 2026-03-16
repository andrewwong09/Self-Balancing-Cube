#ifndef VOLTAGE_READER_H
#define VOLTAGE_READER_H

#include <Arduino.h>
#include "esp_adc_cal.h"

class VoltageReader {

  public:
    VoltageReader(int pin, float r1, float r2, int samples = 64);

    void begin();
    float readVoltage();

  private:
    int _pin;
    float _r1;
    float _r2;
    int _samples;

    esp_adc_cal_characteristics_t adc_chars;

    uint32_t readAverage();
};

#endif