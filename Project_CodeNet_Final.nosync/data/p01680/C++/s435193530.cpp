#include<bits/stdc++.h>
using namespace std;
#define int long long
struct UnionFind{
  vector<int> r,p;
  UnionFind(){}
  UnionFind(int size){init(size);}
  void init(int size){
    r.resize(size,0);
    p.resize(size,0);
    for(int i=0;i<size;i++) r[i]=1,p[i]=i;
  }
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

signed main(){
  int n,m;
  int MOD=1000000007LL;
  while(cin>>n>>m,n||m){
    UnionFind uf(n);
    for(int i=0;i<m;i++){
      int x,y;
      cin>>x>>y;
      x--;y--;
      uf.unite(x,y);
    }
    int ans=1;
    for(int i=0;i<n;i++) if(uf.find(i)==i) (ans*=2)%=MOD;
    if(m) (ans+=1)%=MOD;
    cout<<ans<<endl;
  }
  return 0;
}