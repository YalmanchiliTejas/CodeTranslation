#include <bits/stdc++.h>

#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
typedef long long ll;
const int INF = 1e9;

int main() {
  int a, b, c, x, y, ans = INF, t = 0;
  cin >> a >> b >> c >> x >> y;
  int mx = max(x, y);

  for (int i = 0; i <= mx; ++i) {
    t = 2 * c * i;
    if (x - i > 0) t += a * (x - i);
    if (y - i > 0) t += b * (y - i);
    ans = min(ans, t);
  }

  cout << ans << endl;
  return 0;
}
