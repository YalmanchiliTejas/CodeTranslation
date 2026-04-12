#include <bits/stdc++.h>
using namespace std;

#define REP(i,n) for(int i=0;i<(int)(n);i++)
#define ALL(x) (x).begin(), (x).end()

typedef long long ll;
typedef long double ld;

const int INF = 2e9;
const ld EPS = 1e-8;

typedef ll Weight;
typedef int Flow;

struct Edge {
  int src, dest, rev;
  Flow cap;
  Weight cost;
  bool operator < (const Edge &rhs) const {
    return cost > rhs.cost;
  }
  Edge(int s, int d) : src(s), dest(d) { ; }
  Edge(int s, int d, int c) : src(s), dest(d), cost(c) { ; }
  Edge(int s, int d, int r, Flow cp, Weight cst) : src(s), dest(d), rev(r), cap(cp), cost(cst) { ; }
};

typedef vector<Edge> Edges;
typedef vector<Edges> Graph;
typedef vector<Weight> Array;
typedef vector<Array> Matrix;

struct UnionFind {
  vector<int> data;
  UnionFind(int size) : data(size, -1) { }
  bool unionSet(int x, int y) {
    x = root(x); y = root(y);
    if (x != y) {
      if (data[y] < data[x]) swap(x, y);
      data[x] += data[y]; data[y] = x;
    }
    return x != y;
  }
  bool findSet(int x, int y) {
    return root(x) == root(y);
  }
  int root(int x) {
    return data[x] < 0 ? x : data[x] = root(data[x]);
  }
  int size(int x) {
    return -data[root(x)];
  }
};

bool comp(const Edge &e1, const Edge &e2){
  return e1.cost < e2.cost;
}

pair<Weight, Edges> kruskal(Edges &es, int v){
  sort(ALL(es), comp);
  UnionFind uni(v);
  Edges mst;
  Weight res = 0;
  for(Edge e: es){
    if(!uni.findSet(e.src, e.dest)){
      uni.unionSet(e.src, e.dest);
      mst.push_back(e);
      res += e.cost;
    }
  }
  return make_pair(res, mst);
}

int main(){
  int N, M;
  cin >> N >> M;
  Edges es;
  REP(i,M) {
    int a, b, c;
    cin >> a >> b >> c; --a; --b;
    es.push_back(Edge(a, b, c));
    es.push_back(Edge(b, a, c));
  }

  pair<Weight, Edges> mst = kruskal(es, N);
  Graph g(N);
  for(Edge e: mst.second) {
    g[e.src].push_back(e);
    g[e.dest].push_back(Edge(e.dest, e.src, e.cost));
  }
  /*
  REP(i,N) {
    for(Edge e: g[i]) {
      cout << e.dest << " ";
    }
    cout << endl;
  }
  */

  vector<vector<int>> d(N, vector<int> (N, 0));
  REP(i,N) {
    queue<tuple<int,int,ll>> que;
    que.push(make_tuple(i, -1, 0));
    while(!que.empty()) {
      int curr, prev, cst;
      tie(curr, prev, cst) = que.front(); que.pop();
      d[i][curr] = max(d[i][curr], cst);
      for(Edge e: g[curr]) {
        if(e.dest == prev) continue;
        que.push(make_tuple(e.dest, curr, max((ll)cst, e.cost)));
      }
    }
  }
  /*
  REP(i,N){
    REP(j,N) cout << " " << d[i][j];
    cout << endl;
  }
  */

  int Q;
  cin >> Q;
  REP(q, Q) {
    int S, T;
    cin >> S >> T; --S; --T;
    ll res = mst.first - d[S][T];
    cout << res << endl;
  }
  return 0;
}

