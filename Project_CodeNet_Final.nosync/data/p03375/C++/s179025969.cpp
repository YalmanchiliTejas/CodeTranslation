
#include <bits/stdc++.h>

#define rep(x,y) for (int (x) = 0;(x) < (y);++(x))
#define all(x) (x).begin(),(x).end()
#define fi first
#define sc second
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

const int max_n = 3000;
ll fact[max_n+1];
ll inv_fact[max_n+1];
ll n, m;
ll dp[max_n+1][max_n+1];

ll extgcd(ll a, ll b, ll& x, ll& y) {
  ll d = a;
  if (b != 0) {
    d = extgcd(b, a%b, y, x);
    y -= (a/b) * x;
  } else {
    x = 1; y = 0;
  }
  return d;
}

ll mod_inverse(ll a, ll m) {
  ll x, y;
  extgcd(a, m, x, y);
  return (m + x%m) % m;
}


void init(ll n, ll mod) {
  fact[0] = 1;
  for (int i = 1; i <= n; ++i) fact[i] = (fact[i-1]*i)%mod;

  for (int i = 0; i <= n; ++i) inv_fact[i] = mod_inverse(fact[i], mod);
}

ll mod_comb(ll n, ll r, ll mod) {
  return fact[n]*inv_fact[r]%mod*inv_fact[n-r]%mod;
}

//x^nをmodのもとで計算する
ll mod_pow(ll x, ll n, ll mod) {
  if (n == 0) return 1;
  ll res = mod_pow((x*x) % mod, n/2, mod);
  if (n & 1) res = (res*x) % mod;
  return res;
}

ll f[max_n+1];
ll pow_m_1[max_n+1];

int main() {
  cin >> n >> m;
  init(n, m);

  dp[0][0] = 1;
  for (int k = 1; k <= n; ++k) {
    dp[k][0] = 1;
    for (int x = 1; x <= k; ++x) {
      dp[k][x] = (((x+1)*dp[k-1][x]%m) + dp[k-1][x-1])%m;
    }
  }

  for (int i = 0; i <= n; ++i) pow_m_1[i] = mod_pow(2, i, m-1);

  for (int k = 0; k <= n; ++k) {
    ll mp1 = mod_pow(2, pow_m_1[n-k], m), mp2 = mod_pow(2, (n-k), m);
    ll mp0 = 1;
    for (int x = 0; x <= k; ++x) {
      f[k] += dp[k][x] * mp0 % m * mp1 % m;
      f[k] %= m;
      mp0 = mp0 * mp2 % m;
    }
  }

  ll ans = 0;
  for (int k = 0; k <= n; ++k) {
    ans += mod_comb(n, k, m) * f[k] % m * (k & 1 ? -1 : 1) % m;
    ans = (ans+m) % m;
  }

  cout << ans << endl;

  return 0;
}
