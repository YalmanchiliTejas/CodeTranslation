#include<bits/stdc++.h>
using namespace std;
using Int = long long;
template<typename T1,typename T2> inline void chmin(T1 &a,T2 b){if(a>b) a=b;}
template<typename T1,typename T2> inline void chmax(T1 &a,T2 b){if(a<b) a=b;}


template<typename T>
struct Kruskal{
  
  struct edge{
    Int from,to;
    T cost;
    Int used;
    edge(){}
    edge(Int from,Int to,T cost):
      from(from),to(to),cost(cost),used(0){}
    bool operator<(const edge& e) const{
      return cost<e.cost;
    }
  };

  Int n;
  vector<Int> p,r;
  vector<edge> edges;

  Kruskal(){}
  Kruskal(Int n):n(n){}

  void init(Int n){
    r.assign(n,1);
    p.resize(n);
    iota(p.begin(),p.end(),0);
  }
  
  Int find(Int x){
    return (x==p[x]?x:p[x]=find(p[x]));
  }

  bool same(Int x,Int y){
    return find(x)==find(y);
  }

  void unite(Int x,Int y){
    x=find(x);y=find(y);
    if(x==y) return;
    if(r[x]<r[y]) swap(x,y);
    r[x]+=r[y];
    p[y]=x;
  }

  void add_edge(Int u,Int v,T c){
    edges.emplace_back(u,v,c);
  }
  
  T build(){
    sort(edges.begin(),edges.end());
    init(n);
    T res=0;
    for(auto &e:edges){
      if(!same(e.from,e.to)){
        res+=e.cost;
        unite(e.from,e.to);
        e.used=1;
      }
    }
    return res;
  }
};

//INSERT ABOVE HERE
signed main(){
  Int n;
  cin>>n;
  vector<Int> x(n),y(n);
  for(Int i=0;i<n;i++) cin>>x[i]>>y[i];

  Kruskal<Int> ks(n);

  using P = pair<Int, Int>;
  vector<P> vp;
  
  for(Int i=0;i<n;i++)
    vp.emplace_back(x[i],i);

  sort(vp.begin(),vp.end());
  for(Int i=1;i<n;i++){
    Int a=vp[i-1].second;
    Int b=vp[i].second;
    ks.add_edge(a,b,x[b]-x[a]);
  }

  vp.clear();
  
  for(Int i=0;i<n;i++)
    vp.emplace_back(y[i],i);
  
  sort(vp.begin(),vp.end());
  for(Int i=1;i<n;i++){
    Int a=vp[i-1].second;
    Int b=vp[i].second;
    ks.add_edge(a,b,y[b]-y[a]);
  }

  cout<<ks.build()<<endl;
  return 0;
}
