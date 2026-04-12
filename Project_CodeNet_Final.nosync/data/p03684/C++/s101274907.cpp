#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0, i##_len = (n); i < i##_len; ++i)
#define rep2(i, x, n) for(int i = x, i##_len = (n); i < i##_len; ++i)
#define all(n) begin(n), end(n)
using ll = long long;
using P = pair<ll, ll>;
using vi = vector<int>;
using vl = vector<ll>;
using vs = vector<string>;
using vc = vector<char>;
using vb = vector<bool>;
using vd = vector<double>;
vi dir = {-1, 0, 1, 0, -1, -1, 1, 1, -1};

struct UnionFind {
  vector<int> d;
  UnionFind(int n) : d(n, -1) {}
  int root(int x) {
    if(d[x] < 0) return x;
    return d[x] = root(d[x]);
  }
  bool unite(int x, int y) {
    x = root(x);
    y = root(y);
    if(x == y) return false;
    if(d[x] > d[y]) swap(x, y);
    d[x] += d[y];
    d[y] = x;
    return true;
  }
  bool same(int x, int y) { return root(x) == root(y); }
  int size(int x) { return -d[root(x)]; }
};

struct edge {
  ll from, to, cost;
  bool operator<(const edge& o) const { return cost < o.cost; }
};

ll kruskal(ll n, vector<edge>& edges) {  // n:頂点の数, edges：辺のリスト
  sort(all(edges));
  UnionFind uf(n);
  ll res = 0;
  rep(i, edges.size()) {
    edge& e = edges[i];
    if(uf.same(e.from, e.to)) continue;
    res += e.cost;
    uf.unite(e.from, e.to);
  }
  return res;
}

int main() {
  ll n;
  cin >> n;
  vector<tuple<ll, ll, ll>> t(n);
  rep(i, n) {
    ll x, y;
    cin >> x >> y;
    t[i] = make_tuple(x, y, i);
  }
  vector<edge> edges;
  rep(_, 2) {
    sort(all(t));
    rep(i, n - 1) {
      ll a, b, p, c, d, q;
      tie(a, b, p) = t[i];
      tie(c, d, q) = t[i + 1];
      edge e;
      e.from = p;
      e.to = q;
      e.cost = abs(c - a);
      edges.push_back(e);
      e.cost = abs(d - b);
      edges.push_back(e);
    }
    rep(i, n) {
      ll a, b, p;
      tie(a, b, p) = t[i];
      t[i] = make_tuple(b, a, p);
    }
  }
  cout << kruskal(n, edges) << endl;
}