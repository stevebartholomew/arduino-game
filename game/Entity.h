#ifndef Entity_h
#define Entity_h

#include "Arduino.h"

class Entity
{
  public:
    Entity(int startX, int startY, int _width, int _height, int hBound, int vBound);
    void left();
    void right();
    void up();
    void down();
    void update();
    int x;
    int y;
    int width;
    int height;
  private:
    int _currentX;
    int _currentY;
    int _hBound;
    int _vBound;
    int _nextX;
    int _nextY;
};

#endif
