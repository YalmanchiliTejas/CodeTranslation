#include <bits/stdc++.h>
using namespace std;

int main() {
  int a, b, c, x, y, sum;

  cin >> a >> b >> c >> x >> y;

  if (a + b > c * 2) {
    if (x < y) {
      sum = c * x * 2;
      for (int i = 0; i < y - x; i++) {
        if (b > c * 2) {
          sum += c * 2;
        } else {
          sum += b;
        }
      }
    } else {
      sum = c * y * 2;
      for (int i = 0; i < x - y; i++) {
        if (a > c * 2) {
          sum += c * 2;
        } else {
          sum += a;
        }
      }
    }
  } else {
    sum = a * x + b * y;
  }

  cout << sum << endl;
}
