#include <bits/stdc++.h>
using namespace std;

using ll = long long int;

const int MAX = (int)(1e5 + 5);
const ll INF = (ll)(1e10 + 5);

const ll MOD = (ll)(1e9 + 7);

/////////////////////////////////////////////////////////////
class CombinationModulo {
public:
  static const int MAX_N_LIB = (int)(2e5 + 100);
  static const ll MOD_LIB = (ll)(1e9 + 7);

  ll fact[MAX_N_LIB];
  ll inv[MAX_N_LIB];
  ll fact_inv[MAX_N_LIB];

  CombinationModulo(int n) {
    init(n);
  }

  void init(int n) {
    inv[1] = fact[0] = fact_inv[0] = 1;
    for (int i = 2; i <= n; i++) {
      inv[i] = (MOD_LIB - (MOD_LIB / i) * inv[MOD_LIB % i] % MOD_LIB) % MOD_LIB;
    }
    for (int i = 1; i <= n; i++) {
      fact[i] = fact[i - 1] * i % MOD_LIB;
    }
    for (int i = 1; i <= n; i++) {
      fact_inv[i] = fact_inv[i - 1] * inv[i] % MOD_LIB;
    }
  }

  ll comb(int n, int r) {
    if (r > n) return 0;
  	return fact[n] * fact_inv[r] % MOD_LIB * fact_inv[n - r] % MOD_LIB;
  }
};
/////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////
class ModuloOperator {
public:
  ll mo_modulo;

  ModuloOperator(ll modulo) {
    mo_modulo = modulo;
  }

  ll add(ll a, ll b) {
    ll ret = a + b;
    ret %= mo_modulo;
    return ret;
  }

  ll sub(ll a, ll b) {
    ll ret = a - b;
    if (ret < 0) ret += mo_modulo;
    else ret %= mo_modulo;
    return ret;
  }

  ll mul(ll a, ll b) {
    ll ret = a * b;
    ret %= mo_modulo;
    return ret;
  }

  ll div(ll a, ll b) {
    return mul(a, pow(b, mo_modulo - 2));
  }

  ll pow(ll x, ll y) {
    ll res = 1LL;

    x %= mo_modulo;

    while (y > 0) {
      if (y & 1) {
        res = mul(res, x);
      }

      y = y >> 1;
      x = mul(x, x);
    }

    return res;
  }
};
/////////////////////////////////////////////////////////////

ll n, m, k;

ll ans;

ModuloOperator mo(MOD);

int main(void) {
  // Here your code !
  scanf("%lld %lld %lld", &n, &m, &k);

  int size = (int)(n * m + 3);
  CombinationModulo cm(size);

  ans = 0;

  ll base_comb = cm.comb((int)(n * m - 2), (int)(k - 2));

  for (ll i = 1; i <= n - 1; ++i) {
    ll slide_size = n - i;

    ll times = mo.mul(mo.mul(slide_size, mo.mul(m, m)), base_comb);
    ll commit = mo.mul(i, times);

    ans = mo.add(ans, commit);
  }

  for (ll i = 1; i <= m - 1; ++i) {
    ll slide_size = m - i;

    ll times = mo.mul(mo.mul(slide_size, mo.mul(n, n)), base_comb);
    ll commit = mo.mul(i, times);

    ans = mo.add(ans, commit);
  }

  printf("%lld\n", ans);

  return 0;
}
