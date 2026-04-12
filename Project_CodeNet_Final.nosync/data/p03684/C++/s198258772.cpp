#include <bits/stdc++.h>
using namespace std;

struct UnionFind{
  int n;
  vector<int> r,p;
  UnionFind(){}
  UnionFind(int sz):n(sz),r(sz,1),p(sz,0){iota(p.begin(),p.end(),0);}
  int find(int x){
    return (x==p[x]?x:p[x]=find(p[x]));
  }
  bool same(int x,int y){
    return find(x)==find(y);
  }
  void unite(int x,int y){
    x=find(x);y=find(y);
    if(x==y) return;
    if(r[x]<r[y]) swap(x,y);
    r[x]+=r[y];
    p[y]=x;
  }
};

int main(){
  int N;
  cin>>N;
  std::vector<int> x(N),y(N);
  for(int i=0;i<N;i++)cin>>x[i]>>y[i];
  typedef pair<int,int> P;
  std::vector<P> vx(N),vy(N);
  for(int i=0;i<N;i++){
    vx[i]=P(x[i],i);
    vy[i]=P(y[i],i);
  }
  sort(vx.begin(),vx.end());
  sort(vy.begin(),vy.end());
  typedef tuple<int,int,int> T;
  std::vector<T> w(N*2-2);
  for(int i=1;i<N;i++){
    w[i-1]=T(vx[i].first-vx[i-1].first,vx[i].second,vx[i-1].second);
    w[i-1+N-1]=T(vy[i].first-vy[i-1].first,vy[i].second,vy[i-1].second);
  }
  sort(w.begin(),w.end());
  UnionFind uf(N);
  int ans=0;
  for(int i=0;i<2*N-2;i++){
    int ww,ss,tt;
    tie(ww,ss,tt)=w[i];
    if(!uf.same(ss,tt)){
      ans+=ww;
      uf.unite(ss,tt);
    }
  }
  cout<<ans<<endl;
}
