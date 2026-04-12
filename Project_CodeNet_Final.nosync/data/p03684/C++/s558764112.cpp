#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
#define MOD 1000000007

const int MAX_N=100000;
int N;

int par[MAX_N]; //　親
int rnk[MAX_N]; // rank, 木の深さ

// N要素で初期化
void init(){
  for(int i=0;i<N;i++){
    par[i]=i;
    rnk[i]=0;
  }
}

// 木の根を求める
int find(int x){
  if (par[x] == x){
    return x;
  }else{
    return par[x] = find(par[x]);
  }
}

// ｘとｙの属する集合を併合
void unite(int x, int y){
  x = find(x);
  y = find(y);
  if (x == y) return;

  if (rnk[x] < rnk[y]){
    par[x] = y;
  }else{
    par[y] = x;
    if (rnk[x] == rnk[y]) rnk[x]++;
  }
}

// ｘとｙが同じ集合に属するかどうか
bool same(int x, int y){
  return find(x) == find(y);
}


const int MAX_E=MAX_N*4;
struct edge {int u, v;ll cost;};

bool comp(const edge& e1, const edge& e2){
  return e1.cost<e2.cost;
}

edge es[MAX_E];
int V,E;

ll kruskal(){
  V=N;
  sort(es,es+E,comp);
  init();
  ll res=0;
  for(int i=0;i<E;i++){
    edge e=es[i];
    if(!same(e.u,e.v)){
      unite(e.u,e.v);
      res+=e.cost;
    }
  }
  return res;
}


int main(){
  cin>>N;
  vector<pair<ll,int>> x(N), y(N);
  for(int i=0;i<N;i++){
    cin>>x[i].first>>y[i].first;
    x[i].second=y[i].second=i;
  }
  sort(x.begin(),x.end());
  sort(y.begin(),y.end());
  for(int i=0;i<N-1;i++){
    int a=x[i].second, b=x[i+1].second;
    ll c=x[i+1].first-x[i].first;
    es[i]={a,b,c};
    es[i+N]={b,a,c};
  }
  for(int i=0;i<N-1;i++){
    int a=y[i].second, b=y[i+1].second;
    ll c=y[i+1].first-y[i].first;
    es[i+2*N]={a,b,c};
    es[i+3*N]={b,a,c};
  }
  V=N;
  E=(N-1)*4;
  cout<<kruskal()<<endl;
  return 0;
}
