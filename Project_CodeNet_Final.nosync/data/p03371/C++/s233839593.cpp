#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int a, b, c, x, y;
  cin >> a >> b >> c >> x >> y;
  int ans = a * x + b * y;

  ans = min(ans, 2 * c * max(x, y));
  if (x < y)
    ans = min(ans, 2 * c * x + b * (y - x));
  else
    ans = min(ans, 2 * c * y + a * (x - y));
  cout << ans << '\n';
  return 0;
}
