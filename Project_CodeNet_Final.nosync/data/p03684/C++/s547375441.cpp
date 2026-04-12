#include<bits/stdc++.h>

#define INF 1e9
#define llINF 1e18
#define MOD 1000000007
#define pb push_back
#define mp make_pair 
#define F first
#define S second
#define ll long long
#define ALL(a) (a).begin(),(a).end()
#define Yes(hoge) cout<<((hoge)?"Yes":"No")<<endl;
#define YES(hoge) cout<<((hoge)?"YES":"NO")<<endl;
using namespace std;
#define rep(i,n) for (int i=0; i < int(n); i++)


// 素集合データ構造
struct UnionFind
{
  // par[i]：データiが属する木の親の番号。i == par[i]のとき、データiは木の根ノードである
  vector<ll> par;
  // sizes[i]：根ノードiの木に含まれるデータの数。iが根ノードでない場合は無意味な値となる
  vector<ll> sizes;

  UnionFind(ll n) : par(n), sizes(n, 1) {
    // 最初は全てのデータiがグループiに存在するものとして初期化
    rep(i,n) par[i] = i;
  }

  // データxが属する木の根を得る
  ll find(ll x) {
    if (x == par[x]) return x;
    return par[x] = find(par[x]);  // 根を張り替えながら再帰的に根ノードを探す
  }

  // 2つのデータx, yが属する木をマージする
  void unite(ll x, ll y) {
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
  bool same(ll x, ll y) {
    return find(x) == find(y);
  }

  // データxが含まれる木の大きさを返す
  ll size(ll x) {
    return sizes[find(x)];
  }
};

// 頂点a, bをつなぐコストcostの（無向）辺
struct Edge
{
  ll a, b, cost;

  // コストの大小で順序定義
  bool operator<(const Edge& o) const {
    return cost < o.cost;
  }
};

// 頂点数と辺集合の組として定義したグラフ
struct Graph
{
  ll n;  // 頂点数
  vector<Edge> es;  // 辺集合

  // クラスカル法で無向最小全域木のコストの和を計算する
  // グラフが非連結のときは最小全域森のコストの和となる
  ll kruskal() {
    // コストが小さい順にソート
    sort(es.begin(), es.end());

    UnionFind uf(n);
    ll min_cost = 0;

    rep(ei, es.size()) {
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

// 標準入力からグラフを読み込む
Graph input_graph(vector<pair<ll,ll> >x,vector<pair<ll,ll> >y) {
  Graph g;
  g.n=x.size();
  for(int i=1;i<x.size();i++){
    Edge e;
  e.a=x[i].S;
  e.b=x[i-1].S;
  e.cost=x[i].F-x[i-1].F;
    g.es.push_back(e);
  e.a=y[i].S;
  e.b=y[i-1].S;
  e.cost=y[i].F-y[i-1].F;
    g.es.push_back(e);
  }
  return g;
}

int main(){
  int n;cin>>n;
  vector<pair<ll,ll> >x(n);
  vector<pair<ll,ll> >y(n);
  for(int i=0;i<n;i++){
    cin>>x[i].F>>y[i].F;
    x[i].S=i;
    y[i].S=i;
  }
  sort(ALL(x));
  sort(ALL(y));
  Graph hoge = input_graph(x,y);
  cout<<hoge.kruskal()<<endl;
  return 0;
}
