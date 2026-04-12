#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using  namespace std;
typedef long long ll;

int main()
{
  int n;
  ll x;
  cin >> n >> x;
  ll p[n+1], b[n+1], l[n+1];
  p[0] = 1;
  b[0] = 0;
  rep(i, n) p[i+1] = 2 * p[i] + 1;
  rep(i, n) b[i+1] = 2 * b[i] + 2;
  rep(i, n+1) l[i] = p[i] + b[i];

  ll ans = 0;
  while (n > 0 && x > 0) {
    ll mid = l[n-1] + 2;
    if (x < mid) {
      --x;
    }
    else {
      ans += p[n-1] + 1;
      x -= mid;
    }
    --n;
  }

  if (x > 0) ++ans;
  cout << ans << endl;
  return 0;
}