//
// Created by Yusuf Pisan on 12/6/18.
//

#include "circle.h"

// always use initialization lists when possible
Circle::Circle(double radius) : radius{radius} {
}

// Circle::radius refers to the class variable
// could also use this->radius
// or have a different variable name for the parameter
void Circle::setRadius(double radius) {
  Circle::radius = radius;
}

double Circle::getArea() const {
  return radius * radius * 3.14159;
}
