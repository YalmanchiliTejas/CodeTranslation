#include <bits/stdc++.h>
// #include <boost/multiprecision/cpp_int.hpp>
// using i128 = boost::multiprecision::int128_t;
#define _GLIBCXX_DEBUG
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
using VVV = vector<VV>;
using VVVll = vector<VVll>;
using P = pair<int, int>;
using Pll = pair<ll, ll>;
using Pld = pair<ld, ld>;
#define rep2(i, m, n) for(int i=int(m); i<int(n); ++i)
#define drep2(i, m, n) for(int i=int(m)-1; i>=int(n); --i)
#define rep(i, n) rep2(i, 0, n)
#define drep(i, n) drep2(i, n, 0)
#define all(a) a.begin(), a.end()
struct fast_ios { fast_ios(){ cin.tie(nullptr); ios::sync_with_stdio(false); cout << fixed << setprecision(20); }; } fast_ios_;
template<typename T> inline int sz(T &x) { return x.size(); }
template<typename T> inline bool chmin(T &a, T b) { if (a > b) { a = b; return true; } return false; }
template<typename T> inline bool chmax(T &a, T b) { if (a < b) { a = b; return true; } return false; }
template<typename T1, typename T2> istream &operator>>(istream &is, pair<T1, T2> &p) { is >> p.first >> p.second; return is; }
template<typename T1, typename T2> ostream &operator<<(ostream &os, const pair<T1, T2> &p) { os << "(" << p.first << ", " << p.second << ")"; return os; }
template<typename T> istream &operator>>(istream &is, vector<T> &v) { for (auto &e : v) is >> e; return is; }
template<typename T> ostream &operator<<(ostream &os, const vector<T> &v) { for (auto &e : v) os << e << " "; return os; }
template<typename T> inline int count_between(vector<T> &a, T l, T r) { return lower_bound(all(a), r) - lower_bound(all(a), l); } // [l, r)
inline int fLog2(const int x) { return 31-__builtin_clz(x); } // floor(log2(x))
inline int fLog2(const ll x) { return 63-__builtin_clzll(x); }
inline int cLog2(const int x) { return (x == 1) ? 0 : 32-__builtin_clz(x-1); } // ceil(log2(x))
inline int cLog2(const ll x) { return (x == 1) ? 0 : 64-__builtin_clzll(x-1); }
inline int popcount(const int x) { return __builtin_popcount(x); }
inline int popcount(const ll x) { return __builtin_popcountll(x); }
const int INF  = 1<<30;
const ll INFll = 1ll<<62;
const ld EPS   = 1e-10;
const ld PI    = acos(-1.0);
const int MOD  = int(1e9)+7;
// const int MOD  = 998244353;


VV G;

void ok() {
  cout << "First\n";
  exit(0);
}

int dfs(int u, int p=-1) {
  int cnt = 0;
  for (int v : G[u]) if (v != p) {
    if (dfs(v, u)) ++cnt;
  }
  if (cnt > 1) ok();
  return cnt^1;
}


int main() {
  int n; cin >> n;

  G.assign(n, V());
  rep(i, n-1) {
    int a, b; cin >> a >> b;
    --a; --b;
    G[a].push_back(b);
    G[b].push_back(a);
  }

  if (dfs(0)) ok();
  cout << "Second\n";
  return 0;
}
