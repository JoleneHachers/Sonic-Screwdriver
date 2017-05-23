//SONIC PROTOTYPE CODE MODIFIED        

//                            Written by a complete amateur so take good care!

//            This is the code that will go in to my sonic screwdriver
//            Hardware includes Adafruit Feather 32U4, Music maker feather wing with amp Adafruit NeoPixel stick
//            
// lines 88 to 133 were added in the hope of trying to get a - when sw8 pulled low play a random selection of sw1-7... however not working becuase somthings wrong
//    can you see it?


#include <Adafruit_NeoPixel.h>
#ifdef __AVR__
#include <avr/power.h>
#endif

#define PIN A1

const int sw1 = 2;     // This sets the name of the pins
const int sw2 = 3;
const int sw3 = 5;
const int sw4 = 6;
const int sw5 = 9;
const int sw6 = 10;
const int sw7 = 11;
const int sw8 = 12;

                                                                                struct RGB {          //for fire this could posibly reside elsewhere in the script but I'm not too sure where
                                                                                byte r;
                                                                                byte g;
                                                                                byte b;
                                                                                };

                                                                                RGB flameColors[] = {
                                                                                //  { 226, 121, 35},  // Orange flame   /// select what colour fire you want here 
                                                                                //  { 158, 8, 148},   // Purple flame 
                                                                                //  { 74, 150, 12},   // Green flame
                                                                                //  { 226, 15, 30}    // Red flame
                                                                                                { 15,50,148}      //Blue flame
                                                                                };
                                                                                //  Number of flame colors
                                                                                int NUMBER_OF_COLORS = sizeof(flameColors) / sizeof(RGB);

                                                                                //  Tracks the current color
                                                                                int currentColorIndex = 0;

                                                                                //  The button pin
                                                                                const int buttonPin = 2;

                                                                                //  Variable for reading the pushbutton status
                                                                                int buttonState = 0;         

                                                                                //  Tracking if it's ok to shift colors or not
                                                                                bool okToChangeColors = true;


    

                                                                                float redStates[8];               // I added these for twinkle
                                                                                float blueStates[8];
                                                                                float greenStates[8];
                                                                                float fadeRate = 0.96;           

                                                                                int totalLEDs = 8;                // added for tardis
                                                                                int ledFadeTime = 5;

    
  Adafruit_NeoPixel strip = Adafruit_NeoPixel(8, A1, NEO_GRB + NEO_KHZ800);

    // IMPORTANT: To reduce NeoPixel burnout risk, add 1000 uF capacitor across
    // pixel power leads, add 300 - 500 Ohm resistor on first pixel's data input
    // and minimize distance between Arduino and first pixel.  Avoid connecting
    // on a live circuit...if you must, connect GND first.


    void setup() 
  {
     
       pinMode(sw1, INPUT_PULLUP);    // the pins for your pull low are set here
       pinMode(sw2, INPUT_PULLUP);
       pinMode(sw3, INPUT_PULLUP);
       pinMode(sw4, INPUT_PULLUP);
       pinMode(sw5, INPUT_PULLUP);
       pinMode(sw6, INPUT_PULLUP);
       pinMode(sw7, INPUT_PULLUP);
       pinMode(sw8, INPUT_PULLUP);
                   
                   }
/////////////////////////////////////////////////////////////////////////////////// random add



void loop(std::uniform_int_distribution<>& dis, std::mt19937& gen) 
{
    if (digitalRead(sw1) == LOW) doAction(2);
    if (digitalRead(sw2) == LOW) doAction (3);                                                                                                          
    if (digitalRead(sw3) == LOW) doAction (4);  
    if (digitalRead(sw4) == LOW) doAction (5);                        
    if (digitalRead(sw5) == LOW) doAction (6);
    if (digitalRead(sw6) == LOW) doAction (7)
    if (digitalRead(sw7) == LOW) doAction (8)
    if (digitalRead(sw8) == LOW) doAction(dis(gen));
}                       

int main()
{
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(1, 7);

    while (true)
    {
        loop(dis, gen);
    }

////////////////////////////////////////////////////////////////////////////////// random finish
      strip.begin();
      strip.show(); // Initialize all pixels to 'off'
    }

//    void loop() 
//  {
     // Some example procedures showing how to display to the pixels:
     // if (digitalRead(sw1) == LOW) colorWipe(strip.Color(255, 0, 0), 50, sw1); // Red
     // if (digitalRead(sw7) == LOW) colorWipe(strip.Color(0, 255, 0), 50, sw7); // Green
     // if (digitalRead(sw2) == LOW) skip(150, 0, 150, 250, sw2);                                                                                                                                     
     // if (digitalRead(sw1) == LOW) BouncingBalls(0, 0, 255, 3, sw1);                            
     // if (digitalRead(sw3) == LOW) twinkle (sw3);                                       
     // if (digitalRead(sw3) == LOW) colorWipe(strip.Color(0, 0, 255), 50, sw3); // Blue
     // if (digitalRead(sw4) == LOW) theaterChase(strip.Color(127, 127, 127), 50, sw4); // White
     // if (digitalRead(sw5) == LOW) theaterChase(strip.Color(127, 0, 0), 50, sw5); // Red
     // if (digitalRead(sw6) == LOW) theaterChase(strip.Color(0, 0, 127), 50, sw6); // Blue
     // if (digitalRead(sw4) == LOW) rainbow(20, sw4);
     // if (digitalRead(sw5) == LOW) rainbowCycle(20, sw5);
     // if (digitalRead(sw6) == LOW) fire (sw6);
     // if (digitalRead(sw7) == LOW) theaterChaseRainbow(50, sw7);
     ///if (digitalRead(sw8) == LOW) tardis(sw8);
     // if (digitalRead(sw8) == LOW) scanner (sw8);                                                                                     
//    }

void doAction(int pin)

{
    switch (pin)
    {
    case 2: skip(150, 0, 150, 250, sw2); return;
    case 3: colorWipe(strip.Color(255, 0, 0), 50, sw1); return; // Red
    case 4: colorWipe(strip.Color(0, 255, 0), 50, sw7); return;// Green
    case 5: skip(150, 0, 150, 250, sw2); return;                                                                                                                                    
    case 6: BouncingBalls(0, 0, 255, 3, sw1); return;                           
    case 7: twinkle (sw3); return;                                       
    case 8: colorWipe(strip.Color(0, 0, 255), 50, sw3); return; // Blue
    case 9: theaterChase(strip.Color(127, 127, 127), 50, sw4); return; // White
    case 10: theaterChase(strip.Color(127, 0, 0), 50, sw5); return;// Red
    case 11: theaterChase(strip.Color(0, 0, 127), 50, sw6); return;// Blue
    case 12: rainbow(20, sw4); return;
    case 13: rainbowCycle(20, sw5); return;
    case 14: fire (sw6); return;
    case 15: theaterChaseRainbow(50, sw7); return;
    case 16: tardis(sw8); return
    }
}
/////////////////////////////////////////////////////////////////////////////      colorWipe                /////////////////////////////////
    // Fill the dots one after the other with a color
    void colorWipe(uint32_t c, uint8_t wait, uint8_t sw) 
  {
      for(uint16_t i=0; i<strip.numPixels(); i++) 
    {
        strip.setPixelColor(i, c);
        strip.show();
        if (digitalRead(sw) == HIGH) return;
        delay(wait);
      }
    }
/////////////////////////////////////////////////////////////////////////              rainbow                               ////////////////////////////////////////
    void rainbow(uint8_t wait, uint8_t sw) 
  {
      uint16_t i, j;

      for(j=0; j<256; j++) 
    {
        for(i=0; i<strip.numPixels(); i++) 
    {
          strip.setPixelColor(i, Wheel((i+j) & 255));
          if (digitalRead(sw) == HIGH) return;
        }
        strip.show();
        delay(wait);
      }
   }
////////////////////////////////////////////////////////////////////////////////////////                rainbowCycle                ///////////////////////////
    // Slightly different, this makes the rainbow equally distributed throughout
   void rainbowCycle(uint8_t wait, uint8_t sw) 
  {
      uint16_t i, j;

      for(j=0; j<256*5; j++) 
    {
        // 5 cycles of all colors on wheel
        for(i=0; i< strip.numPixels(); i++) 
    {
          strip.setPixelColor(i, Wheel(((i * 256 / strip.numPixels()) + j) & 255));
          if (digitalRead(sw) == HIGH) return;
        }
        strip.show();
        delay(wait);
      }
    }
/////////////////////////////////////////////////////////////////////////////////////      Theatre-style                //////////////////////////////////////
    //Theatre-style crawling lights.
    void theaterChase(uint32_t c, uint8_t wait, uint8_t sw) 
  {
      for (int j=0; j<10; j++) 
    {
        //do 10 cycles of chasing
        for (int q=0; q < 3; q++) 
    {
          for (uint16_t i=0; i < strip.numPixels(); i=i+3) 
      {
            strip.setPixelColor(i+q, c);    //turn every third pixel on
            if (digitalRead(sw) == HIGH) return;
          }
          strip.show();

          delay(wait);

          for (uint16_t i=0; i < strip.numPixels(); i=i+3) 
      {
            strip.setPixelColor(i+q, 0);        //turn every third pixel off
          }
        }
      }
    }
//////////////////////////////////////////////////////////////////////////////////            Theatre-style rainbow                ///////////////////////////////////////////
    //Theatre-style crawling lights with rainbow effect
    void theaterChaseRainbow(uint8_t wait, uint8_t sw) 
  {
      for (int j=0; j < 256; j++) 
    {  
        // cycle all 256 colors in the wheel
        for (int q=0; q < 3; q++) 
    {
          for (uint16_t i=0; i < strip.numPixels(); i=i+3) 
      {
            strip.setPixelColor(i+q, Wheel( (i+j) % 255));    //turn every third pixel on      
            if (digitalRead(sw) == HIGH) return;
          }
          strip.show();

          delay(wait);

          for (uint16_t i=0; i < strip.numPixels(); i=i+3) 
      {
            strip.setPixelColor(i+q, 0);        //turn every third pixel off
         }
        }
      }
    }
////////////////////////////////////////////////////////////////////////////////////////////////                Skip                ////////////////////////////////////////////////////////////        
    //Skip example
    void skip(int R,int G,int B,int sp, uint8_t sw) 
  {
      for(int i=0;i<strip.numPixels();i=i+2) 
    {
        strip.setPixelColor(i,strip.Color(R,G,B));
        strip.show();
        if (digitalRead(sw) == HIGH) return;
       delay(sp);
      }
    }
    
//////////////////////////////////////////////////////////////////////////////////////////////                    BouncingBalls                //////////////////////////////////////////////////////
    //BouncingBalls example
   void BouncingBalls(byte red, byte green, byte blue, int BallCount, uint8_t sw) 
{
  float Gravity = -9.81;
  int StartHeight = 1;
  float Height[BallCount];
  float ImpactVelocityStart = sqrt( -2 * Gravity * StartHeight );
  float ImpactVelocity[BallCount];
  float TimeSinceLastBounce[BallCount];
  int   Position[BallCount];
  long  ClockTimeSinceLastBounce[BallCount];
  float Dampening[BallCount];
  for (int i = 0 ; i < BallCount ; i++) 
  {  
    ClockTimeSinceLastBounce[i] = millis();
    Height[i] = StartHeight;
    Position[i] = 0;
    ImpactVelocity[i] = ImpactVelocityStart;
    TimeSinceLastBounce[i] = 0;
    Dampening[i] = 0.90 - float(i)/pow(BallCount,2);
  }

    while (true) 
    {
      for (int i = 0 ; i < BallCount ; i++) 
      {
      TimeSinceLastBounce[i] =  millis() - ClockTimeSinceLastBounce[i];
      Height[i] = 0.5 * Gravity * pow( TimeSinceLastBounce[i]/1000 , 2.0 ) + ImpactVelocity[i] * TimeSinceLastBounce[i]/1000;
      if ( Height[i] < 0 ) 
        {                      
          Height[i] = 0;
          ImpactVelocity[i] = Dampening[i] * ImpactVelocity[i];
          ClockTimeSinceLastBounce[i] = millis();
          if ( ImpactVelocity[i] < 0.01 ) 
            {
            ImpactVelocity[i] = ImpactVelocityStart;
            }
        }
      Position[i] = round( Height[i] * (8 - 1) / StartHeight);
      }
         for (int i = 0 ; i < BallCount ; i++) 
        {
          setPixel(Position[i],red,green,blue);
       } 
   
    showStrip();
                if (digitalRead(sw) == HIGH) return;
    setAll(0,0,0);
    }
}

void showStrip() 
{

#ifdef ADAFRUIT_NEOPIXEL_H

   strip.show();
#endif
#ifndef ADAFRUIT_NEOPIXEL_H

   FastLED.show();
#endif
}

void setPixel(int Pixel, byte red, byte green, byte blue) 
{
#ifdef ADAFRUIT_NEOPIXEL_H
   // NeoPixel
   strip.setPixelColor(Pixel, strip.Color(red, green, blue));
#endif
#ifndef ADAFRUIT_NEOPIXEL_H
   // FastLED
   leds[Pixel].r = red;
   leds[Pixel].g = green;
   leds[Pixel].b = blue;
#endif
}

void setAll(byte red, byte green, byte blue) 
{
  for(int i = 0; i < 8; i++ ) 
  {
    setPixel(i, red, green, blue);
  }
  showStrip();
}

////////////////////////////////////////////////////////////////////////////////////////                twinkle                ///////////////////////////////////////
            
void twinkle (uint8_t sw)
{
{
    for(uint16_t l = 0; l < 8; l++) 
  {
    
 
    redStates[l] = 0;
    greenStates[l] = 0;
    blueStates[l] = 0;
  }
}


//while (true); 
{
   if (random(20) == 1) 
   {
      uint16_t i = random(8);
      if (redStates[i] < 1 && greenStates[i] < 1 && blueStates[i] < 1) 
    {
        redStates[i] = random(256);
        greenStates[i] = random(256);
        blueStates[i] = random(256);
      }
    }
    
    for(uint16_t l = 0; l < 8; l++) 
  {
      if (redStates[l] > 1 || greenStates[l] > 1 || blueStates[l] > 1) 
    {
      strip.setPixelColor(l, redStates[l], greenStates[l], blueStates[l]);
        
      if (redStates[l] > 1) 
      {
        redStates[l] = redStates[l] * fadeRate;
      } else 
      {
        redStates[l] = 0;
      }
        
      if (greenStates[l] > 1) 
      {
        greenStates[l] = greenStates[l] * fadeRate;
      }  else 
      {
        greenStates[l] = 0;
      }
        
      if (blueStates[l] > 1) 
      {
      blueStates[l] = blueStates[l] * fadeRate;
      } else 
      {
          blueStates[l] = 0;
      }
        
    } 
    else 
      {
        strip.setPixelColor(l, 0, 0, 0);
      }
    }
    strip.show();
                if (digitalRead(sw) == HIGH) return;
    delay(5);
}
}

/////////////////////////////////////////////////////////////////////////              fire                //////////////////////////////////////////////////////
void fire(uint8_t sw8) 
{
    //  Get the current colors based on the color index:
     RGB currentColor = flameColors[currentColorIndex];

//     // read the state of the pushbutton value:
//     buttonState = digitalRead(buttonPin);
//
//     //  Button is being pressed and it's OK to change colors:
//     if (buttonState == HIGH) 
//  {
//        if(okToChangeColors)
//        {
//          okToChangeColors = false;
//      
           //  Shift to another color flame:
                if(currentColorIndex < (NUMBER_OF_COLORS - 1))
                  { 
                     currentColorIndex++;  
                  } else 
                  
                  {
                   currentColorIndex = 0;
                   }
//         if (digitalRead(sw) == HIGH) return;
  
//  else 
//  {
//    okToChangeColors = true;
//  }

  //  Flicker, based on our initial RGB values
  for(int i=0; i<strip.numPixels(); i++) {
    int flicker = random(0,55);
    int r1 = currentColor.r-flicker;
    int g1 = currentColor.g-flicker;
    int b1 = currentColor.b-flicker;
    if(g1<0) g1=0;
    if(r1<0) r1=0;
    if(b1<0) b1=0;
    strip.setPixelColor(i,r1,g1, b1);
  }
  strip.show();

  //  Adjust the delay here, if you'd like.  Right now, it randomizes the 
  //  color switch delay to give a sense of realism
  delay(random(10,113));
}


///////////////////////////////////////////////////////////////////////////////////////                  tardis                     /////////////////////////////////////////

void tardis(uint8_t sw) {
  rgbFadeInAndOut(0, 0, 255, ledFadeTime,sw); // Blue
    if (digitalRead(sw) == HIGH) return;
}

void rgbFadeInAndOut(uint8_t red, uint8_t green, uint8_t blue, uint8_t wait, uint8_t sw) {
  for(uint8_t b = 0; b <255; b++) {
     for(uint8_t i=0; i < strip.numPixels(); i++) {
        strip.setPixelColor(i, red * b/255, green * b/255, blue * b/255);
     }    if (digitalRead(sw) == HIGH) return;


     strip.show();
     delay(wait);
  };

  for(uint8_t b=255; b > 0; b--) {
     for(uint8_t i = 0; i < strip.numPixels(); i++) {
        strip.setPixelColor(i, red * b/255, green * b/255, blue * b/255);
     }
     
     strip.show();
     delay(wait);
  };
};

///////////////////////////////////////////////////////////////////////////////////                          scanner                 //////////////////////////////////////////////

//#include <Adafruit_NeoPixel.h>
//
//#define N_LEDS 8
//#define PIN     A1
//
//Adafruit_NeoPixel strip = Adafruit_NeoPixel(N_LEDS, PIN, NEO_GRB + NEO_KHZ800);
//
//void setup() {
//  strip.begin();
//}

int pos = 0, dir = 1; // Position, direction of "eye"

void scanner(uint8_t sw) 
{
  int j;
//inT pos = 0, dir = 1; // Position, direction of "eye"

  // Draw 5 pixels centered on pos.  setPixelColor() will clip any
  // pixels off the ends of the strip, we don't need to watch for that.
  strip.setPixelColor(pos - 2, 0x100000); // Dark red
  strip.setPixelColor(pos - 1, 0x800000); // Medium red
  strip.setPixelColor(pos    , 0xFF3000); // Center pixel is brightest
  strip.setPixelColor(pos + 1, 0x800000); // Medium red
  strip.setPixelColor(pos + 2, 0x100000); // Dark red

  strip.show();
  delay(100);  //This slows the travel down

  // Rather than being sneaky and erasing just the tail pixel,
  // it's easier to erase it all and draw a new one next time.
  for(j=-2; j<= 2; j++) strip.setPixelColor(pos+j, 0);

  // Bounce off ends of strip
  pos += dir;
  if(pos < 0) {
    pos = 1;
    dir = -dir;
  } else if(pos >= strip.numPixels()) {
    pos = strip.numPixels() - 2;
    dir = -dir;
    if (digitalRead (sw) == HIGH) return;
    
  }
}

////////////////////////////////////////////////////////////////////////  very important colour wheel referance leave alone! //////////////////////////////////////

    
    // Input a value 0 to 255 to get a color value.
    // The colours are a transition r - g - b - back to r.
  
    uint32_t Wheel(byte WheelPos) 
  {
      WheelPos = 255 - WheelPos;
      if(WheelPos < 85) 
    {
      return strip.Color(255 - WheelPos * 3, 0, WheelPos * 3);
    }
      if(WheelPos < 170) 
    {
      WheelPos -= 85;
      return strip.Color(0, WheelPos * 3, 255 - WheelPos * 3);
    }
      WheelPos -= 170;
      return strip.Color(WheelPos * 3, 255 - WheelPos * 3, 0);
    }



