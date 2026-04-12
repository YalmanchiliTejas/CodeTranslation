#include <iostream>
#include <stdio.h>
using namespace std;

int main(void) {
  int r1, r2;
  double r3;

  cin >> r1 >> r2;

  r3 = (r1 * r2) / (double)(r1 + r2);

  printf("%.10lf\n", r3);

  return 0;
}