#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <set>
#include <map>
#include <cmath>
#include <string>
#define FOR(i,a,b) for(int i=a;i<b;i++)
#define ROF(i,a,b) for(int i=b-1;i>=a;i--)
#define FI first
#define SE second
#define SI size()
#define MA(i,j) make_pair(i,j)
#define PA pair<int,int>
#define PF push_front
#define PB push_back
#define VE vector<int>
#define VP vector<PA>
#define LL long long
#define YES(i) cout<<(i?"YES":"NO")<<endl
#define Yes(i) cout<<(i?"Yes":"No")<<endl
using namespace std;
//
const int MOD=1e9+7;
const int INF=1e9+7;
//
int N;
int X[100000],Y[100000];
//
struct edge{int from,to,cost;};
//
bool comp(const edge& e1,const edge& e2){
  return e1.cost<e2.cost;
}
//
vector<edge> es;
int V,E;
//
int par[100000];//親
int runk[100000];//木の深さ
//初期化
void init(int n){
  FOR(i,0,n){
    par[i]=i;
    runk[i]=0;
  }
}
//木の根を求める
int find(int x){
  if(par[x]==x){
    return x;
  }else{
    return par[x]=find(par[x]);
  }
}
//Xの属する集合とYの属する集合を併合
void unite(int x,int y){
  x=find(x);
  y=find(y);
  if(x==y){
    return;
  }
  if(runk[x]<runk[y]){
    par[x]=y;
  }else{
    par[y]=x;
    if(runk[x]==runk[y]){
      runk[x]++;
    }
  }
}
//XとYが同じ集合に属するか否か
bool same(int x,int y){
  return  find(x)==find(y);
}
//
long long kruskal(){
  sort(es.begin(),es.end(),comp);
  init(V);
  long long res=0;
  FOR(i,0,E){
    edge e=es[i];
    if(!same(e.from,e.to)){
      unite(e.from,e.to);
      res+=e.cost;
    }
  }
  return res;
}
//
int main(){
  cin>>N;
  VP x,y;
  FOR(i,0,N){
    cin>>X[i]>>Y[i];
    x.PB(MA(X[i],i));
    y.PB(MA(Y[i],i));
  }
  sort(x.begin(),x.end());
  sort(y.begin(),y.end());
  V=N;
  E=2*(N-1);
  FOR(i,0,N-1){
    int num1=x[i].SE,num2=x[i+1].SE;
    es.PB({num1,num2,min(abs(X[num1]-X[num2]),abs(Y[num1]-Y[num2]))});
    num1=y[i].SE;num2=y[i+1].SE;
    es.PB({num1,num2,min(abs(X[num1]-X[num2]),abs(Y[num1]-Y[num2]))});
  }
  cout<<kruskal()<<endl;
  return 0;
}
