#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
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
template<typename T> using P = pair<T, T>;
using ll = long long;
using ld = long double;
using Vi = V<int>;  using VVi = V<Vi>;
using Vl = V<ll>;   using VVl = V<Vl>;
using Vd = V<ld>;   using VVd = V<Vd>;
using Vb = V<bool>; using VVb = V<Vb>;
using Pi = P<int>;
using Pl = P<ll>;
using Pd = P<ld>;
template<typename T> using priority_queue_rev = priority_queue<T, vector<T>, greater<T>>;
template<typename T> vector<T> make_vec(size_t n, T a) { return vector<T>(n, a); }
template<typename... Ts> auto make_vec(size_t n, Ts... ts) { return vector<decltype(make_vec(ts...))>(n, make_vec(ts...)); }
template<typename T> inline int sz(T &x) { return x.size(); }
template<typename T> inline bool chmin(T &a, T b) { if (a > b) { a = b; return true; } return false; }
template<typename T> inline bool chmax(T &a, T b) { if (a < b) { a = b; return true; } return false; }
template<typename T1, typename T2> istream &operator>>(istream &is, pair<T1, T2> &p) { is >> p.first >> p.second; return is; }
template<typename T1, typename T2> ostream &operator<<(ostream &os, const pair<T1, T2> &p) { os << '(' << p.first << ", " << p.second << ')'; return os; }
// template<typename T, int n> istream &operator>>(istream &is, array<T, n> &v) { rep(i, n) is >> v[i]; return is; }
// template<typename T, int n> ostream &operator<<(ostream &os, const array<T, n> &v) { for (auto &e : v) os << e << ' '; return os; }
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


int op(int x, int y) {
  return max(x, y);
}

int e() {
  return -1;
}

int v;

bool f(int x) {
  return x < v;
}



int main() {
  int n, q; cin >> n >> q;
  Vi a(n); cin >> a;

  segtree<int, op, e> sg(a);

  rep(_, q) {
    int t; cin >> t;
    if (t == 1) {
      int x; cin >> x >> v;
      --x;
      sg.set(x, v);
    }
    else if (t == 2) {
      int l, r; cin >> l >> r;
      --l;
      cout << sg.prod(l, r) << '\n';
    }
    else {
      int x; cin >> x >> v;
      --x;
      cout << sg.max_right<f>(x)+1 << '\n';
    }
  }
}