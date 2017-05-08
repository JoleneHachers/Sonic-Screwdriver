/********************************************************************************************************
  neopixel_moving1:
  Written by Scott Kildall
  
  This sketch will show three bands of solid colors on the NeoPixel strip
  the 1st 1/3 will be 1 color, the 2nd 1/3 another, and the last 1/3 a different color
  A switch at pin 4 will turn the whole strip off.
  
  A timing loop will be setup so that we cycle the colors
  
---------------------------------------------------------------------------------------------------------
NeoPixel Information for initializing the strip, below
  60ma/pixel for current load
  Parameter 1 = number of pixels in strip
  Parameter 2 = pin number (most are valid)
  Parameter 3 = pixel type flags, add together as needed:
    NEO_KHZ800  800 KHz bitstream (most NeoPixel products w/WS2812 LEDs)
    NEO_KHZ400  400 KHz (classic 'v1' (not v2) FLORA pixels, WS2811 drivers)
    NEO_GRB     Pixels are wired for GRB bitstream (most NeoPixel products)
    NEO_RGB     Pixels are wired for RGB bitstream (v1 FLORA pixels, not v2)
**********************************************************************************************************/

#include <Adafruit_NeoPixel.h>
 
// the data pin for the NeoPixels
int neoPixelPin = 6;

// How many NeoPixels we will be using, charge accordingly
int numPixels = 8;

// Instatiate the NeoPixel from the ibrary
Adafruit_NeoPixel strip = Adafruit_NeoPixel(numPixels, neoPixelPin, NEO_GRB + NEO_KHZ800);

// Color set #1
int r1 = 255;
int g1 = 0;
int b1 = 0;

// Color set #2
int r2 = 255;
int g2 = 255;
int b2 = 0;

// Color set #3
int r3 = 0;
int g3 = 255;
int b3 = 255;

// Color set #4  ///I added this
int r4 = 80;
int g4 = 80;
int b4 = 80; 

// our button
//int switchPin = 4;

int start1 = 0;
int start2 = 20;
int start3 = 40;
int start4 = 60;   /// I added this

// a pre-processor macro
#define DELAY_TIME (500)
   
void setup() {
  strip.begin();  // initialize the strip
  strip.show();   // make sure it is visible
  strip.clear();  // Initialize all pixels to 'off'
}

void loop() {
  // Check to see if switch is on/off and call the proper function   /// I took this out belive if you add a button the leds will turn off.
//  if( digitalRead(switchPin) == true )
     allOff();
//  else
     activate();
     
  // delay for the purposes of debouncing the switch
  delay(DELAY_TIME);
}

void allOff() {
  strip.clear();
   strip.show();
}

// the adjustStarts() function will move the starting point of the for loop to imitiate a cycling effect
void activate() {
   adjustStarts();
   
   // first 20 pixels = color set #1
    for( int i = start1; i < start1+20; i++ ) {
       strip.setPixelColor(i, r1, g1, b1 );
    }
    
    // next 20 pixels = color set #2
    for( int i = start2; i < start2+20 ; i++ ) {
       strip.setPixelColor(i, r2, g2, b2 );
    }
    
     // last 20 pixels = color set #3
    for( int i = start3; i < start3+20; i++ ) {
       strip.setPixelColor(i, r3, g3, b3 );
    }

       // last 20 pixels = color set #4             //I added this
    for( int i = start4; i < start4+20; i++ ) {
       strip.setPixelColor(i, r4, g4, b4 );
    }
  strip.show();
}

// calls the incrementStart() function to move the offsets for each NeoPixel
void adjustStarts() {
  start1 = incrementStart(start1);
  start2 = incrementStart(start2);
  start3 = incrementStart(start3);
  start4 = incrementStart(start4);    ///I added this
}

// will add 20 to the start value, resetting it to zero when we hit the max number of pixels
int incrementStart(int startValue) {
  startValue = startValue + 20;
  if( startValue == 80 )          // I had to change this from 60 to 80 to get the white light to show
    startValue = 0;
    
  return startValue;
}

