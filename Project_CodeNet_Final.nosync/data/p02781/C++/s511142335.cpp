#include <bits/stdc++.h>
using namespace std;
#define rep2(i, m, n) for (int i = (m); i < (n); ++i)
#define rep(i, n) rep2(i, 0, n)
#define drep2(i, m, n) for (int i = (m)-1; i >= (n); --i)
#define drep(i, n) drep2(i, n, 0)
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#ifdef LOCAL
void debug_out() { cerr << endl; }
template <typename Head, typename... Tail> void debug_out(Head H, Tail... T) { cerr << ' ' << H; debug_out(T...); }
#define debug(...) cerr << 'L' << __LINE__ << " [" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)
#define dump(x) cerr << 'L' << __LINE__ << " " << #x << " = " << (x) << endl
#else
#define debug(...) (void(0))
#define dump(x) (void(0))
#endif
template<typename T> using V = vector<T>;
template<typename T, typename U> using P = pair<T, U>;
using ll = long long;
using ld = long double;
using Vi = V<int>;  using VVi = V<Vi>;
using Vl = V<ll>;   using VVl = V<Vl>;
using Vd = V<ld>;   using VVd = V<Vd>;
using Vb = V<bool>; using VVb = V<Vb>;
using Pi = P<int, int>;
using Pl = P<ll, ll>;
using Pd = P<ld, ld>;
template<typename T> using priority_queue_rev = priority_queue<T, vector<T>, greater<T>>;
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
inline ll cDiv(const ll x, const ll y) { return (x+y-1) / y; } // ceil(x/y)
inline int fLog2(const ll x) { assert(x > 0); return 63-__builtin_clzll(x); } // floor(log2(x))
inline int cLog2(const ll x) { assert(x > 0); return (x == 1) ? 0 : 64-__builtin_clzll(x-1); } // ceil(log2(x))
inline int popcount(const ll x) { return __builtin_popcountll(x); }
inline void fail() { cout << -1 << '\n'; exit(0); }
struct fast_ios { fast_ios(){ cin.tie(nullptr); ios::sync_with_stdio(false); cout << fixed << setprecision(20); }; } fast_ios_;
// const int INF  = 1<<30;
// const ll INFll = 1ll<<60;
// const ld EPS   = 1e-10;
// const ld PI    = acos(-1.0);
// const int MOD  = int(1e9)+7;
// const int MOD  = 998244353;


int main() {
  string s; cin >> s;
  int k; cin >> k;

  VVi dp(2, Vi(k+1));
  dp[0][0] = 1;

  for (auto c : s) {
    VVi tmp(2, Vi(k+1));
    int x = c - '0';
    rep(sm, 2) rep(i, k+1) rep(y, 10) {
      int sm2 = sm;
      int i2 = i;
      if (!sm && (y > x)) continue;
      if (y < x) sm2 = 1;
      if (y != 0) ++i2;
      if (i2 > k) continue;
      tmp[sm2][i2] += dp[sm][i];
    }
    swap(dp, tmp);
    dump(dp);
  }
  cout << (dp[0][k] + dp[1][k]) << '\n';
}
