#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << fixed << setprecision(15);

  int a, b, c, x, y;
  cin >> a >> b >> c >> x >> y;
  x *= 2;
  y *= 2;
  int64_t sum = 0;

  if (a + b <= c * 2) {
    sum = (a * x + b * y) / 2;
  } else {
    if (x == y) {
      sum = c * x;
    } else if (x < y) {
      if (c * 2 < b) {
        sum = c * y;
      } else {
        sum = c * x + (b * (y - x) / 2);
      }
    } else {
      if (c * 2 < a) {
        sum = c * x;
      } else {
        sum = c * y + (a * (x - y) / 2);
      }
    }
  }
  cout << sum << '\n';

  return 0;
}
