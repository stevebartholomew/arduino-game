#include "Entity.h"

Entity::Entity(int startX, int startY, int _width, int _height, int hBound, int vBound)
{
  x = startX;
  y = startY;
  
  _nextX = x;
  _nextY = y;

  _hBound = hBound;
  _vBound = vBound;

  width = _width;
  height = _height;
}

void Entity::left()
{
    _nextX = x - 1;
}

void Entity::right()
{
    _nextX = x + 1;
}

void Entity::up()
{
   _nextY = y - 1;
}

void Entity::down()
{
    _nextY = y + 1;
}

void Entity::update() 
{
  if(_nextY != y || _nextX != x) {
    if(_nextX > 0 && _nextX < (_hBound - width)) {
      x = _nextX;  
    }

    if(_nextY > 0 && _nextY < (_vBound - height)) {
      y = _nextY;  
    }
  }
}
