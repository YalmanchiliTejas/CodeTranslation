#include <bits/stdc++.h>
using namespace std;
#define int long long
typedef int ll;
typedef long double ld;
const ll N = 200005;
char en = '\n';
ll inf = 1e16;
ll mod = 998244353;
ll power(ll x, ll n, ll mod) {
  ll res = 1;
  x %= mod;
  while (n) {
    if (n & 1)
      res = (res * x) % mod;
    x = (x * x) % mod;
    n >>= 1;
  }
  return res;
}

ll dp[3005][3005];
ll arr[3005];
ll n;
ll recur(ll pos, ll rem) {

  if (rem < 0) {
    return 0;
  }
  if (rem == 0) {
    return pos - 1;
  }
  if (pos == n + 1)
    return 0;

  ll &ans = dp[pos][rem];
  if (ans != -1)
    return ans;

  ans = recur(pos + 1, rem - arr[pos]) + recur(pos + 1, rem);

  if (ans >= mod)
    ans -= mod;
  return ans;
}

ll recur2(ll pos, ll rem) {

  if (rem < 0) {
    return 0;
  }
  if (rem == 0) {
    return 1;
  }
  if (pos == n + 1)
    return 0;

  ll &ans = dp[pos][rem];
  if (ans != -1)
    return ans;

  ans = recur2(pos + 1, rem - arr[pos]) + recur2(pos + 1, rem);

  if (ans >= mod)
    ans -= mod;
  return ans;
}

int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  ll s;
  cin >> n >> s;
  for (ll i = 1; i <= n; i++)
    cin >> arr[i];

  memset(dp, -1, sizeof(dp));

  ll res = 0;
  for (ll i = 1; i <= n; i++) {
    res += (n + 1) * i % mod * recur2(i + 1, s - arr[i]) % mod;
    if (res >= mod)
      res -= mod;
  }

  memset(dp, -1, sizeof(dp));
  for (ll i = 1; i <= n; i++) {
    res -= i * recur(i + 1, s - arr[i]) % mod;
    if (res < 0)
      res += mod;
  }

  cout << res << en;

  return 0;
}
