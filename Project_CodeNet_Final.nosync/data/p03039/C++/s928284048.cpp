#include <bits/stdc++.h>
using namespace std;
#define int long long
typedef int ll;
typedef long double ld;
const ll N = 200005;
char en = '\n';
ll inf = 1e16;
ll mod = 1e9 + 7;
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

ll fact[N];
ll ifact[N];

ll nCr(ll n, ll r) {
  if (n < r)
    return 0;
  return fact[n] * ifact[r] % mod * ifact[n - r] % mod;
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  fact[0] = ifact[0] = 1;
  for (ll i = 1; i < N; i++) {
    fact[i] = (i * fact[i - 1]) % mod;
    ifact[i] = power(fact[i], mod - 2, mod);
  }
  ll n, m, k;
  cin >> n >> m >> k;

  ll res = 0;
  for (ll i = 1; i <= n; i++) {
    for (ll j = 1; j <= m; j++) {
      ll L = i - 1;
      ll R = n - i;

      ll valL = (L * (L + 1) / 2) % mod;
      ll valR = (R * (R + 1) / 2) % mod;
      res += m * nCr(n * m - 2, k - 2) % mod * valL % mod;
      res %= mod;
      res += m * nCr(n * m - 2, k - 2) % mod * valR % mod;
      res %= mod;
    }
  }

  swap(n, m);
  for (ll i = 1; i <= n; i++) {
    for (ll j = 1; j <= m; j++) {
      ll L = i - 1;
      ll R = n - i;

      ll valL = (L * (L + 1) / 2) % mod;
      ll valR = (R * (R + 1) / 2) % mod;
      res += m * nCr(n * m - 2, k - 2) % mod * valL % mod;
      res %= mod;
      res += m * nCr(n * m - 2, k - 2) % mod * valR % mod;
      res %= mod;
    }
  }

  res *= power(2, mod - 2, mod);
  res %= mod;
  cout << res << en;

  return 0;
}