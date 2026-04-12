#include<bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < n; i++)
#define pb push_back
using namespace std;
typedef long long ll;

int n,m;
vector<vector<int>> g;
vector<int> seen;
int ans = 0;
void dfs(int v,int pa = 1){
  seen[v] = 1;
  for(int nv : g[v]){
    if(seen[nv]) continue;
    if(pa == n-1) ans++;
    dfs(nv,pa+1);    
  }
  seen[v] = 0;
}
int main(){
  cin>>n>>m;
  g.resize(n);
  seen.resize(n);
  rep(i,m){
    int a,b;
    cin>>a>>b;
    a--; b--;
    g[a].pb(b); g[b].pb(a);
  }
  
  dfs(0);
  cout << ans << endl;
}
