#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define all(obj) (obj).begin(),(obj).end()
typedef pair<int,int> P;
typedef pair<ll,P> Edge;
struct unionfind{
  vector<int> par;
  vector<int> size;
  unionfind(int n):par(n),size(n,1){
    rep(i,n)par.at(i)=i;
  }
  int root(int x){
    if(par[x]==x)return x;
    return root(par[x]);
  }
  void unit(int x,int y){
    x=root(x);
    y=root(y);
    if(x==y)return;
    if(size[par[x]]<size[par[y]])swap(x,y);
    par[y]=x;
    size[x]+=size[y];
  }
  bool find(int x,int y){
    x=root(x);
    y=root(y);
    return x==y;
  }
};


int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  int n;cin>>n;
  vector<int> x(n),y(n);
  rep(i,n)cin>>x[i]>>y[i];
  vector<Edge> es;
  vector<int> id(n);
  iota(id.begin(),id.end(),0);
  sort(id.begin(),id.end(),[&](int i,int j){return x[i]<x[j];});
  rep(i,n-1){
    int u=id[i],v=id[i+1];
    es.push_back(Edge(x[v]-x[u],P(u,v)));
  }
  sort(id.begin(),id.end(),[&](int i,int j){return y[i]<y[j];});
  rep(i,n-1){
    int u=id[i],v=id[i+1];
    es.push_back(Edge(y[v]-y[u],P(u,v)));
  }
  sort(es.begin(),es.end());
  unionfind uf(n);
  ll ans=0;
  for(auto k:es){
    int u=k.second.first,v=k.second.second;
    if(uf.find(u,v))continue;
    ans+=k.first;
    uf.unit(u,v);
  }
  cout<<ans<<endl;
  return 0;
  }
