#include <bits/stdc++.h>
using namespace std;

template<typename T> void drop(const T &x){cout<<x<<'\n';exit(0);}

void solve() {
  int a, b, c, x, y;
  cin >> a >> b >> c >> x >> y;

  int ans = a*x + b*y;
  ans = min(ans, c * 2*max(x,y));
  int tmp;
  if(x < y) tmp = b*(y-x);
  else tmp = a*(x-y);
  ans = min(ans, c * 2*min(x,y) + tmp);
  cout << ans << '\n';
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int T=1;
  //cin >> T;
  while(T--) solve();

  return 0;
}
