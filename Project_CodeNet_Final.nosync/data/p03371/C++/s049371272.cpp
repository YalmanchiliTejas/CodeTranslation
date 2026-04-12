#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int a, b, c, x, y;
  cin >> a >> b >> c >> x >> y;
  int ans = 0;
  if (a + b > 2 * c) {
    int xy = min(x, y);
    ans += xy * 2 * c;
    ans += (x - xy) * min(a, 2 * c);
    ans += (y - xy) * min(b, 2 * c);
  } else {
    ans += a * x;
    ans += b * y;
  }
  cout << ans << '\n';
  return 0;
}