#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
#define rep2(i, m, n) for (int i = (m); i < (n); ++i)
#define rep(i, n) rep2(i, 0, n)
#define drep2(i, m, n) for (int i = (m)-1; i >= (n); --i)
#define drep(i, n) drep2(i, n, 0)
#define all(a) (a).begin(), (a).end()
template<typename T = int> using V = vector<T>;
template<typename T = int> using P = pair<T, T>;
using Vi = V<int>;
using Vl = V<ll>;
using Vd = V<ld>;
using Vb = V<bool>;
using VVi = V<Vi>;
using VVl = V<Vl>;
using VVb = V<Vb>;
using Pi = P<int>;
using Pl = P<ll>;
using Pd = P<ld>;
template<typename T> vector<T> make_vec(size_t n, T a) { return vector<T>(n, a); }
template<typename... Ts> auto make_vec(size_t n, Ts... ts) { return vector<decltype(make_vec(ts...))>(n, make_vec(ts...)); }
template<typename T> inline int sz(T &x) { return x.size(); }
template<typename T> inline bool chmin(T &a, T b) { if (a > b) { a = b; return true; } return false; }
template<typename T> inline bool chmax(T &a, T b) { if (a < b) { a = b; return true; } return false; }
template<typename T1, typename T2> istream &operator>>(istream &is, pair<T1, T2> &p) { is >> p.first >> p.second; return is; }
template<typename T1, typename T2> ostream &operator<<(ostream &os, const pair<T1, T2> &p) { os << '(' << p.first << ", " << p.second << ')'; return os; }
template<typename T> istream &operator>>(istream &is, vector<T> &v) { for (auto &e : v) is >> e; return is; }
template<typename T> ostream &operator<<(ostream &os, const vector<T> &v) { for (auto &e : v) os << e << ' '; return os; }
template<typename T> inline int count_between(vector<T> &a, T l, T r) { return lower_bound(all(a), r) - lower_bound(all(a), l); } // [l, r)
inline int fLog2(const ll x) { assert(x > 0); return 63-__builtin_clzll(x); } // floor(log2(x))
inline int cLog2(const ll x) { assert(x > 0); return (x == 1) ? 0 : 64-__builtin_clzll(x-1); } // ceil(log2(x))
inline int popcount(const ll x) { return __builtin_popcountll(x); }
inline void fail() { cout << -1 << '\n'; exit(0); }
struct fast_ios { fast_ios(){ cin.tie(nullptr); ios::sync_with_stdio(false); cout << fixed << setprecision(20); }; } fast_ios_;
// const int INF  = 1<<30;
// const ll INFll = 1ll<<60;
// const ld EPS   = 1e-10;
// const ld PI    = acos(-1.0);
const int MOD  = int(1e9)+7;
// const int MOD  = 998244353;


template<int MOD> struct ModInt {
  int x;
  ModInt(ll _x = 0) : x( (0 <= _x && _x < MOD) ? _x : (_x%MOD+MOD)%MOD ) {}
  constexpr int &value() noexcept { return x; }
  constexpr ModInt operator-() const noexcept { return ModInt(MOD-x); }
  constexpr ModInt operator+(const ModInt y) const noexcept { return ModInt(*this) += y; }
  constexpr ModInt operator-(const ModInt y) const noexcept { return ModInt(*this) -= y; }
  constexpr ModInt operator*(const ModInt y) const noexcept { return ModInt(*this) *= y; }
  constexpr ModInt operator/(const ModInt y) const noexcept { return ModInt(*this) /= y; }
  constexpr ModInt &operator+=(const ModInt y) noexcept { x += y.x; if (x >= MOD) x -= MOD; return *this; }
  constexpr ModInt &operator-=(const ModInt y) noexcept { x -= y.x; if (x < 0) x += MOD; return *this; }
  constexpr ModInt &operator*=(const ModInt y) noexcept { x = ll(x) * y.x % MOD; return *this; }
  constexpr ModInt &operator/=(const ModInt y) {
    int a = y.x, b = MOD, u = 1, v = 0;
    while (b) {
      int t = a / b;
      a -= t * b; swap(a, b);
      u -= t * v; swap(u, v);
    }
    x = ll(x) * u % MOD;
    if (x < 0) x += MOD;
    return *this;
  }
  constexpr ModInt pow(ll n) const noexcept {
    ModInt x(1);
    ModInt a = *this;
    for (; n > 0; n >>= 1, a *= a) if (n&1) x *= a;
    return x;
  }
};
using mint = ModInt<MOD>;
using Vm = vector<mint>;
// using VVm = vector<Vm>;
// using VVVm = vector<VVm>;
istream &operator>>(istream &is, mint &a) { return is >> a.x; }
ostream &operator<<(ostream &os, const mint &a) { return os << a.x; }


int main() {
  ll n; cin >> n;
  Vm a(n); cin >> a;

  mint sum = 0;
  rep(i, n) sum += a[i];

  mint ans = sum * sum;
  
  rep(i, n) ans -= a[i] * a[i];
  ans /= 2;

  cout << ans << '\n';
}
