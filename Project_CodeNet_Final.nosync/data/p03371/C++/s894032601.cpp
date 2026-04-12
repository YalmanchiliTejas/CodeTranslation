#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
  ll a, b, c, x, y, ans = 1e9 + 7;
  cin >> a >> b >> c >> x >> y;

  for (ll i = 0; i < x + y; i++)
  {
    ll m = (2 * c * i) + (a * max(x - i, (ll)0)) + (b * max(y - i, (ll)0));
    ans = min(ans, m);
  }
  cout << ans << endl;
}
