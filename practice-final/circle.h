//
// Created by Yusuf Pisan on 12/6/18.
//

#ifndef PRACTICE_FINAL_CIRCLE_H
#define PRACTICE_FINAL_CIRCLE_H

class Circle {
 private:
  double radius;
 public:
  // all constructors with 1 parameter should be declared explicit
  explicit Circle(double radius);
  // return area
  double getArea() const;
  // change radius
  void setRadius(double radius);
};

#endif // PRACTICE_FINAL_CIRCLE_H
