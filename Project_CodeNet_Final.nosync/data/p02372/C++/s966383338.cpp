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
template<typename T> int len(const T &v) { return v.size(); }
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

using Weight = int;
struct Edge {
  int src, dst;
  Weight weight;
  Edge(const int &s = 0, const int &d = 0, const Weight &w = 0) : src(s), dst(d), weight(w) {}
};

using Edges = vector<Edge>;
using Array = vector<Weight>;
using Matrix = vector<Array>;

class Graph {
  vector<Edges> g;

public:
  Graph(const int &size = 0) : g(size) {}
  size_t size() const { return g.size(); }
  const Edges &operator[](const int &i) const { return g[i]; }
  Edges &operator[](const int &i) { return g[i]; }
  void addArc(const int &src, const int &dst, const Weight &w = 1) { g[src].emplace_back(src, dst, w); }
  void addEdge(const int &node1, const int &node2, const Weight &w = 1) {
    addArc(node1, node2, w);
    addArc(node2, node1, w);
  }
  auto begin() { return g.begin(); }
  auto end() { return g.end(); }
};

vector<Weight> treeHeight(const Graph &g) {
  int n = g.size();
  vector<vector<int>> dp(n);
  rep(i, n) dp[i].assign(g[i].size(), -1);
  function<Weight(int, int)> dfs = [&](int i, int j) {
    if (dp[i][j] != -1) return dp[i][j];
    dp[i][j] = g[i][j].weight;
    int u = g[i][j].dst;
    rep(k, g[u].size()) {
      if (g[u][k].dst == i) continue;
      cmax(dp[i][j], g[i][j].weight + dfs(u, k));
    }
    return dp[i][j];
  };
  rep(i, n) rep(j, g[i].size()) if (dp[i][j] == -1) dp[i][j] = dfs(i, j);
  vector<Weight> hs(n);
  rep(i, n) {
    dp[i].emplace_back(0);
    hs[i] = *max_element(all(dp[i]));
  }
  return hs;
}

main {
  int n = in();
  Graph g(n);
  rep(i, n - 1) {
    int a, b, c;
    cin >> a >> b >> c;
    g.addEdge(a, b, c);
  }
  auto hs = treeHeight(g);
  for (auto &h : hs) cout << h << endl;
}

