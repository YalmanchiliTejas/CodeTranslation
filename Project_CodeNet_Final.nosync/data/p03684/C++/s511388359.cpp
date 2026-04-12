#include<iostream>
#include<vector>
#include<map>
#include<cstdlib>
#include<algorithm>

using namespace std;

struct point {
  int x,y,index;
};

//struct neighbor{
//  point 
//};

const int MAX_E = 400001;
struct edge{ int u, v, cost; };
edge es[MAX_E];
int V, E; // 頂点数と辺数

//--------Union-Find木------------
vector<int> par; // 親
vector<int> rnk; // 深さ

// Union-Find木の初期化
void init_union_find(int n) {
  par  = vector<int>(n);
  rnk = vector<int>(n);
  for (int i = 0; i < n; i++) {
    par[i] = i;
    rnk[i] = 0;
  }
}

// 木の根を求める
int find(int x) {
  if (par[x] == x) {
    return x;
  } else {
    return par[x] = find(par[x]);
  }
}

// xとyの属する集合を併合
void unite(int x, int y) {
  x = find(x);
  y = find(y);
  if (x == y) return;

  if (rnk[x] < rnk[y]) {
    par[x] = y;
  } else {
    par[y] = x;
    if (rnk[x] == rnk[y]) rnk[x]++;
  }
}

// xとyが同じ集合に属するか否か
bool same(int x, int y) {
  return find(x) == find(y);
}

//----------クラスカル法------------
bool comp(const edge& e1, const edge& e2) {
  return e1.cost < e2.cost;
}
int kruskal() {
  sort(es, es + E, comp); // edge.costの小さい順
  init_union_find(V); // Union-Findの初期化
  int res = 0;
  for (int i = 0; i < E; i++) {
    edge e = es[i];
    if (!same(e.u, e.v)) {
      unite(e.u, e.v);
      res += e.cost;
    }
  }
  return res;
}


bool compareX(const point &a, const point &b){
  return a.x < b.x;
}

bool compareY(const point &a, const point &b){
  return a.y < b.y;
}

int main(){
  int N;
  cin>>N;
  vector<point> data(N);
  for(int i=0;i<N;i++){
    cin>>data[i].x>>data[i].y;
    data[i].index=i;
  }
  vector<point> dataX,dataY;
  copy(data.begin(),data.end(),back_inserter(dataX));
  copy(data.begin(),data.end(),back_inserter(dataY));

  sort(dataX.begin(),dataX.end(),compareX);
  sort(dataY.begin(),dataY.end(),compareY);

  //vector<Edge> edges;
  //struct edge{ int u, v, cost; };
  //  int x,y,index;
  V = N;E = 0;
  for(int i=0;i<dataX.size()-1;i++){
    es[E].u=dataX[i].index;
    es[E].v=dataX[i+1].index;
    es[E].cost=min(abs(dataX[i].x-dataX[i+1].x),abs(dataX[i].y-dataX[i+1].y));
    E++;
  }
  for(int i=0;i<dataY.size()-1;i++){
    es[E].u=dataY[i].index;
    es[E].v=dataY[i+1].index;
    es[E].cost=min(abs(dataY[i].x-dataY[i+1].x),abs(dataY[i].y-dataY[i+1].y));
    E++;
  }
  int cost = kruskal();
  cout << cost <<endl;
  return 0;
  
}
