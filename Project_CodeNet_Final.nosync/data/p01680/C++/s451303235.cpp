#include <bits/stdc++.h>
#define r(i,n) for(int i=0;i<n;i++)
using namespace std;

struct UnionFind{
  int n;
  vector<int> ran,p,cnt;
  UnionFind(){}
  UnionFind(int sz):n(sz),ran(sz,1),p(sz,0){iota(p.begin(),p.end(),0);}
  int find(int x){
    return (x==p[x]?x:p[x]=find(p[x]));
  }
  bool same(int x,int y){
    return find(x)==find(y);
  }
  void unite(int x,int y){
    x=find(x);y=find(y);
    if(x==y) return;
    if(ran[x]<ran[y]) swap(x,y);
    ran[x]+=ran[y];
    p[y]=x;
  }
  int sum(int x){
    return ran[find(x)];
  }
};

int n,m,a,b,ans;

signed main(){
  while(cin>>n>>m,n){
    ans=1;
    UnionFind U(n);
    r(i,m){
      cin>>a>>b;
      a--;b--;
      U.unite(a,b);
    }
    r(i,n)if(U.find(i)==i)ans=(ans*2)%1000000007;
    if(m)ans=(ans+1)%1000000007;
    cout<<ans<<endl;
  }
}
