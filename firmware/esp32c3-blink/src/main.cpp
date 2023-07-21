#include <Arduino.h>
#include <Adafruit_NeoPixel.h>
#include <Ticker.h>

#define PIN_LED 8
#define LED_COUNT 1

Adafruit_NeoPixel pixels(LED_COUNT, PIN_LED, NEO_GRB + NEO_KHZ800);
Ticker tOn, tOff;


void setup()
{
  Serial.begin(SERIAL_BAUD);
  Serial.println(F("Hello,"));
  Serial.println(F("I'm"));
  Serial.println(F("ESP32-C3!"));

  tOn.attach_ms(500, [](){
    pixels.setPixelColor(0, pixels.Color(0, 150, 0));
    pixels.show();
  });
  delay(250);
  tOff.attach_ms(500, [](){
    pixels.setPixelColor(0, pixels.Color(0, 0, 0));
    pixels.show();    
  
    Serial.printf("[%ld] %#08lx\n", millis(), random());
  });
}

void loop(){}