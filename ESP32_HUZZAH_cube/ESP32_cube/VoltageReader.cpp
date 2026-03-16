#include "VoltageReader.h"

VoltageReader::VoltageReader(int pin, float r1, float r2, int samples) {
  _pin = pin;
  _r1 = r1;
  _r2 = r2;
  _samples = samples;
}

void VoltageReader::begin() {

  analogReadResolution(12);
  analogSetPinAttenuation(_pin, ADC_11db);

  esp_adc_cal_characterize(
    ADC_UNIT_1,
    ADC_ATTEN_DB_11,
    ADC_WIDTH_BIT_12,
    1100,
    &adc_chars
  );
}

uint32_t VoltageReader::readAverage() {

  uint32_t sum = 0;

  for (int i = 0; i < _samples; i++) {
    sum += analogRead(_pin);
    delayMicroseconds(200);
  }

  return sum / _samples;
}

float VoltageReader::readVoltage() {

  uint32_t raw = readAverage();

  uint32_t mV = esp_adc_cal_raw_to_voltage(raw, &adc_chars);

  float vPin = mV / 1000.0;

  float vInput = vPin * ((_r1 + _r2) / _r2);

  return vInput;
}