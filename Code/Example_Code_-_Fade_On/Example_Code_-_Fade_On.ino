#define PIN 3
#include <Adafruit_NeoPixel.h>
Adafruit_NeoPixel strip = Adafruit_NeoPixel(9, PIN, NEO_GRB + NEO_KHZ800);

void setup() {
  // put your setup code here, to run once:
  strip.begin();
  strip.setBrightness(25);
}

void loop() {
  for (int j = 0; j < 9; j++) {
    strip.setPixelColor(j, 0, 0, 0);
  }
  strip.show();
  delay(1000);
  for (int i = 0; i < 150; i++) {
    for (int j = 0; j < 9; j++) {
      strip.setPixelColor(j, i, i, i);
    }
    strip.show();
    delay(5);
  }
  while (1) {
  }
}
