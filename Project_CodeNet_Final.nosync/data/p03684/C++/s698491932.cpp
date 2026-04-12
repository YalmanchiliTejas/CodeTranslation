#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cctype>
#include <iostream>
#include <sstream>
#include <algorithm>
#include <string>
#include <string.h>
#include <utility>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <cassert>
#include <bitset>

using namespace std;
typedef long long ll;

#ifndef INT_MAX
#  define INT_MAX std::numeric_limits<int>().max()
#endif
#ifndef INT_MIN
#  define INT_MIN std::numeric_limits<int>().min()
#endif
#define LL_MAX std::numeric_limits<ll>().max()
#define LL_MIN std::numeric_limits<ll>().min()
#define INF LL_MAX

#define REP(i,n) for(int i=0;i<n;++i)
#define SORT(name) sort(name.begin(), name.end())
// 配列の初期化
#define ZERO(p) memset(p, 0, sizeof(p))
// 配列の初期化(-1)
#define MINUS(p) memset(p, 1, sizeof(p))

// 素集合データ構造
struct UnionFind
{
  // par[i]：データiが属する木の親の番号。i == par[i]のとき、データiは木の根ノードである
  vector<int> par;
  // sizes[i]：根ノードiの木に含まれるデータの数。iが根ノードでない場合は無意味な値となる
  vector<int> sizes;

  UnionFind(int n) : par(n), sizes(n, 1) {
    // 最初は全てのデータiがグループiに存在するものとして初期化
    REP(i,n) par[i] = i;
  }

  // データxが属する木の根を得る
  int find(int x) {
    if (x == par[x]) return x;
    return par[x] = find(par[x]);  // 根を張り替えながら再帰的に根ノードを探す
  }

  // 2つのデータx, yが属する木をマージする
  void unite(int x, int y) {
    // データの根ノードを得る
    x = find(x);
    y = find(y);

    // 既に同じ木に属しているならマージしない
    if (x == y) return;

    // xの木がyの木より大きくなるようにする
    if (sizes[x] < sizes[y]) swap(x, y);

    // xがyの親になるように連結する
    par[y] = x;
    sizes[x] += sizes[y];
    // sizes[y] = 0;  // sizes[y]は無意味な値となるので0を入れておいてもよい
  }

  // 2つのデータx, yが属する木が同じならtrueを返す
  bool same(int x, int y) {
    return find(x) == find(y);
  }

  // データxが含まれる木の大きさを返す
  int size(int x) {
    return sizes[find(x)];
  }
};

// 頂点a, bをつなぐコストcostの（無向）辺
struct Edge
{
  int a, b, cost;

  // コストの大小で順序定義
  bool operator<(const Edge& o) const {
    return cost < o.cost;
  }
};

// 頂点数と辺集合の組として定義したグラフ
struct Graph
{
  int n;  // 頂点数
  vector<Edge> es;  // 辺集合

  // クラスカル法で無向最小全域木のコストの和を計算する
  // グラフが非連結のときは最小全域森のコストの和となる
  int kruskal() {
    // コストが小さい順にソート
    sort(es.begin(), es.end());

    UnionFind uf(n);
    int min_cost = 0;

    REP(ei, es.size()) {
      Edge& e = es[ei];
      if (!uf.same(e.a, e.b)) {
        // 辺を追加しても閉路ができないなら、その辺を採用する
        min_cost += e.cost;
        uf.unite(e.a, e.b);
      }
    }

    return min_cost;
  }
};

ll V;
vector< pair<ll, ll> > sx, sy; // 値、インデックス

int main()
{
    cin >> V;
    REP(i, V) {
        ll x, y;
        cin >> x >> y;
        sx.push_back(make_pair(x, i));
        sy.push_back(make_pair(y, i));
    }

    SORT(sx);
    SORT(sy);

    Graph g;
    g.n = V;
    REP(i, V-1) {
        Edge e;
        e.a = sx[i].second;
        e.b = sx[i+1].second;
        e.cost = abs(sx[i].first - sx[i+1].first);
        g.es.push_back(e);

        e.a = sy[i].second;
        e.b = sy[i+1].second;
        e.cost = abs(sy[i].first - sy[i+1].first);
        g.es.push_back(e);
    }

    printf("%d\n", g.kruskal());

    return 0;
}
