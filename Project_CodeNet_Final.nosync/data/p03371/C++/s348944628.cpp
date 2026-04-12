#include <bits/stdc++.h>
using namespace std;
#define rep(i, ss, ee) for (int i = (ss); i < (ee); ++i)
const int INF = 1e9 + 1;

void solve() {
  int a, b, c, x, y;
  cin >> a >> b >> c >> x >> y;

  int ans = INF;
  rep(i, 0, 1e5 + 1) {
    ans = min(ans, i * 2 * c + max(0, x - i) * a + max(0, y - i) * b);
  }
  cout << ans << endl;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  solve();
}