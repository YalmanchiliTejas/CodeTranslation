#include <bits/stdc++.h>

#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
typedef long long ll;
const int INF = 1e9;

int main() {
  ll a, b, c, x, y, maxm = INF, ans = 0;
  bool flg = false;
  cin >> a >> b >> c >> x >> y;

  if (a + b > 2 * c) {
    ans += 2 * min(x, y) * c;
    if (x == y) {
    } else if (x > y) {
      ans += min((x - y) * a, (x - y) * 2 * c);
    } else {
      ans += min((y - x) * b, (y - x) * 2 * c);
    }
  } else {
    ans = a * x + b * y;
  }

  cout << ans << endl;
  return 0;
}
