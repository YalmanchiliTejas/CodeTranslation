#include <bits/stdc++.h>
#define REP(i, n) for (int i = 0, max_i = (n); i < max_i; i++)
#define REPI(i, a, b) for (int i = (a), max_i = (b); i < max_i; i++)
#define ALL(obj) (obj).begin(), (obj).end()
#define RALL(obj) (obj).rbegin(), (obj).rend()
#define fi first
#define se second
#define int long long
using namespace std;
using ll = long long;
using II = pair<int, int>; using VII = vector<II>; using VVII = vector<VII>;
using VI = vector<int>; using VVI = vector<VI>; using VVVI = vector<VVI>;
template <class T> using V = vector<T>; template <class T> using VV = V<V<T>>; template <class T> using VVV = V<VV<T>>;
template <class T = int> inline bool chmax(T &a, const T &b) { if (a < b) { a = b; return true; } return false; }
template <class T = int> inline bool chmin(T &a, const T &b) { if (a > b) { a = b; return true; } return false; }
template <class T> ostream& operator<<(ostream &s, const vector<T>& d) { REP (i, d.size()) s << d[i] << (i == d.size() - 1 ? "" : " "); return s; }
template <class T> ostream& operator<<(ostream &s, const vector<vector<T>>& d) { REP (i, d.size()) s << d[i] << (i == d.size() - 1 ? "" : "\n"); return s; }
template <class T, class S> ostream& operator<<(ostream &s, const pair<T, S>& p) { s << "{" << p.first << ", " << p.second << "}"; return s; }
template <class T, class S> ostream& operator<<(ostream& s, const map<T, S> m) { for (auto it = m.begin(); it != m.end(); it++) { s << *it << (next(it) == m.end() ? "" : "\n"); } return s; }
#ifdef _MY_DEBUG
  #define dump(...) cerr << "/* " << #__VA_ARGS__ << " :[" << __LINE__ << ":" << __FUNCTION__ << "]" << endl, dump_func(__VA_ARGS__), cerr << "*/\n\n";
#else
  #define dump(...)
#endif
void dump_func() { cerr << endl; }
template <class Head, class... Tail> void dump_func(Head&& h, Tail&&... t) { cerr << h << (sizeof...(Tail) == 0 ? "" : ", "), dump_func(forward<Tail>(t)...); }
struct Fast { Fast() { cin.tie(0); ios::sync_with_stdio(false); } } fast;
constexpr int MOD = 1e9 + 7;

template <class T>
T pow(T x, int n) {
  T ret = 1;
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
  ModInt inv() const { return pow(*this, MD - 2); }
  friend ostream& operator<<(ostream& s, ModInt<MD> a) { s << a.x; return s; }
};
using mint = ModInt<MOD>;

signed main() {
  string K; cin >> K;
  int n = K.size();
  int D; cin >> D;
  VVV<mint> dp(n + 1, VV<mint>(2, V<mint>(D)));
  dp[0][0][0] = 1;
  REP (i, n) {
    REP (j, 2) {
      REP (k, D) {
        int c = K[i] - '0';
        REP (d, (j ? 9 : c) + 1) {
          dp[i + 1][j | d < c][(k + d) % D] += dp[i][j][k];
        }
      }
    }
  }
  cout << dp[n][0][0] + dp[n][1][0] - 1 << endl;
}
