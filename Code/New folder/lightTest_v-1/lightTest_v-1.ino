#include <Adafruit_NeoPixel.h>

Adafruit_NeoPixel strip = Adafruit_NeoPixel(9, 3, NEO_GRB + NEO_KHZ800);

void setup() {
  Serial.begin(9600);
  strip.begin();
  strip.setBrightness(25);
  for(int i = 0; i<9; i++){
    strip.setPixelColor(i, 50, 50, 50);
    delay(50);
    strip.show();
  }
  for(int i = 0; i< 9; i++){
    strip.setPixelColor(i, 0, 0, 0);
    delay(50);
    strip.show();
  }
}
int buttonArray[16][5] {
  {0, 0, 0, 0, 0},
  {151, 1, 0, 0, 0},
  {256, 0, 5, 0, 0},
  {319, 0, 0, 7, 0},
  {344, 1, 5, 0, 0},
  {394, 1, 0, 7, 0},
  {427, 0, 0, 0, 3},
  {451, 0, 5, 7, 0},
  {482, 1, 0, 0, 3},
  {501, 1, 5, 7, 0},
  {524, 0, 5, 0, 3},
  {551, 0, 0, 7, 3},
  {563, 1, 5, 0, 3},
  {586, 1, 0, 7, 3},
  {614, 0, 5, 7, 3},
  {641, 1, 5, 7, 3}
};

void loop() {
  Serial.println(analogRead(A0));
  strip.clear();
  strip.show();
  int buttonVal = analogRead(A0);
  if(buttonVal > 100){
    for(int i = 1; i< 16; i++){
      if(abs(buttonArray[i][0]-buttonVal) <= 6){
//        Serial.print("Checking between: ");
//        Serial.print(buttonArray[i-1][0]);
//        Serial.print(" and ");
//        Serial.println(buttonArray[i+1][0]);
//        Serial.print(buttonVal);
//        Serial.print(" --- ");
//        Serial.println(buttonArray[i][0]);
        for(int j = 1; j<5; j++){
          if(buttonArray[i][j] >= 1){
            strip.setPixelColor(buttonArray[i][j], 50, 50, 50);
            strip.show();
          }
        }
        strip.show();
//        delay(2000);
        break;
      }
    }
  } 
}
