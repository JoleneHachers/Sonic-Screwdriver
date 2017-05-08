#include <Adafruit_NeoPixel.h>
//Hacked from the original Adafruit library demo
 
#define PIN 6   //my control pin
 
// Parameter 1 = number of pixels in strip
// Parameter 2 = pin number (most are valid)
// Parameter 3 = pixel type flags, add together as needed:
//   NEO_KHZ800  800 KHz bitstream (most NeoPixel products w/WS2812 LEDs)
//   NEO_KHZ400  400 KHz (classic 'v1' (not v2) FLORA pixels, WS2811 drivers)
//   NEO_GRB     Pixels are wired for GRB bitstream (most NeoPixel products)
//   NEO_RGB     Pixels are wired for RGB bitstream (v1 FLORA pixels, not v2)
Adafruit_NeoPixel strip = Adafruit_NeoPixel(8, PIN, NEO_GRB + NEO_KHZ800);
 
 
 
void setup() {
  strip.begin();
  strip.show(); // Initialize all pixels to 'off'
}
 
void loop() {
  //Start out with a purple color
  colorWipe(strip.Color(100, 100, 100), 100); // white   //This sets the colour and speed (r,g,b),speed); this will set a progressive white forward motion
 
  //Throb read and then fade out
  PlasmaPulse(3);   //making this value higer changes the amound of time the background color runs for
}
 
// Fill the dots one after the other with a color
void colorWipe(uint32_t c, uint8_t wait) {
  for(uint16_t i=0; i<strip.numPixels(); i++) {
      strip.setPixelColor(i, c);
      strip.show();
      delay(wait);
  }
}
 
void PlasmaPulse(uint8_t wait) {
  uint16_t i, j;
  uint8_t brightness = 1;   ///think this is to do with the pulse which I ccan't see

  for(i=0; i<strip.numPixels(); i++) {
    strip.setPixelColor(i, strip.Color(0, 20, 0)); ///this sets the non traveling colour also the brightness of the non travelling color
  }
  strip.show();
  delay(wait);
  //Adjust 60 and 90 to the starting and ending colors you want to fade between. 
  for(j=170; j>=135; --j) {
    for(i=0; i<strip.numPixels(); i++) {
//      strip.setPixelColor(i, Wheel((i+j) & 255));
    }
    strip.show();
    brightness -= 6;
    strip.setBrightness(100);
    delay(wait);
  }

 // for(j=135; j<1170; j++) {
   // for(i=0; i<strip.numPixels(); i++) {
//      strip.setPixelColor(i, Wheel((i+j) & 255));
    }
   // strip.show();
   // brightness += 6;
   // strip.setBrightness(brightness);
   // delay(wait);
 // }
 
// for(i=0; i<strip.numPixels(); i++) {//
 //   strip.setPixelColor(i, strip.Color(255, 0, 0));
//  }
  //strip.show();
  //delay(wait);

//}
 
// Input a value 0 to 255 to get a color value.
// The colours are a transition r - g - b - back to r.
//uint32_t Wheel(byte WheelPos) {
 // if(WheelPos < 85) {
  // return strip.Color(WheelPos * 3, 255 - WheelPos * 3, 0);
 // } else if(WheelPos < 170) {
  // WheelPos -= 85;
   //return strip.Color(255 - WheelPos * 3, 0, WheelPos * 3);
 // } else {
  // WheelPos -= 170;
  // return strip.Color(0, WheelPos * 3, 255 - WheelPos * 3);
//  }
//}
