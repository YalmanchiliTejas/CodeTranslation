#include <bits/stdc++.h>
using namespace std;

int main() {
  int a, b, c, x, y;
  cin >> a >> b >> c >> x >> y;
  
  int sum = 0;
  
  if (a + b > c * 2) {
    if (x >= y) {
      for (int i = 0; i < y; i++) {
        sum += c * 2;
      }
      if (a > c * 2) {
        sum += c * 2 * (x - y);
      }
      else if (a <= c * 2) {
        sum += a * (x - y);
      }
    }
    else if (y > x) {
      for (int i = 0; i < x; i++) {
        sum += c * 2;
      }
      if (b > c * 2) {
        sum += c * 2 * (y - x);
      }
      else if (b <= c * 2) {
        sum += b * (y - x);
      }
    }
  }
  
  else if (a + b <= c * 2) {
    sum = a * x + b * y;
  }
  
  cout << sum << endl;
  return 0;
}