#include<bits/stdc++.h>

using namespace std;

using int64 = long long;

struct CentroidPathDecomposition
{
  struct Centroid
  {
    int ParIndex, ParDepth, Deep;
    vector< int > node;

    Centroid(int idx, int dep, int deep) : ParIndex(idx), ParDepth(dep), Deep(deep) {}

    inline size_t size()
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

  vector< vector< int > > graph;
  vector< int > SubTreeSize, NextPath;
  vector< int > TreeIndex, TreeDepth;
  vector< Centroid > Centroids;

  void BuildSubTreeSize()
  {
    stack< pair< int, int > > s;
    s.emplace(0, -1);
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
          if(p.second != to) s.emplace(to, p.first);
        }
      }
    }
  }

  void BuildPath()
  {
    stack< pair< int, int > > s;
    Centroids.emplace_back(-1, -1, 0);
    s.emplace(0, -1);
    TreeIndex[0] = 0;
    while(!s.empty()) {
      auto p = s.top();
      s.pop();
      TreeDepth[p.first] = (int) Centroids[TreeIndex[p.first]].size();
      for(auto &to : graph[p.first]) {
        if(p.second == to) continue;
        if(to == NextPath[p.first]) { // Centroid-Path
          TreeIndex[to] = TreeIndex[p.first];
        } else {                  // Not Centroid-Path
          TreeIndex[to] = (int) Centroids.size();
          Centroids.emplace_back(TreeIndex[p.first], TreeDepth[p.first], Centroids[TreeIndex[p.first]].Deep + 1);
        }
        s.emplace(to, p.first);
      }
      Centroids[TreeIndex[p.first]].node.emplace_back(p.first);
    }
  }

  void AddEdge(int x, int y)
  {
    graph[x].push_back(y);
    graph[y].push_back(x);
  }

  virtual void Build()
  {
    BuildSubTreeSize();
    BuildPath();
  }

  inline size_t size()
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

  inline virtual void query(int a, int b, const function< void(int, int, int) > &f)
  {
    int TreeIdxA, TreeDepthA, TreeIdxB, TreeDepthB;
    tie(TreeIdxA, TreeDepthA) = Information(a);
    tie(TreeIdxB, TreeDepthB) = Information(b);
    while(TreeIdxA != TreeIdxB) {
      if(Centroids[TreeIdxA].Deep > Centroids[TreeIdxB].Deep) {
        f(TreeIdxA, 0, TreeDepthA + 1);
        tie(TreeIdxA, TreeDepthA) = Centroids[TreeIdxA].Up();
      } else {
        f(TreeIdxB, 0, TreeDepthB + 1);
        tie(TreeIdxB, TreeDepthB) = Centroids[TreeIdxB].Up();
      }
    }
    if(TreeDepthA > TreeDepthB) swap(TreeDepthA, TreeDepthB);
    f(TreeIdxA, TreeDepthA, TreeDepthB + 1);
  }

  CentroidPathDecomposition(int SZ)
  {
    graph.resize(SZ);
    SubTreeSize.assign(SZ, -1);
    NextPath.resize(SZ);
    TreeIndex.resize(SZ);
    TreeDepth.resize(SZ);
  }
};

struct TreeArray : CentroidPathDecomposition
{
  TreeArray(int sz) : CentroidPathDecomposition(sz) {}

  vector< int > index;

  void Build()
  {
    CentroidPathDecomposition::Build();
    int ptr = 0;
    for(auto &centroid : Centroids) {
      index.emplace_back(ptr);
      ptr += centroid.size();
    }
  }

  inline int get(int a)
  {
    auto p = Information(a);
    return (index[p.first] + p.second);
  }

  inline void query(int a, int b, const function< void(int, int) > &f)
  {
    int TreeIdxA, TreeDepthA, TreeIdxB, TreeDepthB;
    tie(TreeIdxA, TreeDepthA) = Information(a);
    tie(TreeIdxB, TreeDepthB) = Information(b);
    while(TreeIdxA != TreeIdxB) {
      if(Centroids[TreeIdxA].Deep > Centroids[TreeIdxB].Deep) {
        f(index[TreeIdxA], index[TreeIdxA] + TreeDepthA + 1);
        tie(TreeIdxA, TreeDepthA) = Centroids[TreeIdxA].Up();
      } else {
        f(index[TreeIdxB], index[TreeIdxB] + TreeDepthB + 1);
        tie(TreeIdxB, TreeDepthB) = Centroids[TreeIdxB].Up();
      }
    }
    if(TreeDepthA > TreeDepthB) swap(TreeDepthA, TreeDepthB);
    f(index[TreeIdxA] + TreeDepthA + 1, index[TreeIdxA] + TreeDepthB + 1);
  }
};

struct SegNode
{
  int v;

  SegNode(int v) : v(v) {}

  SegNode operator*(const SegNode &r) const
  {
    return (v > r.v ? *this : r);
  }
} e(0);

struct SegmentTree
{
  int sz;
  vector< SegNode > seg;

  SegmentTree(int n)
  {
    sz = 1;
    while(sz < n) sz <<= 1;
    seg.assign(2 * sz - 1, e);
  }

  void update(int k, const SegNode &x)
  {
    k += sz - 1;
    seg[k] = x;
    while(k > 0) {
      k = (k - 1) >> 1;
      seg[k] = seg[2 * k + 1] * seg[2 * k + 2];
    }
  }

  SegNode query(int a, int b, int k, int l, int r)
  {
    if(a >= r || b <= l) return (e);
    if(a <= l && r <= b) return (seg[k]);
    return (query(a, b, 2 * k + 1, l, (l + r) >> 1) * query(a, b, 2 * k + 2, (l + r) >> 1, r));
  }

  SegNode query(int a, int b)
  {
    return (query(a, b, 0, 0, sz));
  }
};

struct UnionFind
{
  vector< int > data;

  UnionFind(int sz)
  {
    data.assign(sz, -1);
  }

  bool unite(int x, int y)
  {
    x = find(x), y = find(y);
    if(x == y) return (false);
    if(data[x] > data[y]) swap(x, y);
    data[x] += data[y];
    data[y] = x;
    return (true);
  }

  int find(int k)
  {
    if(data[k] < 0) return (k);
    return (data[k] = find(data[k]));
  }

  int size(int k)
  {
    return (-data[find(k)]);
  }
};

using int64 = long long;

int main()
{
  int N, M, Q;
  scanf("%d %d", &N, &M);
  vector< tuple< int, int, int > > vs;
  for(int i = 0; i < M; i++) {
    int a, b, c;
    scanf("%d %d %d", &a, &b, &c);
    --a, --b;
    vs.emplace_back(c, a, b);
  }
  sort(begin(vs), end(vs));
  UnionFind uf(N);
  TreeArray tree(N);
  int64 ret = 0;
  map< pair< int, int >, int > conv;
  for(auto &e : vs) {
    int cost;
    int a, b;
    tie(cost, a, b) = e;
    if(uf.unite(a, b)) {
      tree.AddEdge(a, b);
      conv[minmax(a, b)] = cost;
      ret += cost;
    }
  }
  tree.Build();
  SegmentTree seg(N);
  for(auto &p : conv) {
    seg.update(max(tree.get(p.first.first), tree.get(p.first.second)), p.second);
  }

  scanf("%d", &Q);
  while(Q--) {
    int a, b;
    scanf("%d %d", &a, &b);
    int sub = 0;
    tree.query(--a, --b, [&](int x, int y)
    {
      sub = max(sub, seg.query(x, y).v);
    });
    printf("%lld\n", ret - sub);
  }
}
