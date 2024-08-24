#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <Adafruit_NeoPixel.h>

#define RGB 8
Adafruit_NeoPixel strip(8, RGB, NEO_GRB + NEO_KHZ800);

#define SCREEN_WIDTH 128  // OLED 寬度像素
#define SCREEN_HEIGHT 64  // OLED 高度像素
#define OLED_RESET -1     // Reset pin # (or -1 if sharing Arduino reset pin)
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

const int buttonUp = A3;     // 向上按鈕引腳
const int buttonDown = A2;   // 向下按鈕引腳
const int buttonEnter = A1;  // 確認按鈕引腳
const int buttonReturn = A0;


int page = 1, t = 6, w = 18, R = 0, G = 0, B = 0;


unsigned long startMillis = 0;
const long introDisplayDuration = 2000;
bool introDisplayDone = false;


unsigned long previousMillis2 = 0;
const long interval3 = 10;  // 延遲時間（毫秒）
int brightness = 0;
int brightnessChange = 1;  // 控制亮度增加或減少



const long YRDuration = 1000;  // 黃燈持續時間（2秒）
const long GRDuration = 3000;  // 綠燈持續時間（3秒）

unsigned long previousMillis = 0;  // 上一次變更時間
int state = 0;


const int numPixels = 15;    // 確保這個數字與你的 LED 條數量相符
const long interval2 = 133;  // 延遲時間

int position = 0;
bool forward = true;



void setup() {
  Serial.begin(9600);

  pinMode(buttonUp, INPUT);     // 設定向上按鈕引腳為輸入
  pinMode(buttonEnter, INPUT);  // 設定確認按鈕引腳為輸入
  pinMode(buttonDown, INPUT);   // 設定向下按鈕引腳為輸入

  strip.begin();
  strip.show();

  // 偵測是否安裝好OLED了
  if (!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) {  // 一般1306 OLED的位址都是0x3C
    Serial.println(F("SSD1306 allocation failed"));
    for (;;)
      ;  // Don't proceed, loop forever
  }
  display.clearDisplay();     // 清除顯示畫面
  display.setTextSize(2);     // 設定文字大小
  display.setTextColor(1);    // 設定文字顏色（1 表示預設顏色）
  display.setCursor(41, 10);  // 設定文字起始座標
  display.print("HCVS");      // 顯示字串 "NKHS"
  display.setCursor(48, 40);  // 設定文字起始座標
  display.print("A01");       // 顯示字串 "C201"
  display.display();          // 更新顯示內容
}
int Down = false;
bool BlueBreath = false;
bool Rainbow = false;
bool RYG = false;

void loop() {
  unsigned long starttime = millis();
  unsigned long currentMillis = millis();
  unsigned long interval;

  if (starttime - startMillis >= introDisplayDuration && !introDisplayDone) {
    int buttonUpState = digitalRead(buttonUp);        // 讀取向上按鈕狀態
    int buttonEnterState = digitalRead(buttonEnter);  // 讀取確認按鈕狀態
    int buttonDownState = digitalRead(buttonDown);    // 讀取向下按鈕狀態
    int buttonReturnState = digitalRead(buttonReturn);

    switch (page) {
      case 1:
        display.clearDisplay();
        display.setTextSize(1);     // 設定文字大小
        display.setTextColor(1);    // 1:OLED預設的顏色(這個會依該OLED的顏色來決定)
        display.setCursor(0, 1);    // 設定起始座標
        display.print("HCVS A01");  // 要顯示的字串
        display.fillRect(0, 9, 128, 1, 1);
        display.setTextSize(2);             // 設定文字小大
        display.setCursor(64 - t * 5, 30);  // 設定起始座標
        display.print("Mulit");             // 要顯示的字串
        display.setCursor(64 - t * 7, 48);  // 設定起始座標
        display.print("Dynamic");           // 要顯示的字串
        display.fillRect(0, 10 + w * 0, 128, 18, 1);
        display.setTextColor(0);
        display.setCursor(64 - t * 4, 12);  // 設定起始座標
        display.print("Mono");              // 要顯示的字串
        display.display();                  // 要有這行才會把文字顯示出來
        if (buttonDownState == LOW)
          page = 2;
        if (buttonEnterState == LOW)
          page = 10;
        break;
      case 2:
        display.clearDisplay();
        display.setTextSize(1);     // 設定文字大小
        display.setTextColor(1);    // 1:OLED預設的顏色(這個會依該OLED的顏色來決定)
        display.setCursor(0, 1);    // 設定起始座標
        display.print("HCVS A01");  // 要顯示的字串
        display.fillRect(0, 9, 128, 1, 1);
        display.setTextSize(2);             // 設定文字小大
        display.setCursor(64 - t * 4, 12);  // 設定起始座標
        display.print("Mono");              // 要顯示的字串
        display.setCursor(64 - t * 7, 48);  // 設定起始座標
        display.print("Dynamic");           // 要顯示的字串
        display.fillRect(0, 10 + w * 1, 128, 18, 1);
        display.setTextColor(0);
        display.setCursor(64 - t * 5, 30);  // 設定起始座標
        display.print("Mulit");             // 要顯示的字串
        display.display();                  // 要有這行才會把文字顯示出來
        if (buttonUpState == LOW)
          page = 1;
        if (buttonDownState == LOW)
          page = 3;
        if (buttonEnterState == LOW)
          page = 20;
        break;
      case 3:
        display.clearDisplay();
        display.setTextSize(1);     // 設定文字大小
        display.setTextColor(1);    // 1:OLED預設的顏色(這個會依該OLED的顏色來決定)
        display.setCursor(0, 1);    // 設定起始座標
        display.print("HCVS A01");  // 要顯示的字串
        display.fillRect(0, 9, 128, 1, 1);
        display.setTextSize(2);             // 設定文字小大
        display.setCursor(64 - t * 4, 12);  // 設定起始座標
        display.print("Mono");              // 要顯示的字串
        display.setCursor(64 - t * 5, 30);  // 設定起始座標
        display.print("Mulit");             // 要顯示的字串
        display.fillRect(0, 10 + w * 2, 128, 18, 1);
        display.setTextColor(0);
        display.setCursor(64 - t * 7, 48);  // 設定起始座標
        display.print("Dynamic");           // 要顯示的字串
        display.display();                  // 要有這行才會把文字顯示出來
        if (buttonUpState == LOW)
          page = 2;
        if (buttonDownState == LOW)
          page = 4;
        if (buttonEnterState == LOW)
          page = 30;
        break;
      case 4:
        display.clearDisplay();
        display.setTextSize(1);     // 設定文字大小
        display.setTextColor(1);    // 1:OLED預設的顏色(這個會依該OLED的顏色來決定)
        display.setCursor(0, 1);    // 設定起始座標
        display.print("HCVS A01");  // 要顯示的字串
        display.fillRect(0, 9, 128, 1, 1);
        display.setTextSize(2);             // 設定文字小大
        display.setCursor(64 - t * 5, 12);  // 設定起始座標
        display.print("Mulit");             // 要顯示的字串
        display.setCursor(64 - t * 7, 30);  // 設定起始座標
        display.print("Dynamic");           // 要顯示的字串
        display.fillRect(0, 10 + w * 2, 128, 18, 1);
        display.setTextColor(0);
        display.setCursor(64 - t * 6, 48);  // 設定起始座標
        display.print("Custom");            // 要顯示的字串
        display.display();                  // 要有這行才會把文字顯示出來
        if (buttonUpState == LOW)
          page = 6;
        //if (buttonEnterState == LOW)
        //page = 40;
        break;
      case 5:
        display.clearDisplay();
        display.setTextSize(1);     // 設定文字大小
        display.setTextColor(1);    // 1:OLED預設的顏色(這個會依該OLED的顏色來決定)
        display.setCursor(0, 1);    // 設定起始座標
        display.print("HCVS A01");  // 要顯示的字串
        display.fillRect(0, 9, 128, 1, 1);
        display.setTextSize(2);             // 設定文字小大
        display.setCursor(64 - t * 7, 30);  // 設定起始座標
        display.print("Dynamic");           // 要顯示的字串
        display.setCursor(64 - t * 6, 48);  // 設定起始座標
        display.print("Custom");            // 要顯示的字串
        display.fillRect(0, 10 + w * 0, 128, 18, 1);
        display.setTextColor(0);
        display.setCursor(64 - t * 5, 12);  // 設定起始座標
        display.print("Mulit");             // 要顯示的字串
        display.display();                  // 要有這行才會把文字顯示出來
        if (buttonUpState == LOW)
          page = 1;
        if (buttonDownState == LOW)
          page = 6;
        if (buttonEnterState == LOW)
          page = 20;
        break;
      case 6:
        display.clearDisplay();
        display.setTextSize(1);     // 設定文字大小
        display.setTextColor(1);    // 1:OLED預設的顏色(這個會依該OLED的顏色來決定)
        display.setCursor(0, 1);    // 設定起始座標
        display.print("HCVS A01");  // 要顯示的字串
        display.fillRect(0, 9, 128, 1, 1);
        display.setTextSize(2);             // 設定文字小大
        display.setCursor(64 - t * 5, 12);  // 設定起始座標
        display.print("Mulit");             // 要顯示的字串
        display.setCursor(64 - t * 6, 48);  // 設定起始座標
        display.print("Custom");            // 要顯示的字串
        display.fillRect(0, 10 + w * 1, 128, 18, 1);
        display.setTextColor(0);
        display.setCursor(64 - t * 7, 30);  // 設定起始座標
        display.print("Dynamic");           // 要顯示的字串
        display.display();                  // 要有這行才會把文字顯示出來
        if (buttonUpState == LOW)
          page = 5;
        if (buttonDownState == LOW)
          page = 4;
        if (buttonEnterState == LOW)
          page = 30;
        break;


      case 10:
        display.clearDisplay();
        display.setTextSize(1);   // 設定文字大小
        display.setTextColor(1);  // 1:OLED預設的顏色(這個會依該OLED的顏色來決定)
        display.setCursor(0, 1);  // 設定起始座標
        display.print("< Mono");  // 要顯示的字串
        display.fillRect(0, 9, 128, 1, 1);
        display.setTextSize(2);              // 設定文字小大
        display.setCursor(64 - t * 10, 30);  // 設定起始座標
        display.print("1357R2468G");         // 要顯示的字串
        display.setCursor(64 - t * 10, 48);  // 設定起始座標
        display.print("BlueBreath");         // 要顯示的字串
        display.fillRect(0, 10 + w * 0, 128, 18, 1);
        display.setTextColor(0);
        display.setCursor(64 - t * 5, 12);  // 設定起始座標
        display.print("White");             // 要顯示的字串
        display.display();                  // 要有這行才會把文字顯示出來
        if (buttonDownState == LOW)
          page = 11;
        if (buttonEnterState == LOW) {
          BlueBreath = false;
          Rainbow = false;
          RYG = false;

          for (int i = 0; i <= 7; i++)
            strip.setPixelColor(i, strip.Color(255, 255, 255));
          strip.show();
        }
        if (buttonReturnState == LOW)
          page = 1;
        break;
      case 11:
        display.clearDisplay();
        display.setTextSize(1);   // 設定文字大小
        display.setTextColor(1);  // 1:OLED預設的顏色(這個會依該OLED的顏色來決定)
        display.setCursor(0, 1);  // 設定起始座標
        display.print("< Mono");  // 要顯示的字串
        display.fillRect(0, 9, 128, 1, 1);
        display.setTextSize(2);              // 設定文字小大
        display.setCursor(64 - t * 5, 12);   // 設定起始座標
        display.print("White");              // 要顯示的字串
        display.setCursor(64 - t * 10, 48);  // 設定起始座標
        display.print("BlueBreath");         // 要顯示的字串
        display.fillRect(0, 10 + w * 1, 128, 18, 1);
        display.setTextColor(0);
        display.setCursor(64 - t * 10, 30);  // 設定起始座標
        display.print("1357R2468G");         // 要顯示的字串
        display.display();                   // 要有這行才會把文字顯示出來
        if (buttonUpState == LOW)
          page = 10;
        if (buttonDownState == LOW)
          page = 12;
        if (buttonEnterState == LOW) {
          BlueBreath = false;
          Rainbow = false;
          RYG = false;

          for (int i = 0; i <= 6; i += 2)
            strip.setPixelColor(i, strip.Color(255, 0, 0));
          for (int i = 1; i <= 7; i += 2)
            strip.setPixelColor(i, strip.Color(0, 255, 0));
          strip.show();
        }
        if (buttonReturnState == LOW)
          page = 1;
        break;
      case 12:
        display.clearDisplay();
        display.setTextSize(1);   // 設定文字大小
        display.setTextColor(1);  // 1:OLED預設的顏色(這個會依該OLED的顏色來決定)
        display.setCursor(0, 1);  // 設定起始座標
        display.print("< Mono");  // 要顯示的字串
        display.fillRect(0, 9, 128, 1, 1);
        display.setTextSize(2);              // 設定文字小大
        display.setCursor(64 - t * 5, 12);   // 設定起始座標
        display.print("White");              // 要顯示的字串
        display.setCursor(64 - t * 10, 30);  // 設定起始座標
        display.print("1357R2468G");         // 要顯示的字串
        display.fillRect(0, 10 + w * 2, 128, 18, 1);
        display.setTextColor(0);
        display.setCursor(64 - t * 10, 48);  // 設定起始座標
        display.print("BlueBreath");         // 要顯示的字串
        display.display();                   // 要有這行才會把文字顯示出來
        if (buttonUpState == LOW)
          page = 11;
        if (buttonEnterState == LOW) {
          Rainbow = false;
          RYG = false;
          BlueBreath = true;
        }
        if (buttonReturnState == LOW)
          page = 1;
        break;


      case 20:
        display.clearDisplay();
        display.setTextSize(1);    // 設定文字大小
        display.setTextColor(1);   // 1:OLED預設的顏色(這個會依該OLED的顏色來決定)
        display.setCursor(0, 1);   // 設定起始座標
        display.print("< Mulit");  // 要顯示的字串
        display.fillRect(0, 9, 128, 1, 1);
        display.setTextSize(2);             // 設定文字小大
        display.setCursor(64 - t * 3, 30);  // 設定起始座標
        display.print("RYG");               // 要顯示的字串
        display.fillRect(0, 10 + w * 0, 128, 18, 1);
        display.setTextColor(0);
        display.setCursor(64 - t * 7, 12);  // 設定起始座標
        display.print("Rainbow");           // 要顯示的字串
        display.display();                  // 要有這行才會把文字顯示出來
        if (buttonDownState == LOW)
          page = 21;
        if (buttonEnterState == LOW) {
          BlueBreath = false;
          Rainbow = false;
          RYG = false;

          strip.setPixelColor(0, strip.Color(255, 0, 0));
          strip.setPixelColor(1, strip.Color(255, 125, 0));
          strip.setPixelColor(2, strip.Color(255, 255, 0));
          strip.setPixelColor(3, strip.Color(0, 255, 0));
          strip.setPixelColor(4, strip.Color(0, 0, 255));
          strip.setPixelColor(5, strip.Color(0, 255, 255));
          strip.setPixelColor(6, strip.Color(255, 0, 255));
          strip.setPixelColor(7, strip.Color(0, 0, 0));
          strip.show();
        }
        if (buttonReturnState == LOW)
          page = 2;
        break;
      case 21:
        display.clearDisplay();
        display.setTextSize(1);    // 設定文字大小
        display.setTextColor(1);   // 1:OLED預設的顏色(這個會依該OLED的顏色來決定)
        display.setCursor(0, 1);   // 設定起始座標
        display.print("< Mulit");  // 要顯示的字串
        display.fillRect(0, 9, 128, 1, 1);
        display.setTextSize(2);             // 設定文字小大
        display.setCursor(64 - t * 7, 12);  // 設定起始座標
        display.print("Rainbow");           // 要顯示的字串
        display.fillRect(0, 10 + w * 1, 128, 18, 1);
        display.setTextColor(0);
        display.setCursor(64 - t * 3, 30);  // 設定起始座標
        display.print("RYG");               // 要顯示的字串
        display.display();                  // 要有這行才會把文字顯示出來
        if (buttonUpState == LOW)
          page = 20;
        if (buttonEnterState == LOW) {
          BlueBreath = false;
          Rainbow = false;
          RYG = false;

          strip.setPixelColor(0, strip.Color(255, 0, 0));
          strip.setPixelColor(1, strip.Color(255, 255, 0));
          strip.setPixelColor(2, strip.Color(0, 255, 0));
          strip.setPixelColor(3, strip.Color(0, 0, 0));
          strip.setPixelColor(4, strip.Color(0, 0, 0));
          strip.setPixelColor(5, strip.Color(255, 0, 0));
          strip.setPixelColor(6, strip.Color(255, 255, 0));
          strip.setPixelColor(7, strip.Color(0, 255, 0));
          strip.show();
        }
        if (buttonReturnState == LOW)
          page = 2;
        break;


      case 30:
        display.clearDisplay();
        display.setTextSize(1);      // 設定文字大小
        display.setTextColor(1);     // 1:OLED預設的顏色(這個會依該OLED的顏色來決定)
        display.setCursor(0, 1);     // 設定起始座標
        display.print("< Dynamic");  // 要顯示的字串
        display.fillRect(0, 9, 128, 1, 1);
        display.setTextSize(2);             // 設定文字小大
        display.setCursor(64 - t * 7, 30);  // 設定起始座標
        display.print("Rainbow");           // 要顯示的字串
        display.fillRect(0, 10 + w * 0, 128, 18, 1);
        display.setTextColor(0);
        display.setCursor(64 - t * 3, 12);  // 設定起始座標
        display.print("RYG");               // 要顯示的字串
        display.display();                  // 要有這行才會把文字顯示出來
        if (buttonDownState == LOW)
          page = 31;
        if (buttonEnterState == LOW) {
          BlueBreath = false;
          Rainbow = false;
          RYG = true;
        }
        if (buttonReturnState == LOW)
          page = 3;
        break;
      case 31:
        display.clearDisplay();
        display.setTextSize(1);      // 設定文字大小
        display.setTextColor(1);     // 1:OLED預設的顏色(這個會依該OLED的顏色來決定)
        display.setCursor(0, 1);     // 設定起始座標
        display.print("< Dynamic");  // 要顯示的字串
        display.fillRect(0, 9, 128, 1, 1);
        display.setTextSize(2);             // 設定文字小大
        display.setCursor(64 - t * 3, 12);  // 設定起始座標
        display.print("RYG");               // 要顯示的字串
        display.fillRect(0, 10 + w * 1, 128, 18, 1);
        display.setTextColor(0);
        display.setCursor(64 - t * 7, 30);  // 設定起始座標
        display.print("Rainbow");           // 要顯示的字串
        display.display();                  // 要有這行才會把文字顯示出來
        if (buttonUpState == LOW)
          page = 30;
        if (buttonEnterState == LOW) {
          BlueBreath = false;
          RYG = false;
          Rainbow = true;
        }
        if (buttonReturnState == LOW)
          page = 3;
        break;
    }
  }

  if (BlueBreath == true) {
    if (currentMillis - previousMillis2 >= interval3) {
      previousMillis = currentMillis;

      // 更新亮度
      brightness += brightnessChange;

      // 反轉亮度變化方向
      if (brightness >= 100 || brightness <= 0) {
        brightnessChange = -brightnessChange;
      }

      // 設定所有像素的顏色
      for (int i = 0; i < strip.numPixels(); i++) {
        strip.setPixelColor(i, strip.Color(0, 0, brightness));
      }
      strip.show();
    }
  }



  if (RYG == true) {
    switch (state) {
      case 0:  // 南北向綠燈
        interval = GRDuration;
        break;
      case 1:  // 南北向黃燈
        interval = YRDuration;
        break;
      case 2:  // 東西向綠燈
        interval = GRDuration;
        break;
      case 3:  // 東西向黃燈
        interval = YRDuration;
        break;
    }

    // 根據時間來變更燈的狀態
    if (currentMillis - previousMillis >= interval) {
      previousMillis = currentMillis;
      state = (state + 1) % 4;  // 共有6種狀態

      switch (state) {
        case 0:
          strip.clear();
          strip.setPixelColor(0, strip.Color(255, 0, 0));
          strip.setPixelColor(7, strip.Color(0, 255, 0));  // 東西向紅燈，南北向綠燈
          strip.show();
          break;
        case 1:
          strip.clear();
          strip.setPixelColor(0, strip.Color(255, 0, 0));
          strip.setPixelColor(6, strip.Color(255, 255, 0));  // 東西向紅燈，南北向黃燈
          strip.show();
          break;
        case 2:
          strip.clear();
          strip.setPixelColor(2, strip.Color(0, 255, 0));
          strip.setPixelColor(5, strip.Color(255, 0, 0));  // 東西向綠燈，南北向紅燈
          strip.show();
          break;
        case 3:
          strip.clear();
          strip.setPixelColor(1, strip.Color(255, 255, 0));
          strip.setPixelColor(5, strip.Color(255, 0, 0));  // 東西向黃燈，南北向紅燈
          strip.show();
          break;
      }
    }
  }


  if (Rainbow == true) {
    if (currentMillis - previousMillis >= interval2) {
      previousMillis = currentMillis;

      // 清除所有像素
      for (int i = 0; i < numPixels; i++) {
        strip.setPixelColor(i, strip.Color(0, 0, 0));
      }

      // 設定顏色
      if (Rainbow) {
        for (int i = 0; i <= 14; i++) {
          if (i == position) strip.setPixelColor(i, strip.Color(255, 0, 0));
          if (i == position - 1) strip.setPixelColor(i, strip.Color(255, 125, 0));
          if (i == position - 2) strip.setPixelColor(i, strip.Color(255, 255, 0));
          if (i == position - 3) strip.setPixelColor(i, strip.Color(0, 255, 0));
          if (i == position - 4) strip.setPixelColor(i, strip.Color(0, 0, 255));
          if (i == position - 5) strip.setPixelColor(i, strip.Color(0, 255, 255));
          if (i == position - 6) strip.setPixelColor(i, strip.Color(255, 0, 255));
        }

        // 更新顯示
        strip.show();

        // 更新位置
        if (forward) {
          position++;
          if (position > 14) {
            position = 14;
            forward = false;
          }
        } else {
          position--;
          if (position < -7) {
            position = -7;
            forward = true;
          }
        }
      }
    }
  }
}


void setAllPixels(uint32_t color) {
  for (int i = 0; i < strip.numPixels(); i++) {
    strip.setPixelColor(i, color);
  }
}
