#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <algorithm>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <functional>
#include <utility>
#include <tuple>
#include <cctype>
#define INF 0x3f3f3f3f
#define MOD 1000000007
#define PI 4*atan(1.0)
typedef long long ll;
typedef long double ld;
using namespace std;
int dx[4]={0,0,-1,1};
int dy[4]={-1,1,0,0};
const int SIZE=200001;
//int arr[SIZE]={};
//ここまでテンプレ
#define REP(i,n) for(int i=0;i<(int)n;++i)
#define FOR(i,c) for(auto i=(c).begin();i!=(c).end();++i)
#define ALL(c) (c).begin(), (c).end()
typedef int Weight;
struct Edge {
  int src, dst;
  Weight weight;
  Edge(int src, int dst, Weight weight) :
    src(src), dst(dst), weight(weight) { }
};
bool operator < (const Edge &e, const Edge &f) {
  return e.weight != f.weight ? e.weight > f.weight : // !!INVERSE!!
    e.src != f.src ? e.src < f.src : e.dst < f.dst;
}
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

pair<Weight, Edges> minimumSpanningForest(const Graph &g) {
  int n = g.size();
  UnionFind uf(n);
  priority_queue<Edge> Q;
  REP(u, n) FOR(e, g[u]) if (u < e->dst) Q.push(*e);

  Weight total = 0;
  Edges F;
  while (F.size() < n-1 && !Q.empty()) {
    Edge e = Q.top(); Q.pop();
    if (uf.unionSet(e.src, e.dst)) {
      F.push_back(e);
      total += e.weight;
    }
  }
  return pair<Weight, Edges>(total, F);
}
int main(){
	Graph G;
	int N;
	cin>>N;
	for(int i=0;i<N;i++){
		Edges E;
		G.push_back(E);
	}
	vector<tuple<int,int,int>> X,Y;
	for(int i=0;i<N;i++){
		int x,y;
		cin>>x>>y;
		X.push_back(make_tuple(x,y,i));
		Y.push_back(make_tuple(y,x,i));
	}
	sort(X.begin(),X.end());
	sort(Y.begin(),Y.end());
	for(int i=1;i<N;i++){
		G[get<2>(X[i])].push_back(Edge(get<2>(X[i]),get<2>(X[i-1]),get<0>(X[i])-get<0>(X[i-1])));
		G[get<2>(X[i-1])].push_back(Edge(get<2>(X[i-1]),get<2>(X[i]),get<0>(X[i])-get<0>(X[i-1])));
		G[get<2>(Y[i])].push_back(Edge(get<2>(Y[i]),get<2>(Y[i-1]),get<0>(Y[i])-get<0>(Y[i-1])));
		G[get<2>(Y[i-1])].push_back(Edge(get<2>(Y[i-1]),get<2>(Y[i]),get<0>(Y[i])-get<0>(Y[i-1])));
	}

	cout<<minimumSpanningForest(G).first<<endl;
	return 0;
}