#include <bits/stdc++.h>

using namespace std;

typedef long long int64;

const int INF = 1 << 30;

struct SegmentTree
{
  vector< int > seg;
  int sz;

  SegmentTree(int n)
  {
    sz = 1;
    while(sz < n) sz <<= 1;
    seg.assign(2 * sz - 1, -INF);
  }

  void set(int k, int x)
  {
    seg[k + sz - 1] = x;
  }

  void build()
  {
    for(int k = sz - 2; k >= 0; k--) {
      seg[k] = max(seg[2 * k + 1], seg[2 * k + 2]);
    }
  }

  int rmq(int a, int b, int k, int l, int r)
  {
    if(a >= r || b <= l) return (-INF);
    if(a <= l && r <= b) return (seg[k]);
    return (max(rmq(a, b, 2 * k + 1, l, (l + r) >> 1),
                rmq(a, b, 2 * k + 2, (l + r) >> 1, r)));
  }

  int rmq(int a, int b)
  {
    return (rmq(a, b, 0, 0, sz));
  }

  void update(int k, int x)
  {
    k += sz - 1;
    seg[k] = x;
    while(k > 0) {
      k = (k - 1) >> 1;
      seg[k] = max(seg[2 * k + 1], seg[2 * k + 2]);
    }
  }

};

vector< vector< int > > graph;

struct CentroidPathDecomposition
{
  struct Centroid
  {
    int ParIndex, ParDepth, Deep;
    vector< int > node;

    inline int size()
    {
      return (node.size());
    }

    inline int &operator[](int k)
    {
      return (node[k]);
    }

    inline pair< int, int > Up()
    {
      return (make_pair(ParIndex, ParDepth));
    }
  };

  vector< int > SubTreeSize, NextPath;
  vector< int > TreeIndex, TreeDepth;
  vector< Centroid > Centroids;

  void BuildSubTreeSize()
  {
    stack< pair< int, int > > s;
    s.push({0, -1});
    while(!s.empty()) {
      auto p = s.top();
      s.pop();
      if(~SubTreeSize[p.first]) {
        NextPath[p.first] = -1;
        for(auto &to : graph[p.first]) {
          if(p.second == to) continue;
          SubTreeSize[p.first] += SubTreeSize[to];
          if(NextPath[p.first] == -1 || SubTreeSize[NextPath[p.first]] < SubTreeSize[to]) {
            NextPath[p.first] = to;
          }
        }
      } else {
        s.push(p);
        SubTreeSize[p.first] = 1;
        for(auto &to : graph[p.first]) {
          if(p.second != to) s.push({to, p.first});
        }
      }
    }
  }

  void BuildPath()
  {
    stack< pair< int, int > > s;
    Centroids.push_back((Centroid) {-1, -1, 0});
    s.push({0, -1});
    TreeIndex[0] = 0;
    while(!s.empty()) {
      auto p = s.top();
      s.pop();
      TreeDepth[p.first] = Centroids[TreeIndex[p.first]].size();
      for(auto &to : graph[p.first]) {
        if(p.second != to) {
          if(to == NextPath[p.first]) { // Centroid-Path
            TreeIndex[to] = TreeIndex[p.first];
          } else {                  // Not Centroid-Path
            TreeIndex[to] = Centroids.size();
            Centroids.push_back((Centroid) {TreeIndex[p.first], TreeDepth[p.first], Centroids[TreeIndex[p.first]].Deep + 1});
          }
          s.push({to, p.first});
        }
      }
      Centroids[TreeIndex[p.first]].node.push_back(p.first);
    }
  }

  void AddEdge(int x, int y)
  {
    graph[x].push_back(y);
    graph[y].push_back(x);
  }

  void Build()
  {
    BuildSubTreeSize();
    BuildPath();
  }

  inline int size()
  {
    return (Centroids.size());
  }

  inline pair< int, int > Information(int idx)
  {
    return (make_pair(TreeIndex[idx], TreeDepth[idx]));
  }

  inline Centroid &operator[](int k)
  {
    return (Centroids[k]);
  }

  inline int LCA(int a, int b)
  {
    int TreeIdxA, TreeDepthA, TreeIdxB, TreeDepthB;
    tie(TreeIdxA, TreeDepthA) = Information(a);
    tie(TreeIdxB, TreeDepthB) = Information(b);
    while(TreeIdxA != TreeIdxB) {
      if(Centroids[TreeIdxA].Deep > Centroids[TreeIdxB].Deep) {
        tie(TreeIdxA, TreeDepthA) = Centroids[TreeIdxA].Up();
      } else {
        tie(TreeIdxB, TreeDepthB) = Centroids[TreeIdxB].Up();
      }
    }
    if(TreeDepthA > TreeDepthB) swap(TreeDepthA, TreeDepthB);
    return (Centroids[TreeIdxA][TreeDepthA]);
  }

  CentroidPathDecomposition(int SZ)
  {
    graph.resize(SZ);
    SubTreeSize.assign(SZ, -1);
    NextPath.resize(SZ);
    TreeIndex.resize(SZ);
    TreeDepth.resize(SZ);
  }

  inline int getPathMax(int a, int b);
};


struct UnionFind
{
  vector< int > data;

  UnionFind(int sz) : data(sz, -1) {}

  void unite(int x, int y)
  {
    x = find(x);
    y = find(y);
    if(x == y) return;
    if(data[x] > data[y]) swap(x, y);
    data[x] += data[y];
    data[y] = x;
  }

  int find(int k)
  {
    if(data[k] < 0) return (k);
    return (data[k] = find(data[k]));
  }
};

struct edge
{
  int u, v, cost;

  bool operator<(const edge &e) const
  {
    return (cost < e.cost);
  }
};


vector< SegmentTree > segs;

int CentroidPathDecomposition::getPathMax(int a, int b)
{
  int TreeIdxA, TreeDepthA, TreeIdxB, TreeDepthB;
  tie(TreeIdxA, TreeDepthA) = Information(a);
  tie(TreeIdxB, TreeDepthB) = Information(b);
  int ret = 0;
  while(TreeIdxA != TreeIdxB) {
    if(Centroids[TreeIdxA].Deep > Centroids[TreeIdxB].Deep) {
      ret = max(ret, segs[TreeIdxA].rmq(0, TreeDepthA + 1));
      tie(TreeIdxA, TreeDepthA) = Centroids[TreeIdxA].Up();
    } else {
      ret = max(ret, segs[TreeIdxB].rmq(0, TreeDepthB + 1));
      tie(TreeIdxB, TreeDepthB) = Centroids[TreeIdxB].Up();
    }
  }
  if(TreeDepthA > TreeDepthB) swap(TreeDepthA, TreeDepthB);
  return (max(ret, segs[TreeIdxA].rmq(TreeDepthA + 1, TreeDepthB + 1)));
}

int main()
{
  int N, M;
  cin >> N >> M;
  vector< edge > edges(M);
  for(auto &e : edges) cin >> e.u >> e.v >> e.cost;
  sort(begin(edges), end(edges));
  int64 cost = 0LL;
  UnionFind tree(N);
  CentroidPathDecomposition cpd(N);
  map< pair< int, int >, int > vs;
  for(auto &e : edges) {
    e.u--, e.v--;
    if(tree.find(e.u) == tree.find(e.v)) continue;
    cost += e.cost;
    tree.unite(e.u, e.v);
    cpd.AddEdge(e.u, e.v);
    vs[{e.u, e.v}] = e.cost;
  }
  cpd.Build();
  for(int i = 0; i < cpd.size(); i++) {
    segs.push_back(SegmentTree(cpd[i].size()));
  }
  for(auto &v : vs) {
    auto a = cpd.Information(v.first.first);
    auto b = cpd.Information(v.first.second);
    if(a.first > b.first || (a.first == b.first) && a.second > b.second) swap(a, b);
    segs[b.first].update(b.second, v.second);
  }
  int Q;
  cin >> Q;
  while(Q--) {
    int s, t;
    cin >> s >> t;
    cout << cost - cpd.getPathMax(--s, --t) << endl;
  }
}