#include <bits/stdc++.h>
using namespace std;
typedef long long ll;


int main() {
  ll a, b, c;
  int x, y;
  cin >> a >> b >> c >> x >> y;

  ll ans = 1e18;
  for (int i = 0; i <= max(x, y) * 2; ++i) {
    int rx = max(0, x - i / 2);
    int ry = max(0, y - i / 2);
    ll total = (c * i) + (a * rx) + (b * ry);
    ans = min(ans, total);
  }
  cout << ans << '\n';
  return 0;
}
