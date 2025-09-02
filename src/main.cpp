#include <Arduino.h> 
#include <FastLED.h>
#define MA_BROCHE_ANGLE 32



CRGB monPixel;


void setup() {
  
  Serial.begin(115200);

  //Communication céréale (Frosted Flakes)


  FastLED.addLeds<WS2812, 27, GRB>(&monPixel, 1);

}

void loop() {
 
int lectureAnalogique;
lectureAnalogique = analogRead(MA_BROCHE_ANGLE);


Serial.print(lectureAnalogique);
Serial.println();
delay(100);

if(lectureAnalogique >= 2000){
  monPixel = CRGB(25, 225, 50);
  FastLED.show();
}
else{
  monPixel = CRGB(0, 0, 0);
  FastLED.show();
}

}
