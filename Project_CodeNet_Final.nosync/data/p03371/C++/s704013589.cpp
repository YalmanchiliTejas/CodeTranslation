#include <algorithm>
#include <cmath>
#include <iostream>
#include <string>
#include <vector>

using namespace std;
using ll = long long;

int main() {
  int A, B, C, X, Y;
  cin >> A >> B >> C >> X >> Y;
  ll price;
  if (A + B >= 2 * C) {
    // ABの方がトク
    int AB = min(X, Y);
    price = (2 * C * AB);
    if (X > Y) {
      price += A * (X - Y);
    } else {
      price += B * (Y - X);
    }
    if (price > 2 * C * max(X, Y)) {
      price = 2 * C * max(X, Y);
    }
  } else {
    price = A * X + B * Y;
  }
  cout << price << endl;
  return 0;
}