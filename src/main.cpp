#include <Arduino.h>
#include "FastLED/src/FastLED.h"

#define LED_PIN 7
#define NUM_LEDS 100

CRGB leds[NUM_LEDS];
int currentLED = 1;
int r = 100;
int g = 70;
int b = 80;

void setup() {
    FastLED.addLeds<WS2812, LED_PIN, RGB>(leds, NUM_LEDS);
}

void loop() {
    if (currentLED == 100) {
        currentLED = 1;
    }
    for (int i = 0; i < NUM_LEDS; i++) {
        leds[i] = CRGB(r, g, b);
        r++;
        g+=2;
        b+=2;
        if (r > 100) {
            r = 0;
        }
        if (b > 100) {
            b = 0;
        }
        if (g > 100) {
            g = 0;
        }
    }
    FastLED.show();
    delay(100);
}
