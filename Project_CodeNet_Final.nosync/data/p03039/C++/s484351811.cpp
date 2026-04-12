#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); i++)
using namespace std;
typedef long long ll;

int MOD = 1000000007;

ll mod_pow(ll x, ll n)
{
  ll ret = 1;
  while (n > 0)
  {
    if (n & 1)
      ret = ret * x % MOD;
    x = x * x % MOD;
    n >>= 1;
  }
  return ret;
}

vector<ll> fact;
vector<ll> ifact;

void mod_ifact(ll n)
{
  fact.resize(n + 1);
  fill(fact.begin(), fact.end(), 1);
  ifact.resize(n + 1);
  fill(ifact.begin(), ifact.end(), 0);
  for (ll i=1; i<n+1; i++)
    fact[i] = fact[i-1] * i % MOD;
  ifact[n] = mod_pow(fact[n], MOD - 2);
  for (ll i=n; i>0; i--)
    ifact[i-1] = ifact[i] * i % MOD;
}

ll mod_comb(ll n, ll k)
{
  if (k < 0 || k > n)
    return 0;
  return fact[n] * ifact[k] % MOD * ifact[n-k] % MOD;
}
int main()
{
  ll n, m, k;
  cin >> n >> m >> k;
  ll ans = 0;
  mod_ifact(n * m);
  ll c = mod_comb(n * m - 2, k - 2);
  for (int i=1; i<m; i++)
    ans = (ans + i * n % MOD * n % MOD * (m - i) % MOD * c) % MOD;
  for (int i=1; i<n; i++)
    ans = (ans + i * m % MOD * m % MOD * (n - i) % MOD * c) % MOD;
  cout << ans << endl;
  return 0;
}