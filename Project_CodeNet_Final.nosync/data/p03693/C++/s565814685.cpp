#include <iostream>
#include <math.h>
#include <string>
#include <algorithm>
using namespace std;

int main() {
  int a, b, c;
  cin >> a >> b >> c;
  int tmp = a * 100 + b * 10 + c;
  cout << (tmp%4==0 ? "YES" : "NO");
  
}