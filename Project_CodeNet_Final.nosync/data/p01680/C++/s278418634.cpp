#include <bits/stdc++.h>

#define REP(i,n) for(int i=0;i<(int)(n);i++)

using namespace std;

struct UnionFind {
  vector<int> parent;
  UnionFind (int n) { parent.assign(n, -1); }
  int root(int x) { return parent[x] < 0 ? x : parent[x] = root(parent[x]); }
  bool merge(int x, int y) {
    x = root(x); y = root(y);
    if (x == y) return false;
    if (parent[y] < parent[x]) swap(x, y);
    if (parent[x] == parent[y]) --parent[x];
    parent[y] = x;
    return true;
  }
};

const int MOD = 1000000007;

int p2(int n){
  if(n==0) return 1;
  else return (p2(n-1)*2)%MOD;
}

int main() {
  while(1){
    int n,m;
    cin>>n>>m;
    if(!n)break;
    UnionFind uf(n);
    REP(i,m){
      int a,b;
      cin>>a>>b;
      --a;--b;
      uf.merge(a,b);
    }
    set<int> s;
    REP(i,n) s.insert(uf.root(i));
    if(s.size()==n){
      cout<<p2(n)<<endl;
    }else{
      int p=p2(s.size())+1;
      p%=MOD;
      cout<<p<<endl;
    }
  }
  return 0;
}