#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;

int main() {
  int a, b, c, x, y;
  int price, pmin = INT_MAX;
  cin >> a >> b >> c >> x >> y;
  pmin = min(x, y);
  if (c * 2 < a + b) {
    price = (c * 2) * pmin;
  } else {
    price = a * pmin + b * pmin;
  }
  x -= pmin;
  y -= pmin;
  if (x != 0) {
    if (a * x < (c * 2) * x) {
      price += a * x;
    } else {
      price += (c * 2) * x;
    }
  } else {
    if (b * y < (c * 2) * y) {
      price += b * y;
    } else {
      price += (c * 2) * y;
    }
  }
  cout << price << endl;
}