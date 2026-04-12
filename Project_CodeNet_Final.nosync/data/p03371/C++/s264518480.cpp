#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main()
{
  int a, b, c, x, y;
  cin >> a >> b >> c >> x >> y;
  int ca = 0, cb = 0;
  ll ans = 0;
  while (ca < x && cb < y)
  {
    ans += min(2 * c, a + b);
    ca++;
    cb++;
  }
  while (ca < x)
  {
    ans += min(2 * c, a);
    ca++;
  }
  while (cb < y)
  {
    ans += min(2 * c, b);
    cb++;
  }
  cout << ans << endl;
  return 0;
}