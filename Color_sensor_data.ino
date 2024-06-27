#include "RobotSetup.hpp"
using namespace srbots;
OLEDDisplay oled(port0);
ColorDetector color(port0);

void setup() {
  RobotSetup();
  oled.init();
  color.init();
  

}

void loop() {
  uint16_t r=0, g=0, b=0, c=0;
  char buff[100];

  color.getColors(r, g, b, c);
  oled.clear();
  sprintf(buff, "red : %4d", r);
  oled.drawtext(0, buff);
  oled.updateDisplay();

}
