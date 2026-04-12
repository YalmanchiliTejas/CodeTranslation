#include<bits/stdc++.h>

using namespace std;
using ll = long long;

const ll nax = 1e4 + 12;
const ll md = 1e9 + 7;

ll dp[nax][123][2];
ll n, d;
string s;

ll add (ll &a, ll b)
{
  a += b;
  if (a > md) {
    a -= md;
  }
}

ll sub (ll &a, ll b)
{
  a -= b;
  if (a < 0) {
    a += md;
  }
}

ll solve (ll pos, ll rem, ll f)
{
  if (pos == n) {
    return (rem == 0);
  }
  if (dp[pos][rem][f] != -1) {
    return dp[pos][rem][f];
  }
  ll ans = 0;
  ll limit = 0;
  if (f == 1) {
    limit = 9;
  } else {
    limit = s[pos] - '0';
  }
  for (ll i = 0; i <= limit; i++) {
    ll nf = f;
    if (f == 0 && i < limit) {
      nf = 1;
    }
    ll new_rem = (rem + i) % d;
    add (ans, solve (pos + 1, new_rem, nf) );
  }
  return dp[pos][rem][f] = ans;
}

int main()
{
  ios_base::sync_with_stdio (0);
  cin.tie (0);
  memset (dp, -1, sizeof (dp) );
  cin >> s >> d;
  n = (ll) s.length();
  ll ans  = solve (0, 0, 0);
  sub (ans, 1LL);
  cout << ans << '\n';
  return 0;
}
