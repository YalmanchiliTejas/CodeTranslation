#include <bits/stdc++.h>
using namespace std;
using lint = long long int;
template<class T = int> using V = vector<T>;
template<class T = int> using VV = V< V<T> >;
template<class T> void assign(V<T>& v, int n, auto& a = T()) { v.assign(n, a); }
template<class T, class... U> void assign(V<T>& v, int n, const U&... u) { v.resize(n); for (auto&& i : v) assign(i, u...); }

struct QU {
  V<> par, rank, _size;

  QU(int n) { 
    par.resize(n);
    iota(par.begin(), par.end(), 0);
    rank.resize(n);
    _size.assign(n, 1);
  }

  int find(int a) {
    if (par[a] == a) return a;
    return par[a] = find(par[a]);
  }

  bool same(int a, int b) { return find(a) == find(b); }

  int size(int a) { return _size[find(a)]; }

  void unite(int a, int b) {
    a = find(a), b = find(b);
    if (a == b) return;
    if (rank[a] < rank[b]) {
      par[a] = b;
      _size[b] += _size[a];
    } else {
      par[b] = a;
      _size[a] += _size[b];
    }
    if (rank[a] == rank[b]) rank[a]++;
  }
};

template<class T> struct edge { int id, from, to; T w; };

template<class T> T kruskal(V< edge<T> >& g, int n, V<bool>& used) {
  T res = 0;
  QU qu(n);
  sort(g.begin(), g.end(), [](auto a, auto b) { return a.w < b.w; });
  for (auto&& e : g) {
    if (!qu.same(e.from, e.to)) {
      qu.unite(e.from, e.to);
      res += e.w;
      used[e.id] = true;
    }
  }
  return res;
}

int main() {
  cin.tie(NULL); ios::sync_with_stdio(false);
  int n, m; cin >> n >> m;
  V< edge<lint> > es(m);
  for (int i = 0; i < m; i++) {
    int a, b, c; cin >> a >> b >> c, a--, b--;
    es[i] = {i, a, b, c};
  }
  V<bool> used(m);
  lint sm = kruskal<lint>(es, n, used);
  struct edge2 { int to; lint w; };
  VV<edge2> g(n);
  for (int i = 0; i < m; i++) if (used[es[i].id]) {
    g[es[i].from].push_back({es[i].to, es[i].w});
    g[es[i].to].push_back({es[i].from, es[i].w});
  }
  VV<lint> res; assign(res, n, n, -1e18);
  for (int i = 0; i < n; i++) {
    queue<int> q;
    V<bool> vis(n);
    vis[i] = true; q.push(i);
    while (!q.empty()) {
      int v = q.front(); q.pop();
      for (auto&& e : g[v]) if (!vis[e.to]) {
        vis[e.to] = true;
        res[i][e.to] = max(res[i][v], e.w);
        q.push(e.to);
      }
    }
  }
  int q; cin >> q;
  for (int iq = 0; iq < q; iq++) {
    int s, t; cin >> s >> t, s--, t--;
    cout << sm - res[s][t] << '\n';
  }
}