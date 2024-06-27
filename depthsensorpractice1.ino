#include "RobotSetup.hpp"
using namespace srbots;
OLEDDisplay oled(port0);
UltraSonic ping;

void setup() {
  RobotSetup();
  oled.init();
  ping.init();
}
char buff[100];

void loop() {
  int32_t dist;
  ping.get(dist);
  if (dist < 30) {
    oled.clear();
    oled.drawtext(0, "under 30");
    oled.updateDisplay();
  }
  else {
    oled.clear();
    oled.drawtext(1, "farther than 30");
    oled.updateDisplay();
}

  }

