
#include <cstdio>
#include <iostream>
#include <algorithm>
#define REP(i, n) for(int i = 0; i < (int)(n); ++i)
using namespace std;

int main(void) {
  int r, g, b;
  cin >> r >> g >> b;
  int v = r*100 + g*10 + b;
  puts(v%4 == 0 ? "YES" : "NO");
  return 0;
}
