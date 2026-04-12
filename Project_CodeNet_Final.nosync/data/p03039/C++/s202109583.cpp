#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> ii;
typedef pair<ll, ll> l4;
typedef pair<double, double> dd;
#define mp make_pair
#define pb push_back
#define debug(x) cerr << #x << " = " << x << " "

const int mod = 1e9+7;
ll power(ll base, ll p)
{
  ll ret = 1 % mod;
  while (p)
    {
      if (p&1) ret = ret * base % mod;
      p >>= 1;
      base = base * base % mod;
    }
  return ret;
}

ll inverse(ll base)
{
  return power(base, mod-2);
}
const int N = 2e5+1;
ll f[N], inv[N];
inline ll cb(ll n, ll k)
{
  if (n < k || n < 0 || k < 0) return 0;
  return f[n] * inv[k] % mod * inv[n-k] % mod;
}
void init()
{
  f[0] = 1;
  for (ll i = 1; i < N; ++i) f[i] = f[i-1] * i % mod;
  inv[N-1] = inverse(f[N-1]);
  for (int i = N-1; i >= 1; --i) inv[i-1] = inv[i] * i % mod;
}
int main()
{
  init();
  int n, m, k; scanf("%d %d %d", &n, &m, &k);
  ll ans = 0;
  ll cnt_per_pair = cb(n*m-2, k-2);
  //  cerr << "cnt_per_pair = " << cnt_per_pair << endl;
  for (int t = 0; t < 2; ++t, swap(n, m))
    for (int i = 1; i <= (n-1); ++i)
      (ans += 1ll * i * (n-i) % mod * m % mod * m % mod) %= mod;
  (ans *= cnt_per_pair) %= mod;
  printf("%lld\n", ans);
}

// 126 * 6 / 36
