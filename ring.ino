#include <FastLED.h>
#define NUM_LEDS 11
#define DATA_PIN 2
CRGB leds[NUM_LEDS];

void setup() {
  FastLED.addLeds<NEOPIXEL, DATA_PIN>(leds, NUM_LEDS);
}

float i = 0.0;
float _step = 0.02;
float n = float(NUM_LEDS);
void loop() {



  i = i + _step;
  i = fmod(i, n);

  for (int j = 0; j < NUM_LEDS; j++) {

    float a = n - i + j;
    float b = abs(i - j);
    float c = fmod(abs(i - j + n), n);
    float d = min(a, min(b, c));
    float v = 1 - d / n * 2;

    v = v * v * v * v;
    


    CRGB color = CRGB::Blue;
    color.nscale8(255 * v);
    leds[j] = color; //  % (255 * v);
    // leds[j].fadeLightBy(255 * v);
    // leds[j] = CHSV(color, 255, 255 * v);
  }
  
  FastLED.show();
  delay(10);
}
