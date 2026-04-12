#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
  ll a, b, c, x, y;
  cin >> a >> b >> c >> x >> y;
  ll ans = 0;
  rep(i, 100000) {
    if (i >= x && i >= y) break;
    if (i >= x) {
      ans += min(c * 2, b);
    } else if (i >= y) {
      ans += min(c * 2, a);
    } else {
      ans += min(c * 2, a + b);
    }
  }
  cout << ans << endl;
  return 0;
}