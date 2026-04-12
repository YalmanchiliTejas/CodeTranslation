#include <iostream>
#include <cstdio>
using namespace std;

int main() {
  double r1, r2;
  cin >> r1 >> r2;
  printf("%.16lf\n", r1*r2/(r1 + r2));
  return 0;
}