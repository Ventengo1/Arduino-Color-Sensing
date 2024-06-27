#include "RobotSetup.hpp"
using namespace srbots;
OLEDDisplay oled(port0);
ColorDetector color(port0);


void setup() {
  RobotSetup();
    oled.init();
   color.init();




  pinMode(20, INPUT);
  while (digitalRead(20));
 
}


void loop() {
  uint16_t r, g, b, c;


  if (color.colorRead()) {
      color.getColors(r, g, b, c);
      if (c > threshold) {
        rightmotor.speed(0);
        leftmotor.speed(0);


      }
      else {
            rightmotor.speed(30);
            leftmotor.speed(30);
            
      }


  }


}
     

