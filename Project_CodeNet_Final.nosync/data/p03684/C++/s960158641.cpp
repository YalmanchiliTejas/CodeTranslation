#include<bits/stdc++.h>
using namespace std;
#define MAX_N 300000
#define MAX_E 300000
typedef pair<int,int> P;

int par[MAX_N];
int ran[MAX_N]; 

void init(int n){
  for(int i=0;i<n;i++){
    par[i]=i;
    ran[i]=0;
  }
}

int find(int x){
  if(par[x]==x)return x;
  else return par[x]=find(par[x]);
}

void unite(int x,int y){
  x=find(x);
  y=find(y);
  if(ran[x]<ran[y])par[x]=y;
  else {
    par[y]=x;
    if(ran[x]==ran[y])ran[x]++;

  }
}

bool same(int x,int y){
  return find(x)==find(y);
}

struct edge{int u,v,cost;};

bool comp(const edge& e1,const edge e2){
  return e1.cost < e2.cost;
}

edge es[MAX_E];
int V,E; //頂点数、辺数

int kruskal(){
  sort(es,es+E,comp);
  init(V);
  int res=0;
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
  cin>>V;
  vector<P> vx,vy;
  for(int i=0;i<V;i++){
    int x,y;
    cin>>x>>y;
    vx.push_back(P(x,i));
    vy.push_back(P(y,i));
  }
  sort(vx.begin(),vx.end());
  sort(vy.begin(),vy.end());
  int cnt=0;
  for(int i=1;i<vx.size();i++){
    int u=vx[i-1].second;
    int v=vx[i].second;
    int cost=vx[i].first-vx[i-1].first;
    es[cnt++]=(edge){u,v,cost};
  }
  
  for(int i=1;i<vy.size();i++){
    int u=vy[i-1].second;
    int v=vy[i].second;
    int cost=vy[i].first-vy[i-1].first;
    es[cnt++]=(edge){u,v,cost};
  }
  E=cnt;
  cout<<kruskal()<<endl;
  
  return 0;
}
