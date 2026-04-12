#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long LL;
struct X{
	int id;
	LL x;
	LL y;
	X(){
		id=0;
		x=0;
		y=0;
	}
	X(int _id,LL _x,LL _y){
		id=_id;
		x=_x;
		y=_y;
	}
	LL getCost(X &x1){
		LL X1=x-x1.x;
		if (X1<0){
			X1=-X1;
		}
		LL Y1=y-x1.y;
		if (Y1<0){
			Y1=-Y1;
		}
		if (X1<Y1){
			return X1;
		}else{
			return Y1;
		}
	}
};
struct EDGE{
	X p1;
	X p2;
	LL cost;
	EDGE(X _p1,X _p2){
		p1=_p1;
		p2=_p2;
		cost=p1.getCost(p2);
	}
  // コストの大小で順序定義
  bool operator<(const EDGE& o) const {
    return cost < o.cost;
  }
	bool find(const EDGE &edge){
		if (p1.id==edge.p1.id && p2.id==edge.p2.id){
			return true;
		}
		if (p1.id==edge.p2.id && p2.id==edge.p1.id){
			return true;
		}
		return false;
	}

};
bool SortX(X &x1,X &x2){
	if (x1.x<x2.x){
		return true;
	}
	return false;
}
bool SortY(X &x1,X &x2){
	if (x1.y<x2.y){
		return true;
	}
	return false;
}
// 素集合データ構造
struct UnionFind
{
  // par[i]：データiが属する木の親の番号。i == par[i]のとき、データiは木の根ノードである
  vector<int> par;
  // sizes[i]：根ノードiの木に含まれるデータの数。iが根ノードでない場合は無意味な値となる
  vector<int> sizes;

  UnionFind(int n) : par(n), sizes(n, 1) {
    // 最初は全てのデータiがグループiに存在するものとして初期化
	  for (int i=0;i<n;i++){
		par[i] = i;
	  }
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
    sizes[y] = 0;  // sizes[y]は無意味な値となるので0を入れておいてもよい
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

// 頂点数と辺集合の組として定義したグラフ
struct Graph
{
  int n;  // 頂点数
  vector<EDGE> edges;  // 辺集合

  // クラスカル法で無向最小全域木のコストの和を計算する
  // グラフが非連結のときは最小全域森のコストの和となる
  LL kruskal() {
    // コストが小さい順にソート
    sort(edges.begin(), edges.end());

    UnionFind uf(n);
    LL min_cost = 0;

    for (int i=0;i<edges.size();i++) {
      EDGE& e = edges[i];
	  if (!uf.same(e.p1.id, e.p2.id)) {
        // 辺を追加しても閉路ができないなら、その辺を採用する
        min_cost += e.cost;
		uf.unite(e.p1.id, e.p2.id);
      }
    }

    return min_cost;
  }
};

int main(int argc, char* argv[])
{
	int N;
	cin>>N;
	vector<X> City;
	int i;
	LL x,y;
	for (i=0;i<N;i++){
		cin>>x>>y;
		City.push_back(X(i,x,y));
	}
	sort(City.begin(),City.end(),SortX);
	Graph graph;
	graph.n=N;
	for (i=0;i<N-1;i++){
		EDGE edge(City[i],City[i+1]);
		graph.edges.push_back(edge);
	}
	sort(City.begin(),City.end(),SortY);
	for (i=0;i<N-1;i++){
		EDGE edge(City[i],City[i+1]);
		graph.edges.push_back(edge);
	}
	cout << graph.kruskal() << endl;
	return 0;
}