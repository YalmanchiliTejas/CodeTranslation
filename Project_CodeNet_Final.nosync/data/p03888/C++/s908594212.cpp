#include <iostream>
#include <cstdio>


int main(void){
  int r1, r2;
  std::cin >> r1 >> r2;

  double r3 = 1.0/r1 + 1.0/r2;
  r3 = 1.0/r3;

  std::printf("%.10f\n", r3);
  return 0;
}