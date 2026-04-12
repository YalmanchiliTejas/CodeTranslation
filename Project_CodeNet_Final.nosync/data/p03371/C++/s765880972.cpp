#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);

  ll a, b, c, x, y; cin >> a >> b >> c >> x >> y;
  ll ans = pow(10, 10);

  ll m;
  for (ll i = 0; i <= max(x, y)*2 ; i+=2) {
    m = c*i;
    if (x-i/2 > 0) m += (x-i/2)*a;
    if (y-i/2 > 0) m += (y-i/2)*b;
    ans = min(ans, m);
  }

  cout << ans << endl;

  return 0;
}