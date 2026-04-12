#include <bits/stdc++.h>

using namespace std;

typedef long long llint;

int main() {
  int a, b, c, x, y;
  cin >> a >> b >> c >> x >> y;
  int ans = 0;
  if (c * 2 < a + b) {
    int m = min(x, y);
    x -= m, y -= m;
    ans += 2 * c * m;
  }
  if (c * 2 < a) {
    ans += 2 * c * x;
    x = 0;
  }
  if (c * 2 < b) {
    ans += 2 * c * y;
    y = 0;
  }
  ans += a * x + b * y;
  cout << ans << endl;

  return 0;
}