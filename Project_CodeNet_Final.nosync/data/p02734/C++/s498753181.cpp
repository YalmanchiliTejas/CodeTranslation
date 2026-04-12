#pragma region template
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using ld = long double;
using vi = vector<int>;
using vvi = vector<vi>;
using vvvi = vector<vvi>;
using vll = vector<ll>;
using vvll = vector<vll>;
using vvvll = vector<vvll>;
using vld = vector<ld>;
using vvld = vector<vld>;
using vvvld = vector<vvld>;
using vs = vector<string>;
using pll = pair<ll, ll>;
using vp = vector<pll>;
template <typename T>
using pqrev = priority_queue<T, vector<T>, greater<T>>;
#define rep(i, n) for (ll i = 0, i##_end = (n); i < i##_end; i++)
#define repb(i, n) for (ll i = (n)-1; i >= 0; i--)
#define repr(i, a, b) for (ll i = (a), i##_end = (b); i < i##_end; i++)
#define reprb(i, a, b) for (ll i = (b)-1, i##_end = (a); i >= i##_end; i--)
#define ALL(a) (a).begin(), (a).end()
#define SZ(x) ((ll)(x).size())
/*
constexpr ll MOD = 1e9 + 7;
/*/
constexpr ll MOD = 998244353;
//*/
constexpr ll INF = 1e+18;
constexpr ld EPS = 1e-12L;
constexpr ld PI = 3.14159265358979323846L;
constexpr ll GCD(ll a, ll b) { return b ? GCD(b, a % b) : a; }
constexpr ll LCM(ll a, ll b) { return a / GCD(a, b) * b; }
template <typename S, typename T>
inline bool chmax(S &a, const T &b) {
  if (a < b) {
    a = b;
    return 1;
  }
  return 0;
}
template <typename S, typename T>
inline bool chmin(S &a, const T &b) {
  if (b < a) {
    a = b;
    return 1;
  }
  return 0;
}
#ifdef OJ_LOCAL
#include "dump.hpp"
#else
#define dump(...) ((void)0)
#endif
template <typename T>
bool print_(const T &a) {
  cout << a;
  return true;
}
template <typename T>
bool print_(const vector<T> &vec) {
  for (auto &a : vec) {
    cout << a;
    if (&a != &vec.back()) {
      cout << " ";
    }
  }
  return false;
}
template <typename T>
bool print_(const vector<vector<T>> &vv) {
  for (auto &v : vv) {
    for (auto &a : v) {
      cout << a;
      if (&a != &v.back()) {
        cout << " ";
      }
    }
    if (&v != &vv.back()) {
      cout << "\n";
    }
  }
  return false;
}
void print() { cout << "\n"; }
template <typename Head, typename... Tail>
void print(Head &&head, Tail &&... tail) {
  bool f = print_(head);
  if (sizeof...(tail) != 0) {
    cout << (f ? " " : "\n");
  }
  print(forward<Tail>(tail)...);
}
#pragma endregion

// ModInt
// 参考：https://ei1333.github.io/luzhiled/snippets/math/mod-int.html
// modはコンパイル時に決定
template <ll mod>
struct ModInt {
  ll x;
  ModInt() : x(0) {}
  ModInt(ll y) : x(y >= 0 ? y % mod : (mod - (-y) % mod) % mod) {}
  constexpr ModInt &operator+=(const ModInt &p) {
    if ((x += p.x) >= mod)
      x -= mod;
    return *this;
  }
  constexpr ModInt &operator-=(const ModInt &p) {
    if ((x += mod - p.x) >= mod)
      x -= mod;
    return *this;
  }
  constexpr ModInt &operator*=(const ModInt &p) {
    x = x * p.x % mod;
    return *this;
  }
  constexpr ModInt &operator/=(const ModInt &p) {
    *this *= p.inverse();
    return *this;
  }
  constexpr ModInt operator-() { return ModInt(-x); }
  constexpr ModInt operator+(const ModInt &p) { return ModInt(*this) += p; }
  constexpr ModInt operator-(const ModInt &p) { return ModInt(*this) -= p; }
  constexpr ModInt operator*(const ModInt &p) { return ModInt(*this) *= p; }
  constexpr ModInt operator/(const ModInt &p) { return ModInt(*this) /= p; }
  constexpr bool operator==(const ModInt &p) { return x == p.x; }
  constexpr bool operator!=(const ModInt &p) { return x != p.x; }
  constexpr ModInt inverse() const {
    ll a = x, b = mod, u = 1, v = 0, t;
    while (b > 0) {
      t = a / b;
      swap(a -= t * b, b);
      swap(u -= t * v, v);
    }
    return ModInt(u);
  }
  constexpr ModInt pow(ll n) {
    ModInt ret(1), mul(x);
    while (n > 0) {
      if (n & 1)
        ret *= mul;
      mul *= mul;
      n >>= 1;
    }
    return ret;
  }
  friend ostream &operator<<(ostream &os, const ModInt &p) {
    return os << p.x;
  }
  friend istream &operator>>(istream &is, ModInt &a) {
    ll t;
    is >> t;
    a = ModInt<mod>(t);
    return (is);
  }
};

using mint = ModInt<MOD>;
using vm = vector<mint>;
using vvm = vector<vm>;

constexpr int MAX_FAC = 200010;
mint fac[MAX_FAC], facinv[MAX_FAC];
void combInit() {
  fac[0] = mint(1);
  for (int i = 0; i < MAX_FAC - 1; i++) {
    fac[i + 1] = fac[i] * (i + 1);
  }
  facinv[MAX_FAC - 1] = fac[MAX_FAC - 1].inverse();
  for (int i = MAX_FAC - 2; i >= 0; i--) {
    facinv[i] = facinv[i + 1] * (i + 1);
  }
}
mint comb(const ll a, const ll b) {
  assert(a < MAX_FAC);
  assert(b < MAX_FAC);
  if (a < 0 || b < 0 || b > a) {
    return mint(0);
  }
  mint ret(1);
  ret *= fac[a];
  ret *= facinv[b];
  ret *= facinv[a - b];
  return ret;
}
mint multicomb(const ll a, const ll b) {
  return comb(a + b - 1, b);
}

const int N = 3010;
mint dp[N][N];

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  cout << fixed << setprecision(20);
  ll n, s;
  cin >> n >> s;
  vll a(n);
  rep(i, n){
    cin >> a[i];
  }
  rep(i, n) dp[i][0] = 1;
  repr(i, 1, n+1)rep(j, s+1){
    dp[i][j] += dp[i-1][j];
    if(j >= a[i-1]) dp[i][j] += dp[i-1][j-a[i-1]];
  }
  mint ans = 0;
  repr(i, 1, n+1){
    ans += dp[i][s];
  }
  print(ans);
}
