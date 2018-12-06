/**
 * Practice Final Questions for CSS 132
 * @author Yusuf Pisan
 * @date 6 Dec 2018
 */

#include <iostream>
#include <cassert>
#include "circle.h"

using namespace std;

/**
 * Write a function called zip that accepts four parameters: an integer array,
 * the length of the array, a second integer array, the length of the
 * second array. zip prints out the array elements in alternating order.
 * If one array is shorter than the other, after all the elements are
 * alternated, the remaining elements of the longer array are printed.
 */
void zip1(const int arrA[], int lengthA, const int arrB[], int lengthB) {
  int smaller = lengthA > lengthB ? lengthB : lengthA;
  for (int i = 0; i < smaller; ++i)
    cout << arrA[i] << ", " << arrB[i] << ", ";
  for (int i = smaller; i < lengthA; ++i)
    cout << arrA[i] << ", ";
  for (int i = smaller; i < lengthB; ++i)
    cout << arrB[i] << ", ";
  cout << endl;
}

// not as good a solution since the if inside the loop
// has to check each time and the loop goes on much more than it has to
// could set the loop ending condition to
// max(lengthA, lengthB) for slight improvement
void zip2(const int arrA[], int lengthA, const int arrB[], int lengthB) {
  for (int i = 0; i < lengthA + lengthB; ++i) {
    if (i < lengthA)
      cout << arrA[i] << ", ";
    if (i < lengthB)
      cout << arrB[i] << ", ";
  }
  cout << endl;
}

// not as good a solution since the samew code is replicated
void zip3(const int arrA[], int lengthA, const int arrB[], int lengthB) {
  if (lengthA > lengthB) {
    for (int i = 0; i < lengthB; ++i)
      cout << arrA[i] << ", " << arrB[i] << ", ";
    for (int i = lengthB; i < lengthA; ++i)
      cout << arrA[i] << ", ";
  } else {
    for (int i = 0; i < lengthA; ++i)
      cout << arrA[i] << ", " << arrB[i] << ", ";
    for (int i = lengthA; i < lengthB; ++i)
      cout << arrB[i] << ", ";
  }
  cout << endl;
}

void testZip() {
  int a1[] = {1, 2, 3, 4};
  int a2[] = {10, 20, 30, 40};
  zip1(a1, 4, a2, 4);            // prints 1 10 2 20 3 30 4 40
  zip2(a1, 4, a2, 4);
  zip3(a1, 4, a2, 4);

  int b1[] = {1, 2};
  int b2[] = {10, 20, 30, 40};
  zip1(b1, 2, b2, 4);            // prints 1 10 2 20 30 40
  zip2(b1, 2, b2, 4);
  zip2(b1, 2, b2, 4);

  int c1[] = {1, 2, 3, 4};
  int c2[] = {10};
  zip1(c1, 4, c2, 1);            // prints 1 10 2 3 4
  zip2(c1, 4, c2, 1);
  zip3(c1, 4, c2, 1);
}


/**
 * Define a class called Circle which has only one variable,
 * radius (type double)
 * Write the constructor, setRadius and getArea functions and
 * test these functions in testCircle.
 * do not use == for testing double numbers
 */
void testCircle() {
  Circle c(10);
  cout << "Area for a circle of 10 is " << c.getArea() << endl;
  c.setRadius(100);
  cout << "Area for a circle of 100 is " << c.getArea() << endl;
}

/**
 * Write a function called squareWithObject that takes three parameters:
 * size of the square, x-location and y-location of the object.
 * The object is represented with '@'.
 * Assume the object location is valid (i.e location is always
 * between (1,1) and (size-2, size-2))
 */
void drawStars(int n) {
  for (int i = 0; i < n; ++i)
    cout << "*";
}

void drawBlanks(int n) {
  for (int i = 0; i < n; ++i)
    cout << " ";
}

void squareWithObject(int size, int x, int y) {
  // top
  drawStars(size);
  cout << endl;
  for (int row = 1; row < size - 1; ++row) {
    drawStars(1);
    if (row == y) {
      int before = x - 1;
      drawBlanks(before);
      cout << "@";
      // -2 for walls, -1 for object, -before for spaces already printed
      drawBlanks(size - 2 - before - 1);
    } else {
      drawBlanks(size - 2);
    }
    drawStars(1);
    cout << endl;
  }
  // bottom
  drawStars(size);
  cout << endl;
}

void testSquareWithObject() {
  squareWithObject(5, 1, 1);
  squareWithObject(5, 3, 1);
  squareWithObject(5, 3, 3);
}

/**
 * Write a function called middle that takes a string and
 * prints the middle letter. If the given string has even length,
 * the two middle characters are printed.
 */
void middle(const string &msg) {
  int mid = msg.length() / 2;
  if (msg.length() % 2 == 0)
    cout << msg[mid - 1];
  cout << msg[mid];
  cout << endl;
}

void testMiddle() {
  string s = "bye";
  cout << s << ": ";
  middle(s);

  s = "love";
  cout << s << ": ";
  middle(s);

  s = "abcdefghi";
  cout << s << ": ";
  middle(s);

  s = "abcdefghij";
  cout << s << ": ";
  middle(s);
}

/**
 * Write a function called search that accepts four parameters:
 * an integer array, the length of the array, and two integers representing
 * minimum and maximum values. search returns the index of the first
 * element in the array between the minimum and maximum values provided
 * (exclusive for both minimum and maximum).
 * If there is no element that satisfies the criteria, search returns -1.
 */
int search(const int arr[], int length, int min, int max) {
  for (int i = 0; i < length; ++i) {
    if (arr[i] > min && arr[i] < max)
      return i;
  }
  return -1;
}

void testSearch() {
  int a1[] = {10, 20, 30, 40};
  int alength = 4;
  assert(search(a1, alength, 21, 35) == 2);
  assert(search(a1, alength, 21, 30) == -1);
  assert(search(a1, alength, -10, 100) == 0);
  assert(search(a1, alength, 30, 100) == 3);

}

/**
 * Write a function to return the total number of vowels
 * (letters 'a', 'e', 'i', 'o', 'u') in a given string using the
 * following function header. You can assume that the input
 * is all lowercase characters.
 */
int countVowels(const string &msg) {
  int count = 0;
  for (int i = 0; i < msg.length(); ++i) {
    switch (msg[i]) {
      case 'a':
      case 'e':
      case 'i':
      case 'o':
      case 'u':++count;
        break;
      default:
        // do nothing, but if we have a default case
        // it cannot be empty, so a single ; or break; to make compiler happy
        break;
    }
  }
  return count;
}

void testVowels() {
  string s = "bye";
  assert(countVowels(s) == 1);
  s = "love";
  assert(countVowels(s) == 2);
  s = "zppt";
  assert(countVowels(s) == 0);
}

/**
 * Write a function called multiply that accepts three parameters:
 * an integer array, the length of the array and a number.
 * The array is modified by multiplying each element in the array
 * by the given number. multiply does not print anything to the screen.
 */

void multiply(int arr[], int length, int x) {
  for (int i = 0; i < length; ++i)
    arr[i] *= x;
}

void testMultiply() {
  int a1[] = {10, 20, 30, 40};
  int alength = 4;
  multiply(a1, alength, 10);
  for (int i = 0; i < alength; ++i)
    cout << a1[i] << " ";
  cout << endl;
}

/**
 * Write the function to convert miles to kilometers using the following
 * function headers and test them both in testMiles function.
 * a)	void miles2km1(double miles, double * km)
 * b)	void miles2km2(double miles, double &km)
 */
void miles2km1(double miles, double * km) {
  *km = miles * 1.6;
}

void miles2km2(double miles, double &km) {
  km = miles * 1.6;
}

void testMiles2km() {
  double m = 10;
  double k;
  miles2km1(m, &k);
  cout << m << " miles is " << k << endl;
  m = 20;
  miles2km2(m, k);
  cout << m << " miles is " << k << endl;
}

/**
 * Write the function int search(int arr[], int length, int target)
 * that takes an array and returns the index for the target.
 * If the target is not found, returns -1.
 */
int searchSimple(const int arr[], int length, int target) {
  for (int i = 0; i < length; ++i) {
    if (arr[i] == target)
      return i;
  }
  return -1;
}

void testSearchSimple() {
  int a1[] = {10, 20, 30, 40};
  int alength = 4;
  assert(searchSimple(a1, alength, 30) == 2);
  assert(searchSimple(a1, alength, 31) == -1);
}

/**
 * Write the function
 * int binSearch(int arr[], int length, int target)
 * that takes a sorted array and returns the index for the target
 * using binary search. If the target is not found, returns -1.
 * Depending on how you structure your code,
 * you may want to write helper functions.
 */

int binSearch(int arr[], int length, int target) {
  cout << "*** Starting binSearch, looking for " << target << endl;
  int low = 0;
  int high = length;
  while (high >= low) {
    int mid = low + (high - low) / 2;
    cout << "Looking at range " << low << "-" << high;
    cout << " with midIndex " << mid << " and midValue " << arr[mid] << endl;
    if (arr[mid] == target) {
      return mid;
    } else if (arr[mid] > target) {
      high = mid - 1;
    } else {
      low = mid + 1;
    }
  }
  return -1;
}

void testBinSearch() {
  int a1[] = {10, 20, 30, 40, 50, 60, 70, 80, 90};
  int alength = 9;
  assert(binSearch(a1, alength, 50) == 4);
  assert(binSearch(a1, alength, 10) == 0);
  assert(binSearch(a1, alength, 90) == 8);
  assert(binSearch(a1, alength, 1000) == -1);
  assert(binSearch(a1, alength, -1000) == -1);
}


int main() {
  testZip();
  testCircle();
  testSquareWithObject();
  testMiddle();
  testSearch();
  testVowels();
  testMultiply();
  testMiles2km();
  testSearchSimple();
  testBinSearch();
  return 0;
}


/*
 * Output

1, 10, 2, 20, 3, 30, 4, 40,
1, 10, 2, 20, 3, 30, 4, 40,
1, 10, 2, 20, 3, 30, 4, 40,
1, 10, 2, 20, 30, 40,
1, 10, 2, 20, 30, 40,
1, 10, 2, 20, 30, 40,
1, 10, 2, 3, 4,
1, 10, 2, 3, 4,
1, 10, 2, 3, 4,
Area for a circle of 10 is 314.159
Area for a circle of 100 is 31415.9
*****
*@  *
*   *
*   *
*****
*****
*  @*
*   *
*   *
*****
*****
*   *
*   *
*  @*
*****
bye: y
love: ov
abcdefghi: e
abcdefghij: ef
100 200 300 400
10 miles is 16
20 miles is 32
*** Starting binSearch, looking for 50
Looking at range 0-9 with midIndex 4 and midValue 50
*** Starting binSearch, looking for 10
Looking at range 0-9 with midIndex 4 and midValue 50
Looking at range 0-3 with midIndex 1 and midValue 20
Looking at range 0-0 with midIndex 0 and midValue 10
*** Starting binSearch, looking for 90
Looking at range 0-9 with midIndex 4 and midValue 50
Looking at range 5-9 with midIndex 7 and midValue 80
Looking at range 8-9 with midIndex 8 and midValue 90
*** Starting binSearch, looking for 1000
Looking at range 0-9 with midIndex 4 and midValue 50
Looking at range 5-9 with midIndex 7 and midValue 80
Looking at range 8-9 with midIndex 8 and midValue 90
Looking at range 9-9 with midIndex 9 and midValue 1
*** Starting binSearch, looking for -1000
Looking at range 0-9 with midIndex 4 and midValue 50
Looking at range 0-3 with midIndex 1 and midValue 20
Looking at range 0-0 with midIndex 0 and midValue 10

Process finished with exit code 0

 */