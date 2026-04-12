#include <bits/stdc++.h>
using namespace std;

#define int long long

#define ii pair<int,int>
#define fi first
#define sc second

#define all(x) (x).begin(),(x).end()

signed main() {
#ifdef _DEBUG
  // freopen("in" , "r", stdin );
  // freopen("out", "w", stdout);
#endif
  ios::sync_with_stdio(0); cin.tie(0);
  int a, b, c, x, y;
  cin >> a >> b >> c >> x >> y;
  int ans = 0;
  if (c * 2 < a + b) {
    int t = min(x, y);
    ans += t * c * 2;
    x -= t;
    y -= t;
  }
  ans += min(x * a, x * c * 2) + min(y * b, y * c * 2);
  cout << ans << '\n';
}
