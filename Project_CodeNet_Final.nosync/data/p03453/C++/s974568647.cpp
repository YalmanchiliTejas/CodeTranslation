#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;
#define FOR(i,m,n) for(int i=(m);i<(n);++i)
#define REP(i,n) FOR(i,0,n)
#define ALL(v) (v).begin(),(v).end()
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fLL;
const double EPS = 1e-8;
const int MOD = 1000000007;
// const int MOD = 998244353;
const int dy[] = {1, 0, -1, 0}, dx[] = {0, -1, 0, 1};
const int dy8[] = {1, 1, 0, -1, -1, -1, 0, 1}, dx8[] = {0, -1, -1, -1, 0, 1, 1, 1};
template <typename T, typename U> inline bool chmax(T &a, U b) { return a < b ? (a = b, true) : false; }
template <typename T, typename U> inline bool chmin(T &a, U b) { return a > b ? (a = b, true) : false; }
struct IOSetup {
  IOSetup() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    cout << fixed << setprecision(20);
  }
} iosetup;

using CostType = int;
struct Edge {
  int src, dst; CostType cost;
  Edge(int src, int dst, CostType cost) : src(src), dst(dst), cost(cost) {}
  inline bool operator<(const Edge &x) const {
    return cost != x.cost ? cost < x.cost : dst != x.dst ? dst < x.dst : src < x.src;
  }
  inline bool operator<=(const Edge &x) const { return !(x < *this); }
  inline bool operator>(const Edge &x) const { return x < *this; }
  inline bool operator>=(const Edge &x) const { return !(*this < x); }
};

int mod = MOD;
struct ModInt {
  unsigned val;
  ModInt(): val(0) {}
  ModInt(ll x) : val(x >= 0 ? x % mod : x % mod + mod) {}
  ModInt pow(ll exponent) {
    ModInt tmp = *this, res = 1;
    while (exponent > 0) {
      if (exponent & 1) res *= tmp;
      tmp *= tmp;
      exponent >>= 1;
    }
    return res;
  }
  ModInt &operator+=(const ModInt &x) { if((val += x.val) >= mod) val -= mod; return *this; }
  ModInt &operator-=(const ModInt &x) { if((val += mod - x.val) >= mod) val -= mod; return *this; }
  ModInt &operator*=(const ModInt &x) { val = static_cast<unsigned long long>(val) * x.val % mod; return *this; }
  ModInt &operator/=(const ModInt &x) {
    // assert(__gcd(static_cast<int>(x.val), mod) == 1);
    unsigned a = x.val, b = mod; int u = 1, v = 0;
    while (b) {
      unsigned tmp = a / b;
      swap(a -= tmp * b, b);
      swap(u -= tmp * v, v);
    }
    return *this *= u;
  }
  bool operator==(const ModInt &x) const { return val == x.val; }
  bool operator!=(const ModInt &x) const { return val != x.val; }
  bool operator<(const ModInt &x) const { return val < x.val; }
  bool operator<=(const ModInt &x) const { return val <= x.val; }
  bool operator>(const ModInt &x) const { return val > x.val; }
  bool operator>=(const ModInt &x) const { return val >= x.val; }
  ModInt &operator++() { if (++val == mod) val = 0; return *this; }
  ModInt operator++(int) { ModInt res = *this; ++*this; return res; }
  ModInt &operator--() { val = (val == 0 ? mod : val) - 1; return *this; }
  ModInt operator--(int) { ModInt res = *this; --*this; return res; }
  ModInt operator+() const { return *this; }
  ModInt operator-() const { return ModInt(val ? mod - val : 0); }
  ModInt operator+(const ModInt &x) const { return ModInt(*this) += x; }
  ModInt operator-(const ModInt &x) const { return ModInt(*this) -= x; }
  ModInt operator*(const ModInt &x) const { return ModInt(*this) *= x; }
  ModInt operator/(const ModInt &x) const { return ModInt(*this) /= x; }
  friend ostream &operator<<(ostream &os, const ModInt &x) { return os << x.val; }
  friend istream &operator>>(istream &is, ModInt &x) { ll val; is >> val; x = ModInt(val); return is; }
};
ModInt abs(const ModInt &x) { return x; }
struct Combinatorics {
  int val; // "val!" and "mod" must be disjoint.
  vector<ModInt> fact, fact_inv, inv;
  Combinatorics(int val = 10000000) : val(val), fact(val + 1), fact_inv(val + 1), inv(val + 1) {
    fact[0] = 1;
    FOR(i, 1, val + 1) fact[i] = fact[i - 1] * i;
    fact_inv[val] = ModInt(1) / fact[val];
    for (int i = val; i > 0; --i) fact_inv[i - 1] = fact_inv[i] * i;
    FOR(i, 1, val + 1) inv[i] = fact[i - 1] * fact_inv[i];
  }
  ModInt nCk(int n, int k) {
    if (n < 0 || n < k || k < 0) return ModInt(0);
    // assert(n <= val && k <= val);
    return fact[n] * fact_inv[k] * fact_inv[n - k];
  }
  ModInt nPk(int n, int k) {
    if (n < 0 || n < k || k < 0) return ModInt(0);
    // assert(n <= val);
    return fact[n] * fact_inv[n - k];
  }
  ModInt nHk(int n, int k) {
    if (n < 0 || k < 0) return ModInt(0);
    return (k == 0 ? ModInt(1) : nCk(n + k - 1, k));
  }
};

int main() {
  int n, m, s, t; cin >> n >> m >> s >> t; --s; --t;
  vector<vector<Edge> > graph(n);
  while (m--) {
    int u, v, d; cin >> u >> v >> d; --u; --v;
    graph[u].emplace_back(u, v, d);
    graph[v].emplace_back(v, u, d);
  }
  using P = pair<ll, int>;
  priority_queue<P, vector<P>, greater<P> > que;
  vector<ll> dist2(n, LINF);
  dist2[t] = 0;
  vector<ModInt> pat2(n, 0);
  pat2[t] = 1;
  que.emplace(0, t);
  while (!que.empty()) {
    ll c; int ver; tie(c, ver) = que.top(); que.pop();
    if (c > dist2[ver]) continue;
    for (const Edge &e : graph[ver]) {
      ll cost = c + e.cost;
      if (cost < dist2[e.dst]) {
        dist2[e.dst] = cost;
        pat2[e.dst] = pat2[ver];
        que.emplace(dist2[e.dst], e.dst);
      } else if (cost == dist2[e.dst]) {
        pat2[e.dst] += pat2[ver];
      }
    }
  }
  vector<ll> dist(n, LINF);
  dist[s] = 0;
  vector<ModInt> pat(n, 0);
  pat[s] = 1;
  que.emplace(0, s);
  while (!que.empty()) {
    ll c; int ver; tie(c, ver) = que.top(); que.pop();
    if (c > dist[ver]) continue;
    for (const Edge &e : graph[ver]) {
      ll cost = c + e.cost;
      if (cost < dist[e.dst]) {
        dist[e.dst] = cost;
        pat[e.dst] = pat[ver];
        que.emplace(dist[e.dst], e.dst);
      } else if (cost == dist[e.dst]) {
        pat[e.dst] += pat[ver];
      }
    }
  }
  ModInt ans = pat[t] * pat2[s];
  ll shortest = dist[t];
  REP(i, n) {
    if (dist[i] * 2 == shortest && dist2[i] * 2 == shortest) ans -= (pat[i] * pat2[i]).pow(2);
  }
  REP(i, n) {
    for (const Edge &e : graph[i]) {
      if (dist[i] + e.cost == dist[e.dst] && dist2[e.dst] + e.cost == dist2[i] && dist[i] * 2 < shortest && shortest < dist[e.dst] * 2 && dist2[e.dst] * 2 < shortest && shortest < dist2[i] * 2 && dist[i] + e.cost + dist2[e.dst] == shortest) {
        ans -= (pat[i] * pat2[e.dst]).pow(2);
      }
    }
  }
  cout << ans << '\n';
  return 0;
}
