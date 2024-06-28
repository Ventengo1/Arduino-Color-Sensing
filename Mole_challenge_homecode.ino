#include "RobotSetup.hpp"
using namespace srbots;
OLEDDisplay oled(port0);
UltraSonic ping;
ColorDetector color(port0);


void setup() {
  RobotSetup();
  oled.init();
  color.init();
  ping.init();


  pinMode(20, INPUT);
  while (digitalRead(20))
    ;


  uint16_t r = 0, g = 0, b = 0, c = 0;
  color.getColors(r, g, b, c);
  while (c < 70) { 
    //normally this value is 160
    leftmotor.speed(60);
    rightmotor.speed(60);
    color.getColors(r, g, b, c);
  }
  leftmotor.speed(0);
  rightmotor.speed(0);
  delay(2000);
  leftmotor.speed(-0);
  rightmotor.speed(85);
  delay(1500);
}
 



void loop() {
   int counter = 0;
  int32_t distance;




  uint16_t r = 0, g = 0, b = 0, c = 0;
  color.getColors(r, g, b, c);
  if (c > 75) {
    //normally the c value is 125
    leftmotor.speed(35);
    rightmotor.speed(80);
  } else {
    leftmotor.speed(80);
    rightmotor.speed(35);
  }




  if (distance < 8) {
    oled.clear();
    oled.drawtext(0, "mole detected");
    oled.updateDisplay();
    counter++;
    leftmotor.speed(0);
    rightmotor.speed(0);
    delay(500);
    leftmotor.speed(60);
    rightmotor.speed(60);
    delay(2000)
    leftmotor.speed(-60);
    rightmotor.speed(-60);
    delay(2000);
  else {
     color.getColors(r, g, b, c);
   if (c > 75) {
     //normally the c value is 125
     leftmotor.speed(35);
     rightmotor.speed(80);
  } else {
      leftmotor.speed(80);
      rightmotor.speed(35);
  }


  }
}




//move forward 40cm
//while (counter < 4) {
//line follow
