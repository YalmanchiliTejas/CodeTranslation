#include <bits/stdc++.h>

using namespace std;

#define int long long
#define all(v) (v).begin(), (v).end()
#define resz(v, ...) (v).clear(), (v).resize(__VA_ARGS__)
#define reps(i, m, n) for(int i = (int)(m); i < (int)(n); i++)
#define rep(i, n) reps(i, 0, n)

template<class T1, class T2> void chmin(T1 &a, T2 b){if(a>b)a=b;}
template<class T1, class T2> void chmax(T1 &a, T2 b){if(a<b)a=b;}

using Pi = pair<int, int>;
using Ti = tuple<int, int, int>;
using vint = vector<int>;

const int inf = 1LL << 55;
const int mod = 1e9 + 7;

using Graph = vector<vint>;

struct HLD {
  Graph graph;
  vint vid, head, heavy, par, depth;
  HLD(int V):graph(V), vid(V, -1), head(V), heavy(V, -1), par(V), depth(V){}
  void add_edge(int u, int v) {
    graph[u].emplace_back(v);
    graph[v].emplace_back(u);
  }
  void build() {
    dfs(0, -1);
    bfs();
  }
  int dfs(int u, int p) {
    par[u] = p;
    int subsz = 1, mx_chsz = 0;
    for(int v : graph[u]) {
      if(v == p) continue;
      depth[v] = depth[u]+1;
      int chsz = dfs(v, u);
      subsz += chsz;
      if(chsz > mx_chsz) mx_chsz = chsz, heavy[u] = v;
    }
    return subsz;
  }
  void bfs() {
    int id = 0;
    queue<int> que;
    que.push(0);
    while(!que.empty()) {
      int h = que.front(); que.pop();
      for(int u = h; u != -1; u = heavy[u]) {
	vid[u] = id++;
	head[u] = h;
	for(int v : graph[u]) {
	  if(v == par[u] || v == heavy[u]) continue;
	  que.push(v);
	}
      }
    }
  }
  void for_edge(int u, int v, function<void(int, int)> f) {
    if(vid[u] > vid[v]) swap(u, v);
    if(head[u] != head[v]) {
      f(vid[head[v]], vid[v]);
      for_edge(u, par[head[v]], f);
    } else {
      if(u != v) f(vid[u]+1, vid[v]);
    }
  }
};

struct UnionFind {
  vint data;
  UnionFind(int V):data(V, -1){}
  int find(int x) {
    return data[x] < 0 ? x : data[x] = find(data[x]);
  }
  int size(int x) {
    return -data[find(x)];
  }
  bool same(int x, int y) {
    return find(x) == find(y);
  }
  void unite(int x, int y) {
    x = find(x), y = find(y);
    if(x == y) return;
    if(data[x] > data[y]) swap(x, y);
    data[x] += data[y];
    data[y] = x;
  }
};

struct edge {
  int u, v, w, id;
  edge(){}
  edge(int u, int v, int w, int id):u(u), v(v), w(w), id(id){}
  bool operator < (const edge& e) const {
    return w < e.w;
  }
};
int Kruskal(int V, vector<edge> es, vint& used) {
  int res = 0;
  UnionFind uf(V);
  sort(all(es));
  resz(used, es.size(), 0);
  for(auto&& e : es) {
    if(!uf.same(e.u, e.v)) {
      uf.unite(e.u, e.v);
      used[e.id] = 1;
      res += e.w;
    }
  }
  return res;
}

struct SegmentTree {
  vint data, lazy;
  int sz;
  SegmentTree(int n) {
    sz = 1; while(sz < n) sz <<= 1;
    resz(data, 2*sz-1, inf);
    resz(lazy, 2*sz-1, -1);
  }
  void push(int k, int l, int r) {
    if(~lazy[k]) {
      chmin(data[k], lazy[k]);
      if(r-l > 1) {
	if(~lazy[2*k+1]) chmin(lazy[2*k+1], lazy[k]);
	else lazy[2*k+1] = lazy[k];
	if(~lazy[2*k+2]) chmin(lazy[2*k+2], lazy[k]);
	else lazy[2*k+2] = lazy[k];
      }
      lazy[k] = -1;
    }
  }
  void update(int a, int b, int x, int k, int l, int r) {
    push(k, l, r);
    if(r <= a || b <= l) return;
    if(a <= l && r <= b) {
      lazy[k] = x;
      push(k, l, r);
      return;
    }
    update(a, b, x, 2*k+1, l, (l+r)/2);
    update(a, b, x, 2*k+2, (l+r)/2, r);
    data[k] = min(data[2*k+1], data[2*k+2]);
  }
  void update(int a, int b, int x) {
    update(a, b, x, 0, 0, sz);
  }
  int query(int a, int b, int k, int l, int r) {
    push(k, l, r);
    if(r <= a || b <= l) return inf;
    if(a <= l && r <= b) return data[k];
    int vl = query(a, b, 2*k+1, l, (l+r)/2);
    int vr = query(a, b, 2*k+2, (l+r)/2, r);
    return min(vl, vr);
  }
  int query(int a, int b) {
    return query(a, b, 0, 0, sz);
  }
};

signed main() {
  cin.tie(0);
  ios_base::sync_with_stdio(0);
  cout << fixed << setprecision(12);

  int n, m;
  cin >> n >> m;
  vector<edge> es;
  UnionFind uf(n);
  rep(i, m) {
    int a, b, c;
    cin >> a >> b >> c;
    --a, --b;
    es.emplace_back(a, b, c, i);
    uf.unite(a, b);
  }
  if(uf.size(0) < n) {
    rep(i, m) cout << -1 << endl;
    return 0;
  }
  vint used;
  int mincost = Kruskal(n, es, used);
  HLD graph(n);
  rep(i, es.size()) {
    if(!used[i]) continue;
    auto&& e = es[i];
    graph.add_edge(e.u, e.v);
  }
  graph.build();
  SegmentTree seg(n);
  rep(i, es.size()) {
    if(used[i]) continue;
    auto&& e = es[i];
    graph.for_edge(e.u, e.v, [&](int l, int r) {
	seg.update(l, r+1, e.w);
      });
  }
  rep(i, es.size()) {
    if(!used[i]) {
      cout << mincost << endl;
    } else {
      auto&& e = es[i];
      int ans = inf;
      graph.for_edge(e.u, e.v, [&](int l, int r) {
	  chmin(ans, seg.query(l, r+1));
	});
      if(ans != inf) cout << mincost-e.w+ans << endl;
      else cout << -1 << endl;
    }
  }

  return 0;
}