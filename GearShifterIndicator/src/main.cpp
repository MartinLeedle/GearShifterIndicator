#include <Arduino.h>
#include "PinChangeInterrupt.h"
#include <avr/sleep.h>
/*Since mask 2 is used 8 input can be used,
  so up to a 7 speed with reverse
  I dont think anyone with an 8 speed+ manual would use this

  Current Config uses D0-D5
*/
#define firstGear 1
#define secondGear 2
#define thirdGear 5
#define fourthGear 6
#define fifthGear 7
#define reverseGear 8

void blinkLed() {
  // Switch Led state
  digitalWrite(LED_BUILTIN, !digitalRead(LED_BUILTIN));
}
void setup() {
  // put your setup code here, to run once:
   pinMode(firstGear, INPUT_PULLUP);
   pinMode(secondGear, INPUT_PULLUP);
   pinMode(thirdGear, INPUT_PULLUP);
   pinMode(fourthGear, INPUT_PULLUP);
   pinMode(fifthGear, INPUT_PULLUP);
   pinMode(reverseGear, INPUT_PULLUP);
   pinMode(LED_BUILTIN, OUTPUT);

  // Manually blink once to test if LED is functional
  blinkLed();
  delay(1000);
  blinkLed();

    attachPCINT(firstGear, blinkLed, CHANGE);
}


void loop() {
  // put your main code here, to run repeatedly:
  set_sleep_mode (SLEEP_MODE_PWR_DOWN);  
  //sleep_mode ();  
}