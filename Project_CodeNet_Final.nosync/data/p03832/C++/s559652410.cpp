#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using V = vector<int>;
using Vll = vector<ll>;
using Vld = vector<ld>;
using Vbo = vector<bool>;
using VV = vector<V>;
using VVll = vector<Vll>;
using VVld = vector<Vld>;
using VVbo = vector<Vbo>;
using P = pair<int, int>;
using Pll = pair<ll, ll>;
using Pld = pair<ld, ld>;
#define rep2(i, m, n) for(ll i=int(m); i<int(n); ++i)
#define drep2(i, m, n) for(ll i=int(m)-1; i>=int(n); --i)
#define rep(i, n) rep2(i, 0, n)
#define drep(i, n) drep2(i, n, 0)
#define all(a) a.begin(), a.end()
struct fast_ios { fast_ios(){ cin.tie(0); ios::sync_with_stdio(false); cout << fixed << setprecision(20); }; } fast_ios_;
template<typename T> inline bool chmin(T &a, T b) { if (a > b) { a = b; return true; } return false; }
template<typename T> inline bool chmax(T &a, T b) { if (a < b) { a = b; return true; } return false; }
template<typename T1, typename T2> istream &operator>>(istream &is, pair<T1, T2> &p) { is >> p.first >> p.second; return is; }
template<typename T1, typename T2> ostream &operator<<(ostream &os, const pair<T1, T2> &p) { os << "(" << p.first << ", " << p.second << ")"; return os; }
template<typename T> istream &operator>>(istream &is, vector<T> &v) { for (auto &e : v) is >> e; return is; }
template<typename T> ostream &operator<<(ostream &os, const vector<T> &v) { for (auto &e : v) os << e << " "; return os; }
template<typename T> inline int count_between(vector<T> &a, T l, T r) { return lower_bound(all(a), r) - lower_bound(all(a), l); } // [l, r)
inline int Log2(ll x) { int k; for (k = 0; x > 0; ++k) x >>= 1; return k; } // number of binary digits
const int INF  = 1<<30;
const ll INFll = 1ll<<62;
const ld EPS   = 1e-10;
const int MOD  = int(1e9)+7;


struct mint {
  ll x;
  mint(ll xx=0) : x(xx) { if (xx >= MOD || xx <= -MOD) x = xx % MOD; if (x < 0) x += MOD; }
  mint operator-() const { return mint(-x);}
  mint& operator+=(const mint a) { if ((x += a.x) >= MOD) x -= MOD; return *this; }
  mint& operator-=(const mint a) { if ((x -= a.x) < 0) x += MOD; return *this; }
  mint& operator*=(const mint a) { (x *= a.x) %= MOD; return *this;}
  mint operator+(const mint a) const { return mint(*this) += a;}
  mint operator-(const mint a) const { return mint(*this) -= a;}
  mint operator*(const mint a) const { return mint(*this) *= a;}
  mint pow(ll t) const {
    if (!t) return 1;
    mint a = pow(t>>1);
    a *= a;
    if (t&1) a *= *this;
    return a;
  }
  mint& operator/=(const mint r) {
    ll a = r.x, b = MOD, u = 1, v = 0;
    while (b) {
      ll t = a / b;
      a -= t * b; swap(a, b);
      u -= t * v; swap(u, v);
    }
    x = x * u % MOD;
    if (x < 0) x += MOD;
    return *this;
  }
  mint operator/(const mint a) const { return mint(*this) /= a;}
};
// istream& operator>>(istream& is, mint& a) { return is >> a.x;}
ostream& operator<<(ostream& os, const mint& a) { return os << a.x;}
using Vm = vector<mint>;


// initialization
const int F_MAX = int(1e3)+10;
ll fac[F_MAX], finv[F_MAX], inv[F_MAX];
void binom_init() {
  fac[0] = fac[1] = 1;
  finv[0] = finv[1] = 1;
  inv[1] = 1;
  for (int i = 2; i < F_MAX; ++i) {
    fac[i] = fac[i-1] * i % MOD;
    inv[i] = MOD - inv[MOD%i] * (MOD/i) % MOD;
    finv[i] = finv[i-1] * inv[i] % MOD;
  }
}

// binom mod MOD
ll binom(int n, int k) {
  if (k < 0 || n < k) return 0;
  return fac[n] * (finv[k] * finv[n-k] % MOD) % MOD;
}


int main() {
  binom_init();
  ll n, a, b, c, d; cin >> n >> a >> b >> c >> d;

  Vm dp(n+1);
  dp[0] = 1;

  drep2(i, b+1, a) drep2(j, n+1, 0) {
    mint x = 1;
    rep(k, c) x *= binom(j-k*i, i);
    rep2(k, c, min(d, j/i)+1) {
      dp[j] += dp[j-i*k] * x * finv[k];
      x *= binom(j-k*i, i);
    }
  }

  cout << dp[n] << "\n";
  return 0;
}
