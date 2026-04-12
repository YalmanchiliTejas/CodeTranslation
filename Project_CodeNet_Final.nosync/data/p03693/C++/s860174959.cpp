#include <iostream>
#include <vector>
#include <cmath>

#define REP(i, n) for(int i = 0; i < (n); ++i)

int main () {
  int r, g, b;
  std::cin >> r >> g >> b;
  int n = r * 100 + g * 10 + b;
  std::cout << (n & 1 || n >> 1 & 1 ? "NO" : "YES") << std::endl;
  return 0;
}