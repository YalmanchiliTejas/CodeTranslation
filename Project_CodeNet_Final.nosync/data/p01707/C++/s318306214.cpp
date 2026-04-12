// clang-format off
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define main signed main()
#define loop(i, a, n) for (int i = (a); i < (n); i++)
#define rep(i, n) loop(i, 0, n)
#define all(v) (v).begin(), (v).end()
#define rall(v) (v).rbegin(), (v).rend()
#define prec(n) fixed << setprecision(n)
constexpr int INF = sizeof(int) == sizeof(long long) ? 1000000000000000000LL : 1000000000;
constexpr int MOD = 1000000007;
constexpr double PI = 3.14159265358979;
template<typename A, typename B> bool cmin(A &a, const B &b) { return a > b ? (a = b, true) : false; }
template<typename A, typename B> bool cmax(A &a, const B &b) { return a < b ? (a = b, true) : false; }
bool odd(const int &n) { return n & 1; }
bool even(const int &n) { return ~n & 1; }
template<typename T = int> T in() { T x; cin >> x; return x; }
template<typename T = int> T in(T &&x) { T z(forward<T>(x)); cin >> z; return z; }
template<typename T> istream &operator>>(istream &is, vector<T> &v) { for (T &x : v) is >> x; return is; }
template<typename A, typename B> istream &operator>>(istream &is, pair<A, B> &p) { return is >> p.first >> p.second; }
template<typename T> ostream &operator<<(ostream &os, const vector<vector<T>> &v) { int n = v.size(); rep(i, n) os << v[i] << (i == n - 1 ? "" : "\n"); return os; }
template<typename T> ostream &operator<<(ostream &os, const vector<T> &v) { int n = v.size(); rep(i, n) os << v[i] << (i == n - 1 ? "" : " "); return os; }
template<typename A, typename B> ostream &operator<<(ostream &os, const pair<A, B> &p) { return os << p.first << ' ' << p.second; }
template<typename Head, typename Value> auto vectors(const Head &head, const Value &v) { return vector<Value>(head, v); }
template<typename Head, typename... Tail> auto vectors(Head x, Tail... tail) { auto inner = vectors(tail...); return vector<decltype(inner)>(x, inner); }
// clang-format on

template<int mod> struct modint {
  int v;
  modint(int a = 0) : v(((a % mod) + mod) % mod) {}
  modint operator+(const modint<mod> &b) const { return (v + b.v) % mod; }
  modint operator-(const modint<mod> &b) const { return (v - b.v + mod) % mod; }
  modint operator*(const modint<mod> &b) const { return (v * b.v) % mod; }
  modint operator/(const modint<mod> &b) const { return (v * b.inv().v) % mod; }
  modint<mod> inv() const { return pow(mod - 2); }
  modint<mod> pow(int t) const {
    modint e = v, c = 1;
    while (t) {
      if (t & 1) c *= e;
      t >>= 1;
      e *= e;
    }
    return c;
  }
  explicit operator int() { return v; }
  friend bool operator==(const modint<mod> &a, const modint<mod> &b) { return a.v == b.v; }
  friend bool operator!=(const modint<mod> &a, const modint<mod> &b) { return a.v != b.v; }
  friend modint<mod> &operator+=(modint<mod> &a, const modint<mod> &b) { return a = a + b; }
  friend modint<mod> &operator-=(modint<mod> &a, const modint<mod> &b) { return a = a - b; }
  friend modint<mod> &operator*=(modint<mod> &a, const modint<mod> &b) { return a = a * b; }
  friend modint<mod> &operator/=(modint<mod> &a, const modint<mod> &b) { return a = a / b; }
  friend ostream &operator<<(ostream &os, const modint<mod> &a) { return os << a.v; }
  friend istream &operator>>(istream &is, modint<mod> &a) {
    int w;
    is >> w;
    a = w;
    return is;
  }
};

main {
  while (true) {
    int n, d, x;
    cin >> n >> d >> x;
    if (n == 0 && d == 0 && x == 0) break;
    auto dp = vectors(n + 1, n + 1, modint<MOD>(0));
    dp[0][0] = 1;
    rep(i, n) loop(j, i, n) {
      dp[i + 1][j + 1] = dp[i + 1][j] + dp[i][j];
      if (j - x + 1 >= 0) dp[i + 1][j + 1] -= dp[i][j - x + 1];
    }
    modint<MOD> cnt = 0;
    for (int i = 1; i <= min(n, d); i++) {
      modint<MOD> c = dp[i][n];
      rep(j, i) c *= modint<MOD>(d - j) / modint<MOD>(j + 1);
      cnt += c;
    }
    cout << cnt << endl;
  }
}

