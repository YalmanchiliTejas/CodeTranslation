#include <iostream>
#include <cstdio>
using namespace std;

int main() {
  int r, g, b;
  cin >> r >> g >> b;

  int num = r*100 + g*10 + b;
  printf("%s\n", num%4==0?"YES":"NO");

  return 0;
}
