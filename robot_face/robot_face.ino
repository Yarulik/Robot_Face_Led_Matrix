/*
 * This example shows how to display bitmaps that are exported from GIMP and
 * compiled into the sketch and stored in the Teensy's Flash memory
 * See more details here:
 * http://docs.pixelmatix.com/SmartMatrix/library.html#smartmatrix-library-how-to-use-the-library-drawing-raw-bitmaps
 *
 * This example uses only the SmartMatrix Background layer
 */


#include <SmartMatrix3.h>
#include "gimpbitmap.h"
//указываем изображения 32х32 пикселя, в папке со скетчем, в формате .c
#include "bender.c"
#include "bender1.c"
#include "cartman.c"
#include "cry.c"
#include "happy.c"
#include "unhappy.c"
#include "marsh.c"
#include "sad.c"
#include "ops.c"
#include "love.c"
#include "top.c"
#include "down.c"
#include "left.c"
#include "right.c"

#define COLOR_DEPTH 24                  // known working: 24, 48 - If the sketch uses type `rgb24` directly, COLOR_DEPTH must be 24
const uint8_t kMatrixWidth = 32;        // known working: 16, 32, 48, 64
const uint8_t kMatrixHeight = 32;       // known working: 32, 64, 96, 128
const uint8_t kRefreshDepth = 36;       // known working: 24, 36, 48
const uint8_t kDmaBufferRows = 4;       // known working: 2-4, use 2 to save memory, more to keep from dropping frames and automatically lowering refresh rate
const uint8_t kPanelType = SMARTMATRIX_HUB75_16ROW_MOD8SCAN; // SMARTMATRIX_HUB75_16ROW_MOD8SCAN for common 16x32 panels, or use SMARTMATRIX_HUB75_64ROW_MOD32SCAN for common 64x64 panels
const uint8_t kMatrixOptions = (SMARTMATRIX_OPTIONS_NONE);
const uint8_t kBackgroundLayerOptions = (SM_BACKGROUND_OPTIONS_NONE);

SMARTMATRIX_ALLOCATE_BUFFERS(matrix, kMatrixWidth, kMatrixHeight, kRefreshDepth, kDmaBufferRows, kPanelType, kMatrixOptions);
SMARTMATRIX_ALLOCATE_BACKGROUND_LAYER(backgroundLayer, kMatrixWidth, kMatrixHeight, COLOR_DEPTH, kBackgroundLayerOptions);

int led = 13;

void drawBitmap(int16_t x, int16_t y, const gimp32x32bitmap* bitmap) {
  for(unsigned int i=0; i < bitmap->height; i++) {
    for(unsigned int j=0; j < bitmap->width; j++) {
      SM_RGB pixel = { bitmap->pixel_data[(i*bitmap->width + j)*3 + 0],
                      bitmap->pixel_data[(i*bitmap->width + j)*3 + 1],
                      bitmap->pixel_data[(i*bitmap->width + j)*3 + 2] };

      backgroundLayer.drawPixel(x + j, y + i, pixel);
    }
  }
}

void setup() {
  matrix.addLayer(&backgroundLayer);
  matrix.begin();

  matrix.setBrightness(20); //Яркость LED панели

  pinMode(led, OUTPUT);
}

void loop() {
  int x, y;




  backgroundLayer.fillScreen({0,0,0});
  x = (kMatrixWidth / 2) - (bender.width/2);
  y = (kMatrixHeight / 2) - (bender.height/2);
  // can pass &colorwheel in directly as the bitmap source is already gimp32x32bitmap
  drawBitmap(x, y, (const gimp32x32bitmap*)&bender);
  backgroundLayer.swapBuffers();

  digitalWrite(led, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(1000);
  digitalWrite(led, LOW);    // turn the LED off by making the voltage LOW
  delay(1000);

  backgroundLayer.fillScreen({0,0,0});
  x = (kMatrixWidth / 2) - (cartman.width/2);
  y = (kMatrixHeight / 2) - (cartman.height/2);
  drawBitmap(x, y, (const gimp32x32bitmap*)&cartman);
  backgroundLayer.swapBuffers();

  digitalWrite(led, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(1000);
  digitalWrite(led, LOW);    // turn the LED off by making the voltage LOW
  delay(1000);

  backgroundLayer.fillScreen({0,0,0});
  x = (kMatrixWidth / 2) - (bender1.width/2);
  y = (kMatrixHeight / 2) - (bender1.height/2);
  drawBitmap(x, y, (const gimp32x32bitmap*)&bender1);
  backgroundLayer.swapBuffers();

  digitalWrite(led, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(1000);
  digitalWrite(led, LOW);    // turn the LED off by making the voltage LOW
  delay(1000);

  backgroundLayer.fillScreen({0,0,0});
  x = (kMatrixWidth / 2) - (marsh.width/2);
  y = (kMatrixHeight / 2) - (marsh.height/2);
  drawBitmap(x, y, (const gimp32x32bitmap*)&marsh);
  backgroundLayer.swapBuffers();

  digitalWrite(led, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(1000);
  digitalWrite(led, LOW);    // turn the LED off by making the voltage LOW
  delay(1000);

  backgroundLayer.fillScreen({0,0,0});
  x = (kMatrixWidth / 2) - (love.width/2);
  y = (kMatrixHeight / 2) - (love.height/2);
  drawBitmap(x, y, (const gimp32x32bitmap*)&love);
  backgroundLayer.swapBuffers();

  digitalWrite(led, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(1000);
  digitalWrite(led, LOW);    // turn the LED off by making the voltage LOW
  delay(1000);
  
  backgroundLayer.fillScreen({0,0,0});
  x = (kMatrixWidth / 2) - (happy.width/2);
  y = (kMatrixHeight / 2) - (happy.height/2);
  drawBitmap(x, y, (const gimp32x32bitmap*)&happy);
  backgroundLayer.swapBuffers();

  digitalWrite(led, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(1000);
  digitalWrite(led, LOW);    // turn the LED off by making the voltage LOW
  delay(1000);

  backgroundLayer.fillScreen({0,0,0});
  x = (kMatrixWidth / 2) - (unhappy.width/2);
  y = (kMatrixHeight / 2) - (unhappy.height/2);
  drawBitmap(x, y, (const gimp32x32bitmap*)&unhappy);
  backgroundLayer.swapBuffers();

  digitalWrite(led, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(1000);
  digitalWrite(led, LOW);    // turn the LED off by making the voltage LOW
  delay(1000);

    backgroundLayer.fillScreen({0,0,0});
  x = (kMatrixWidth / 2) - (sad.width/2);
  y = (kMatrixHeight / 2) - (sad.height/2);
  drawBitmap(x, y, (const gimp32x32bitmap*)&sad);
  backgroundLayer.swapBuffers();

  digitalWrite(led, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(1000);
  digitalWrite(led, LOW);    // turn the LED off by making the voltage LOW
  delay(1000);
  
}
