#include <bits/stdc++.h>
#define REP(i, n) for(int i = 0; i < (n); i++)
#define REPR(i, n) for(int i = (n); i >= 0; i--)
#define FOR(i, m, n) for(int i = (m); i < (n); i++)
#define INF 1e9
#define ALL(v) (v).begin(), (v).end()
#define debug(x) cerr << #x << ": " << x << endl;

using namespace std;
typedef long long ll;

signed main() {
  int a, b, c, x, y, ans = INF;
  cin >> a >> b >> c >> x >> y;

  REP(i, 100001) {
    ans = min(ans, 2 * c * i + max(0, x - i) * a + max(0, y - i) * b);
  }

  cout << ans << endl;
  return 0;
}
