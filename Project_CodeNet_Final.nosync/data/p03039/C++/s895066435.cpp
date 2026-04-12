#include <bits/stdc++.h>
using namespace std;

#define dump(x)  cout << #x << " = " << (x) << endl;

typedef long long ll;
typedef pair<int, int> ii;
const int mod = 1e9+7;
const ll INF = 1e18;
const int inf = 1e9;

const int MAX = 510000;
ll fac[MAX], finv[MAX], inv[MAX];

void cominit(ll m)
{
  fac[0] = fac[1] = 1;
  finv[0] = finv[1] = 1;
  inv[1] = 1;
  for (int i=2; i<MAX; i++) {
    fac[i] = fac[i-1] * i % m;
    inv[i] = m - inv[m%i] * (m/i) % m;
    finv[i] = finv[i-1] * inv[i] % m;
  }
}

ll com(ll n, ll k, ll m)
{
  if (n<k) return 0;
  if (n<0 || k<0) return 0;
  return fac[n] * (finv[k] * finv[n-k] % m) % m;
}

void solve()
{
  cominit(mod);
  ll n,m,k;
  cin>>n>>m>>k;

  ll x=0, y=0;
  for (ll d=1; d<n; d++) {
    x += d * (n-d) % mod;
  }
  x = x * m % mod * m % mod;
  for (ll d=1; d<m; d++) {
    y += d * (m-d) % mod;
  }
  y = y * n % mod * n % mod;

  ll ans = (x+y) % mod * com(n*m-2, k-2, mod) % mod;
  cout << ans << endl;
}

int main()
{
  solve();
  return 0;
}
