#include <bits/stdc++.h>
using namespace std;
#define int long long
#define REP(i, n) for (long long i = 0, max_i = (n); i < max_i; i++)
#define REPI(i, a, b) for (long long i = (a), max_i = (b); i < max_i; i++)
#define ALL(obj) begin(obj), end(obj)
#define RALL(obj) rbegin(obj), rend(obj)
#define fi first
#define se second
using ii = pair<int, int>;
vector<ii> dirs = {
  {1, 0}, {0, 1}, {-1, 0}, {0, -1},  // 4方向
  {1, 1}, {-1, 1}, {-1, -1}, {1, -1},  // 斜め
  {0, 0},  // 自身
};
template <class T> inline bool chmax(T& a, const T& b) { if (a < b) { a = b; return true; } return false; }
template <class T> inline bool chmin(T& a, const T& b) { if (a > b) { a = b; return true; } return false; }

// debug
template <class T> ostream& operator<<(ostream& s, vector<T>& d) { REP (i, d.size()) s << d[i] << (i == d.size() - 1 ? "" : " "); return s; }
template <class T> ostream& operator<<(ostream& s, vector<vector<T>>& d) { REP (i, d.size()) s << d[i] << (i == d.size() - 1 ? "" : "\n"); return s; }
template <class T, class S> ostream& operator<<(ostream& s, pair<T, S>& p) { s << "{" << p.first << ", " << p.second << "}"; return s; }
template <class T, class S> ostream& operator<<(ostream& s, map<T, S> m) { for (auto it = m.begin(); it != m.end(); it++) { s << *it << (next(it) == m.end() ? "" : "\n"); } return s; }
#ifdef _MY_DEBUG
  #define dump(...) cerr << "/* " << #__VA_ARGS__ << " :[" << __LINE__ << ":" << __FUNCTION__ << "]" << endl, dump_func(__VA_ARGS__), cerr << "*/\n\n";
#else
  #define dump(...)
  #define endl "\n"
#endif
void dump_func() { cerr << endl; }
template <class Head, class... Tail> void dump_func(Head&& h, Tail&&... t) { cerr << h << (sizeof...(Tail) == 0 ? "" : ", "), dump_func(forward<Tail>(t)...); }

struct Fast { Fast() { cin.tie(0); ios::sync_with_stdio(false); } } fast;
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
constexpr int MOD = 1000000007;
// *************** TEMPLATE END *************** 

template <class T>
T pow(T x, int n, const T UNION = 1) {
  T ret = UNION;
  while (n) {
    if (n & 1) ret *= x;
    x *= x; n >>= 1;
  }
  return ret;
}

template <int MD>
struct ModInt {
  int x;
  ModInt() : x(0) {}
  ModInt(int x_) { if ((x = x_ % MD + MD) >= MD) x -= MD; }

  ModInt& operator+=(ModInt that) { if ((x += that.x) >= MD) x -= MD; return *this; }
  ModInt& operator*=(ModInt that) { x = (unsigned long long)x * that.x % MD; return *this; }
  ModInt& operator-=(ModInt that) { if ((x -= that.x) < 0) x += MD; return *this; }
  ModInt& operator/=(ModInt that) { x = (unsigned long long)x * that.inv().x % MD; return *this; }

  ModInt operator-() const { return -x < 0 ? MD - x : -x; }
  ModInt operator+(ModInt that) const { return ModInt(*this) += that; }
  ModInt operator*(ModInt that) const { return ModInt(*this) *= that; }
  ModInt operator-(ModInt that) const { return ModInt(*this) -= that; }
  ModInt operator/(ModInt that) const { return ModInt(*this) /= that; }
  bool operator==(ModInt that) const { return x == that.x; }
  bool operator!=(ModInt that) const { return x != that.x; }
  ModInt inv() const { return pow(*this, MD - 2); }
  friend ostream& operator<<(ostream& s, ModInt<MD> a) { s << a.x; return s; }
  friend istream& operator>>(istream& s, ModInt<MD>& a) { s >> a.x; return s; }
};
using mint = ModInt<MOD>;

vector<mint> fact, fact_inv;
void init_factorial(int n) {
  fact = vector<mint>(n + 1, 1);
  fact_inv = vector<mint>(n + 1);
  for (int i = 0; i < n; i++) fact[i + 1] = fact[i] * (i + 1);
  fact_inv[n] = mint(1) / fact[n];
  for (int i = n - 1; i >= 0; i--) fact_inv[i] = fact_inv[i + 1] * (i + 1);
  // for (int i = 0; i < n + 1; i++) assert(fact[i] * fact_inv[i] == 1);
}
mint comb(int n, int r) {
  return fact[n] * fact_inv[r] * fact_inv[n - r];
}

signed main() {
  int n, A, B, C, D; cin >> n >> A >> B >> C >> D;
  init_factorial(n);

  vector<vector<mint>> dp(n + 2, vector<mint>(n + 1));
  dp[A][n] = 1;
  REPI (x, A, B + 1) {
    REP (y, n + 1) {
      if (dp[x][y] == 0) continue;
      for (int k = 0; k <= D; k = k == 0 ? C : k + 1) {
        if (y - k * x < 0) break;
        dp[x + 1][y - k * x] += dp[x][y] * comb(y, k * x) * fact[k * x] / (pow(fact[x], k) * fact[k]);
      }
    }
  }
  cout << dp[B + 1][0] << endl;
}
