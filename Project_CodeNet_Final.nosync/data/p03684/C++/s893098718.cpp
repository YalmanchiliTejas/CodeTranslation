#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <cmath>
#include <map>
using namespace std;
typedef long long ll;
struct edge {int u,v,cost;};
int par[100001],Rank[100001];
edge es[200002];
int N;
bool comp(const edge& e1,const edge& e2){
  return e1.cost<e2.cost;
}

void init_union_find(int n){
  for(int i=0;i<n;i++){
    par[i]=i;
    Rank[i]=0;
  }
}

int find(int x){
  if(par[x]==x)return x;
  else return x=find(par[x]);
}
void unite(int x,int y){
  x=find(x);
  y=find(y);
  if(x==y)return ;
  if(Rank[x]<Rank[y]){
    par[x]=y;
  }
  else{
    par[y]=x;
    if(Rank[x]==Rank[y])Rank[x]++;
  }
}
bool same(int x,int y){
  return find(x) == find(y);
}
int main(){
  cin >> N;
  vector<pair<int ,int> > p(N),p2(N);
  for(int i=0;i<N;i++){
    int x,y;
    cin >> x >> y;
    p[i]=make_pair(x,i);
    p2[i]=make_pair(y,i);
  }
  sort(p.begin(),p.end());
  sort(p2.begin(),p2.end());

  for(int i=0;i<N-1;i++){
    es[i].u=p[i].second;
    es[i].v=p[i+1].second;
    es[i].cost=p[i+1].first-p[i].first;
   
  }

   for(int i=0;i<N-1;i++){
    es[N-1+i].u=p2[i].second;
    es[N-1+i].v=p2[i+1].second;
    es[N-1+i].cost=p2[i+1].first-p2[i].first;
  
  }
   sort(es,es+2*(N-1),comp);
   //for(int i=0;i<2*(N-1);i++)  printf("%d %d %d\n",es[i].u,es[i].v,es[i].cost);
   init_union_find(N);
   ll res=0;
   for(int i=0;i<2*(N-1);i++){
     edge e=es[i];
     if(!same(e.u,e.v)){
       unite(e.u,e.v);
       res+=e.cost;
     }
   }
   cout << res << endl;
  return 0; 
}
