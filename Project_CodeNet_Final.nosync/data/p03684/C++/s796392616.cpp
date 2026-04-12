// clang-format off
#include <bits/stdc++.h>
#define int long long
#define main signed main()
// #define main int main()
#define loop(i, a, n) for (int i = (a); i < (n); i++)
#define rep(i, n) loop(i, 0, n)
#define all(v) (v).begin(), (v).end()
#define rall(v) (v).rbegin(), (v).rend()
#define prec(n) fixed << setprecision(n)
#define stlice(from, to) substr(from, (to) - (from) + 1)
#define pb push_back
#define mp make_pair
#define mt make_tuple
#define fi first
#define se second
using namespace std;
using pii = pair<int, int>;
using vi = vector<int>;
using vd = vector<double>;
using vc = vector<char>;
using vb = vector<bool>;
using vs = vector<string>;
using vpii = vector<pii>;
using vvi = vector<vi>;
using vvb = vector<vb>;
using vvpii = vector<vpii>;
template<typename A> using fn = function<A>;
constexpr int INF = sizeof(int) == sizeof(long long) ? 1000000000000000000LL : 1000000000;
constexpr int MOD = 1000000007;
constexpr double PI = acos(-1);
template<typename A, typename B> bool cmin(A &a, const B &b) { return a > b ? (a = b, true) : false; }
template<typename A, typename B> bool cmax(A &a, const B &b) { return a < b ? (a = b, true) : false; }
constexpr bool odd(const int &n) { return n & 1; }
constexpr bool even(const int &n) { return !odd(n); }
void solve();
main { solve(); return 0; }
// clang-format on

using Weight = int;
struct Edge {
  int src, dst;
  Weight weight;
  Edge(int s, int d, Weight w)
    : src(s), dst(d), weight(w) {
  }
};

using Edges  = vector<Edge>;
using Graph  = vector<Edges>;
using Array  = vector<Weight>;
using Matrix = vector<Array>;

void addEdge(Graph &g, int a, int b, Weight w = 1) {
  g[a].emplace_back(a, b, w);
  g[b].emplace_back(b, a, w);
}

void addArc(Graph &g, int a, int b, Weight w = 1) {
  g[a].emplace_back(a, b, w);
}

class UFT {
private:
  vi data, rnk;

public:
  UFT(const int &size)
    : data(size), rnk(size) {
    iota(all(data), 0);
  }

  int root(const int &x) {
    return data[x] == x ? x : data[x] = root(data[x]);
  }

  bool same(const int &a, const int &b) {
    return root(a) == root(b);
  }

  void unite(int a, int b) {
    a = root(a), b = root(b);
    if (a == b) return;
    if (rnk[a] < rnk[b]) swap(a, b);
    data[b] = a;
    if (rnk[a] == rnk[b]) rnk[a]++;
  }
};

pair<Weight, Edges> kruskal(const Graph &g) {
  UFT uf(g.size());
  Edges es;
  for (auto &adj : g) {
    for (auto &e : adj) es.emplace_back(e);
  }
  sort(all(es), [](const Edge &e, const Edge &f) { return e.weight < f.weight; });
  Weight total = 0;
  Edges T;
  for (auto &e : es) {
    if (!uf.same(e.src, e.dst)) {
      T.pb(e);
      total += e.weight;
      uf.unite(e.src, e.dst);
    }
  }
  return mp(total, T);
}

void solve() {
  int n;
  cin >> n;
  vpii v(n), xs(n), ys(n);
  rep(i, n) {
    cin >> v[i].fi >> v[i].se;
    xs[i] = mp(v[i].fi, i);
    ys[i] = mp(v[i].se, i);
  }
  sort(all(xs)), sort(all(ys));
  Graph g(n);
  loop(i, 1, n) {
    addEdge(g, xs[i - 1].se, xs[i].se, abs(v[xs[i - 1].se].fi - v[xs[i].se].fi));
    addEdge(g, ys[i - 1].se, ys[i].se, abs(v[ys[i - 1].se].se - v[ys[i].se].se));
  }
  cout << kruskal(g).fi << endl;
}
