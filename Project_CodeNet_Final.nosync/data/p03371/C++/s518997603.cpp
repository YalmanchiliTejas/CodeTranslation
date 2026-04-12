#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using ull = unsigned long long;
using P = pair<int, int>;
const int INF = 1e9;

int main() {
  int a, b, c, x, y;
  cin >> a >> b >> c >> x >> y;
  double ave = (a + b) / 2.0;
  ll price = 0;
  if (ave > c) {
    if (x != y) {
      if (x > y) {
        if (c * 2 < a) {
          price = c * 2 * x;
        } else {
          price = y * c * 2 + a * (x - y);
        }
      } else {
        if (c * 2 < b) {
          price = c * 2 * y;
        } else {
          price = x * c * 2 + b * (y - x);
        }
      }
    } else {
      price = x * c * 2;
    }
  } else {
    price = a * x + b * y;
  }
  cout << price << endl;
}
