#include <cstdio>
#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <cmath>
#include <iomanip>
#include <cassert>
#include <bitset>
#include <functional>
using namespace std;

typedef pair<int, int> P;
typedef pair<P, P> P2;
#define rep(i, n) for (int i=0; i<(n); i++)
#define all(c) (c).begin(), (c).end()
#define uniq(c) c.erase(unique(all(c)), (c).end())
#define index(xs, x) (int)(lower_bound(all(xs), x) - xs.begin())
#define _1 first
#define _2 second
#define pb push_back
#define INF 1145141919
#define MOD 1000000007
struct HLDecomposition {
  int N;
  vector<vector<int> > G;
  vector<int> par, head, tid, next;
  HLDecomposition(int N) : N(N), G(N), par(N, -1), head(N, -1), tid(N, -1), next(N, -1) {}

  void add_edge(int u, int v) {
    G[u].pb(v);
    G[v].pb(u);
  }

  void build() {
    dfs(0, -1);
    bfs();
  }

  int dfs(int x, int p) {
    par[x] = p;
    int size = 1, mx = -1;
    for (int t : G[x]) {
      if (t == p) continue;
      int ns = dfs(t, x);
      if (ns > mx) mx = ns, next[x] = t;
      size += ns;
    }
    return size;
  }

  void bfs() {
    queue<int> q;
    q.push(0);

    int k = 0;
    while (!q.empty()) {
      int h = q.front(); q.pop();
      for (int v=h; v!=-1; v=next[v]) {
        head[v] = h, tid[v] = k++;
        for (int t : G[v]) if (t != par[v] && t != next[v]) q.push(t);
      }
    }
    assert(k == N);
  }

  int lca(int x, int y) {
    if (tid[x] > tid[y]) swap(x, y);
    if (head[x] == head[y]) return x;
    return lca(x, par[head[y]]);
  }

  void for_each_edge(int x, int y, function<void(int, int)> f) {
    if (tid[x] > tid[y]) swap(x, y);
    if (x == y) return;
    if (head[x] == head[y]) f(tid[x]+1, tid[y]);
    else {
      f(tid[head[y]], tid[y]);
      for_each_edge(x, par[head[y]], f);
    }
  }
};

#define MAX_N (1<<17)
struct SegTree {
  int seg[MAX_N*2-1], lazy[MAX_N*2-1];
  SegTree() {
    rep(i, MAX_N*2-1) seg[i] = INF, lazy[i] = INF;
  }
  void setLazy(int k, int v) {
    lazy[k] = min(lazy[k], v);
    seg[k] = min(seg[k], v);
  }

  void push(int k) {
    if (lazy[k] == INF) return;
    setLazy(k*2+1, lazy[k]);
    setLazy(k*2+2, lazy[k]);
    lazy[k] = INF;
  }

  void update(int a, int b, int x, int k=0, int l=0, int r=MAX_N) {
    if (b <= l || r <= a) return;
    if (a <= l && r <= b) {
      setLazy(k, x);
      return;
    }
    push(k);
    update(a, b, x, k*2+1, l, (l+r)/2);
    update(a, b, x, k*2+2, (l+r)/2, r);
  }

  int query(int a, int b, int k=0, int l=0, int r=MAX_N) {
    if (b <= l || r <= a) return INF;
    if (a <= l && r <= b) return seg[k];
    push(k);
    return min(query(a, b, k*2+1, l, (l+r)/2), query(a, b, k*2+2, (l+r)/2, r));
  }
};

int N, M;
int U[100000];
long long ans[200000];
bool backward[200000];
SegTree seg;

int find(int x) {
  if (U[x] == x) return x;
  return U[x] = find(U[x]);
}
void unite(int x, int y) {
  x = find(x), y = find(y);
  if (x == y) return;
  U[x] = y;
}
bool same(int x, int y) {
  return find(x) == find(y);
}

signed main() {
  ios::sync_with_stdio(false); cin.tie(0);
  cin >> N >> M;
  vector<P2> edges;
  rep(i, M) {
    int u, v, w;
    cin >> u >> v >> w;
    u--, v--;
    edges.pb(P2(P(w, i), P(u, v)));
  }
  sort(all(edges));
  rep(i, N) U[i] = i;

  long long mst = 0;
  HLDecomposition hld(N);

  for (P2 p : edges) {
    int u = p._2._1, v = p._2._2;
    if (same(u, v)) {
      backward[p._1._2] = true;
      continue;
    }
    unite(u, v);
    hld.add_edge(u, v);
    mst += p._1._1;
  }
  rep(i, N) if (!same(0, i)) {
    rep(_, M) cout << -1 << "\n"; // graph is not connected
    return 0;
  }
  hld.build();

  for (P2 p : edges) {
    if (!backward[p._1._2]) continue;
    ans[p._1._2] = mst;
    int w = p._1._1, u = p._2._1, v = p._2._2;
    hld.for_each_edge(u, v, [&](int l, int r) {
      seg.update(l, r+1, w);
    });
  }
  for (P2 p : edges) {
    int e = p._1._2, u = p._2._1, v = p._2._2;
    if (backward[e]) continue;
    int s = max(hld.tid[u], hld.tid[v]);
    int m = seg.query(s, s+1);
    if (m == INF) ans[e] = -1;
    else ans[e] = mst - p._1._1 + m;
  }
  rep(i, M) cout << ans[i] << "\n";
  return 0;
}