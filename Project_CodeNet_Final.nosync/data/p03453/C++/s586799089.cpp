#include <bits/stdc++.h>
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
#define rep2(i, m, n) for (int i = (m); i < (n); ++i)
#define drep2(i, m, n) for (int i = (m)-1; i >= (n); --i)
#define rep(i, n) rep2(i, 0, n)
#define drep(i, n) drep2(i, n, 0)
#define all(a) (a).begin(), (a).end()
struct fast_ios { fast_ios(){ cin.tie(nullptr); ios::sync_with_stdio(false); cout << fixed << setprecision(20); }; } fast_ios_;
template<typename T> inline int sz(T &x) { return x.size(); }
template<typename T> inline bool chmin(T &a, T b) { if (a > b) { a = b; return true; } return false; }
template<typename T> inline bool chmax(T &a, T b) { if (a < b) { a = b; return true; } return false; }
template<typename T1, typename T2> istream &operator>>(istream &is, pair<T1, T2> &p) { is >> p.first >> p.second; return is; }
template<typename T1, typename T2> ostream &operator<<(ostream &os, const pair<T1, T2> &p) { os << '(' << p.first << ", " << p.second << ')'; return os; }
template<typename T> istream &operator>>(istream &is, vector<T> &v) { for (auto &e : v) is >> e; return is; }
template<typename T> ostream &operator<<(ostream &os, const vector<T> &v) { for (auto &e : v) os << e << ' '; return os; }
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


struct mint {
  ll x;
  mint(ll x=0) : x((x%MOD+MOD)%MOD) {}
  mint operator-() const { return mint(-x);}
  mint& operator+=(const mint a) { if ((x += a.x) >= MOD) x -= MOD; return *this; }
  mint& operator-=(const mint a) { if ((x -= a.x) < 0) x += MOD; return *this; }
  mint& operator*=(const mint a) { (x *= a.x) %= MOD; return *this; }
  mint operator+(const mint a) const { return mint(*this) += a; }
  mint operator-(const mint a) const { return mint(*this) -= a; }
  mint operator*(const mint a) const { return mint(*this) *= a; }
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
  mint operator/(const mint a) const { return mint(*this) /= a; }
};
// istream& operator>>(istream& is, mint& a) { return is >> a.x; }
ostream& operator<<(ostream& os, const mint& a) { return os << a.x; }
using Vm = vector<mint>;
using VVm = vector<Vm>;
using VVVm = vector<VVm>;



template<typename T>
struct edge {
  int v; T w;
  edge(int v, T w) : v(v), w(w) {}
};
template<typename T>
using Graph = vector<vector<edge<T>>>;


template<typename T>
pair<vector<T>, Vm> dijkstra(Graph<T> &G, int s) {
  int n = G.size();
  const auto INF_T = numeric_limits<T>::max();
  vector<T> dist(n, INF_T);
  using PTi = pair<T, int>;
  priority_queue<PTi, vector<PTi>, greater<PTi>> pq;

  dist[s] = 0;
  pq.emplace(dist[s], s);

  Vm cnt(n);
  cnt[s] = 1;
  
  while (!pq.empty()) {
    auto [d, u] = pq.top(); pq.pop();
    if (dist[u] < d) continue;
    for (auto &[v, w] : G[u]) {
      if (dist[v] == d+w) cnt[v] += cnt[u];
      if (chmin(dist[v], d+w)) {
        cnt[v] = cnt[u];
        pq.emplace(dist[v], v);
      }
    }
  }
  return {move(dist), move(cnt)};
}


int main() {
  int n, m; cin >> n >> m;
  int s, t; cin >> s >> t;
  --s, --t;

  Graph<ll> G(n);
  rep(_, m) {
    int u, v, w; cin >> u >> v >> w;
    --u, --v;
    G[u].emplace_back(v, w);
    G[v].emplace_back(u, w);
  }

  auto [dist_s, cnt_s] = dijkstra(G, s);
  auto [dist_t, cnt_t] = dijkstra(G, t);

  ll st = dist_s[t];
  mint ans = cnt_s[t] * cnt_s[t];

  rep(u, n) for (auto &[v, w] : G[u]) {
    if (dist_s[u] + w + dist_t[v] != st) continue;
    if (2*dist_s[u] < st && 2*dist_t[v] < st) {
      ans -= (cnt_s[u] * cnt_t[v]).pow(2);
    }
  }
  rep(u, n) {
    if (dist_s[u] + dist_t[u] != st) continue;
    if (2*dist_s[u] == st) {
      ans -= (cnt_s[u] * cnt_t[u]).pow(2);
    }
  }
  cout << ans << '\n';
  return 0;
}