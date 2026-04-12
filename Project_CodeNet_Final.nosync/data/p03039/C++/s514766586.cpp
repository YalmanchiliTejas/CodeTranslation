#include <bits/stdc++.h>
#define REP(i, n) for (int i = 0; i < n; i++)
#define FOR(i, m, n) for (int i = m; i < n; i++)
#define ll long long int

struct edge
{
  int to, cost;
};
typedef std::vector<std::vector<edge>> graph;
const ll MOD = 1000000007;
using namespace std;

ll modpow(ll a, ll n, ll mod)
{
  ll res = 1;
  while (n > 0)
  {
    if (n & 1)
      res = res * a % mod;
    a = a * a % mod;
    n >>= 1;
  }
  return res;
}

ll modinv(ll a, ll mod)
{
  return modpow(a, mod - 2, mod);
}

ll modnCr(ll n, ll r, ll mod)
{
  ll ans = 1;
  FOR(i, 1, n + 1)
  {
    ans = (ans * i) % mod;
  }
  ll inv = 1;
  FOR(i, 1, r + 1)
  {
    inv = (inv * i) % mod;
  }
  FOR(i, 1, n - r + 1)
  {
    inv = (inv * i) % mod;
  }
  ans = (ans * modinv(inv, mod)) % mod;
  return ans;
}

int main()
{
  ll n, m, k;
  cin >> n >> m >> k;
  ll ans = 0;
  ll kumi = modnCr(n * m - 2, k - 2, MOD);
  FOR(d, 1, n)
  {
    ll tmp = (d * (n - d)) % MOD;
    tmp = (tmp * m) % MOD;
    tmp = (tmp * m) % MOD;
    ans = (ans + (tmp * kumi) % MOD) % MOD;
  }
  FOR(d, 1, m)
  {
    ll tmp = (d * (m - d)) % MOD;
    tmp = (tmp * n) % MOD;
    tmp = (tmp * n) % MOD;
    ans = (ans + (tmp * kumi) % MOD) % MOD;
  }

  cout << ans << endl;
}
