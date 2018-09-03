#include "HX711.h"

#define DOUT  46
#define CLK  44

HX711 scale(DOUT, CLK);

const float calibration_factor = -96650;

void setup() {
  // Initialize scale on right pins
  hx711.init(CLK, DOUT);

  scale.set_scale(-96650);  //Calibration adjustment
  scale.tare();             //Reset the scale to 0  
}

void loop() {  
  Serial.plrintln(scale.get_units(), 3); // up to 3 decimals
}
