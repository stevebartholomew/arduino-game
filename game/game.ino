#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include "Entity.h"

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 32

#define LEFT 3
#define RIGHT 2
#define DOWN 4
#define UP 5

#define OLED_RESET 4 
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

Entity player(20, 20, 10, 5, SCREEN_WIDTH, SCREEN_HEIGHT);
Entity enemy(10, 10, 2, 1, SCREEN_WIDTH, SCREEN_HEIGHT);
  
Entity* entities[2] = {
  &player,
  &enemy
};

void setup() {
  Serial.begin(9600);

  if(!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) {
    Serial.println(F("SSD1306 allocation failed"));
    for(;;);
  }

  display.clearDisplay();
  display.display();

  pinMode(LEFT, INPUT);
  pinMode(RIGHT, INPUT);
  pinMode(UP, INPUT);
  pinMode(DOWN, INPUT);
}

void loop() {
  readControls();
  draw();
}

void draw() {
  display.clearDisplay();
  drawEntities();
  display.display();
}

void drawEntities() {
  for(int i=0; i<2; i++) {
    Entity entity = *entities[i];
  
    display.fillRect(entity.x, entity.y, entity.width, entity.height, SSD1306_WHITE);
  }
}

void readControls() {  
  if(digitalRead(LEFT) == HIGH) {
    player.left();
  }
  else if(digitalRead(RIGHT) == HIGH) {
    player.right();
  }

  if(digitalRead(UP) == HIGH) {
    player.up();
  }
  else if(digitalRead(DOWN) == HIGH) {
    player.down();
  }

  player.update();
}
