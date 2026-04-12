#include "bits/stdc++.h"
#define ALL(x) x.begin(), x.end()
#define LEN(x) (int)x.size()
#define iostreamBooster() do{ cin.tie(nullptr); ios_base::sync_with_stdio(false); }while(0)
using namespace std;
typedef int64_t i64;
typedef pair<int,int> pii;
template<class A, class B>inline bool chmax(A &a, const B &b){return b>a ? a=b,1 : 0;}
template<class A, class B>inline bool chmin(A &a, const B &b){return b<a ? a=b,1 : 0;}
constexpr int INF = 0x3f3f3f3f;

struct P {
  int x, y, id;
  P(int x=0, int y=0, int id=0): x(x), y(y), id(id) {};
};

struct Edge {
  int prev, to, cost;
  Edge(int a=0, int b=0, int c=0): prev(a), to(b), cost(c) {}
  bool operator < (const Edge &rhs) const { return (cost < rhs.cost); }
  bool operator > (const Edge &rhs) const { return (cost > rhs.cost); }
};

struct UnionFind {
  vector<int> uni;
  explicit UnionFind(int n): uni(n+5, -1) {}
  int  root(int x)        { return (uni[x] < 0)? x : uni[x] = root(uni[x]); }
  int  size(int i)        { return (-uni[root(i)]); }
  bool same(int x, int y) { return root(x) == root(y); }
  bool unite(int x, int y){
    if ( (x=root(x)) == (y=root(y)) )return false;
    if ( uni[y] < uni[x] ) swap(x,y);
    uni[x] += uni[y];  uni[y] = x;
    return true;
  }
};

i64 kruskal(int N, vector<Edge> G)
{
  i64 ans = 0;
  UnionFind uf(N);

  sort(ALL(G));
  for(const auto &e : G) {
    if (uf.unite(e.prev, e.to)) ans += e.cost;
  }
  return ans;
}

signed main()
{
  int N;
  vector<Edge> G;
  P p[100100];

  cin >> N;
  for (int i = 0; i < N; i++) {
    int x, y; cin >> x >> y;
    p[i] = P(x, y, i);
  }

  sort(p, p+N, [](const auto &a, const auto &b){return a.x < b.x; });
  for (int i= 1; i < N; ++i) {
    G.emplace_back(p[i].id, p[i-1].id, abs(p[i].x - p[i-1].x));
  }
  sort(p, p+N, [](const auto &a, const auto &b){return a.y < b.y; });
  for (int i= 1; i < N; ++i) {
    G.emplace_back(p[i].id, p[i-1].id, abs(p[i].y - p[i-1].y));
  }

  cout << kruskal(N, G) << endl;
  return 0;
}

