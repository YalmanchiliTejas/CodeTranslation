#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define rep(i, n) for (int i = 0; i < (n); i++)
#define repp(i, s, e) for (int i = (s); i < (e); i++)
#define all(x) x.begin(), x.end()

#define endl "\n"

void use_cio() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
}

template <class L, class R>
ostream &operator<<(ostream &os, pair<L, R> P) {
  return os << "(" << P.first << "," << P.second << ")";
}
template <class T>
ostream &operator<<(ostream &os, vector<T> V) {
  os << "[";
  for (auto x : V) os << x << ", ";
  return os << "]";
}
//--------------------------------------------------//
const int MOD = 1e9 + 7;
inline ll add(ll a, ll b) { return (a + b) % MOD; }
inline ll mul(ll a, ll b) { return ((a % MOD) * (b % MOD)) % MOD; }
ll pow_mod(ll x, ll n) {
  ll ret = 1;
  for (; n; n >>= 1, x = mul(x, x))
    if (n & 1) ret = mul(ret, x);
  return ret;
}
inline ll inv_mod(ll x) { return pow_mod(x, MOD - 2); }

int main() {
  use_cio();
  int n, m, k;
  cin >> n >> m >> k;

  ll val = 1,
     ans = 0;
  rep(i, k - 2) {
    val = mul(val, n * m - 2 - i);
    val = mul(val, inv_mod(i + 1));
  }
  repp(i, 1, n) ans += mul(mul(m, m), mul(i, n - i));
  repp(i, 1, m) ans += mul(mul(n, n), mul(i, m - i));

  cout << mul(ans, val) << endl;
}
