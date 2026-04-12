#include <bits/stdc++.h>
#define FOR(i,k,n)  for(int i = (k);i < (n);++i)
#define REP(i,n)    FOR(i,0,n)
#define ALL(x)      begin(x),end(x)

using namespace std;
using vecint = vector<int>;
using ll = int64_t;
constexpr int INF = 1000000000;

struct UnionFind {
  vector<int> parent;
  UnionFind (int n) : parent(n, -1) {}
  int root(int x) { return parent[x] < 0 ? x : parent[x] = root(parent[x]); }
  bool merge(int x, int y) {
    x = root(x); y = root(y);
    if (x == y) return false;
    if (parent[y] < parent[x]) swap(x, y);
    if (parent[x] == parent[y]) --parent[x];
    parent[y] = x;
    return true;
  }
};

typedef int Weight;
struct Edge{
  int src, dest; Weight weight;
  bool operator < (const Edge &rhs) const {return weight > rhs.weight;}
};

typedef vector<Edge> Edges;

// Kruskal
// N, operator <
Edges kruskal(int V, Edges &es) {
  sort(es.rbegin(), es.rend());
  UnionFind uf(V);
  Edges res;
  REP(i, es.size()) {
    Edge e = es[i];
    if(uf.root(e.src) != uf.root(e.dest)) {
      uf.merge(e.src, e.dest);
      res.push_back(e);
    }
  }
  return res;
}

int main()
{
  int n;
  cin>>n;
  vector<tuple<int,int>> vx, vy;
  REP(i,n) {
    int x,y;
    cin>>x>>y;
    vx.emplace_back(x,i);
    vy.emplace_back(y,i);
  }
  sort(ALL(vx));
  sort(ALL(vy));
  Edges ve;
  REP(i,n-1) {
    int x1, j1, x2, j2;
    tie(x1, j1) = vx[i];
    tie(x2, j2) = vx[i+1];
    ve.push_back((Edge){j1, j2, abs(x1-x2)});
    int y1, y2;
    tie(y1, j1) = vy[i];
    tie(y2, j2) = vy[i+1];
    ve.push_back((Edge){j1, j2, abs(y1-y2)});
  }
  Edges res = kruskal(n, ve);
  int sum = 0;
  for(Edge e:res) sum += e.weight;
  cout << sum << endl;
  return 0;
}