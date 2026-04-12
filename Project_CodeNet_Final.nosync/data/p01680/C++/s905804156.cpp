#include<bits/stdc++.h>
#define rank Gacho_0716
#define M 1000000007
using namespace std;

class UF{
public:
  int V;
  vector<int> par,rank;
  UF(){}
  UF(int V):V(V),par(V),rank(V,0){for(int i=0;i<V;i++)par[i]=i;}
  
  int find(int x){
    assert(x < V);
    if(par[x]==x)return x;
    return par[x]=find(par[x]);
  }
  
  void unite(int x,int y){
    x=find(x), y=find(y);
    if(x==y)return;
    if(rank[x]<rank[y])par[x]=y;
    else{
      par[y]=x;
      if(rank[x]==rank[y])rank[x]++;
    }
  }

  bool same(int x,int y){return find(x)==find(y);}
};

set<int> memo;

int main(){
  
  while(1){
    
    int n, m;
    
    cin>>n>>m;
    if(!n&&!m) break;
    
    UF uf = UF(n);
    
    for(int i=0;i<m;i++){
      int a, b;
      cin>>a>>b;
      a--, b--;
      uf.unite(a,b);
    }
    
    memo.clear();
    
    for(int i=0;i<n;i++) memo.insert(uf.find(i));
    
    int x=1, y=1;
    
    for(int i=0;i<n;i++) x=x*2%M;
    
    for(int i=0;i<memo.size();i++) y=y*2%M;

    cout<<(y%M + (x!=y))%M<<endl;
  }
  
  return 0;
}