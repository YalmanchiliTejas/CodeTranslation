#include <bits/stdc++.h>
#define rep(i,n)for(long long i=0;i<(n);i++)
using namespace std;
typedef long long ll;
const int MOD=998244353;
const int MAX = 510000;
const int INF = 1e9;
const double pi=acos(-1);

struct UnionFind {
    vector<int> par;
    
    UnionFind(int n) : par(n, -1) { }

    int root(int x) {
        if (par[x] < 0) return x;
        else return par[x] = root(par[x]);
    }
    
    bool issame(int x, int y) {
        return root(x) == root(y);
    }
    
    bool merge(int x, int y) {
        x = root(x); y = root(y);
        if (x == y) return false;
        if (par[x] > par[y]) swap(x, y); // merge technique
        par[x] += par[y];
        par[y] = x;
        return true;
    }
    
    int size(int x) {
        return -par[root(x)];
    }
};

int main(){
  ll a,b,c,x,y;
  cin >> a >> b >> c >> x >> y;
  ll ans=1e9;
  rep(i,max(x,y)+1){
    ans=min(ans,i*2*c+max(x-i,0ll)*a+max(y-i,0ll)*b);
  }
  cout << ans << endl;
  return 0;
  
  
}