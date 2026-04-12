#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define repr(i, n) for (int i = (n); i >= 0; --i)
#define FOR(i, m, n) for (int i = (m); i < (n); ++i)
#define FORR(i, m, n) for (int i = (m); i >= (n); --i)
using namespace std;
typedef long long ll;
const ll mod = 1000000007;
const ll mod2 = 998244353;
//x, y方向独立で
// nCrはa/b mod pを用いる

ll modpow(ll a,ll n) {
  ll res = 1;
  while (n > 0) {
    if (n & 1) res = res * a % mod;
    a = a * a % mod;
    n >>= 1;
  }
  return res;
}

ll nCr(ll n, ll r) {
  r = min(n-r, r);
  if (r == 0) return 1;
  ll ans = 1;
  FOR(i, n-r+1, n+1) ans = ans * i % mod;
  ll a = 1;
  FOR(i, 1, r+1) a = a * i % mod;
  ans = ans * modpow(a, mod-2) % mod;
  return ans;
}

int main() {
  ll n, m, k;
  cin >> n >> m >> k;
  ll comb = nCr(n*m-2, k-2);
  ll ans = 0;
  rep(i, m) {
    ll cost = comb;
    cost = cost * (m-i) % mod;
    cost = cost * i % mod;
    cost = cost * n % mod;
    cost = cost * n % mod;
    ans += cost;
    ans %= mod;
  }
  rep(i, n) {
    ll cost = comb;
    cost = cost * (n-i) % mod;
    cost = cost * i % mod;
    cost = cost * m % mod;
    cost = cost * m % mod;
    ans += cost;
    ans %= mod;
  }
  cout << ans << endl;
}