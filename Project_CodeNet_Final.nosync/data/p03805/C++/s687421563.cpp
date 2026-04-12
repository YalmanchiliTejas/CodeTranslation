#include<bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < n; i++)
#define pb push_back
using namespace std;
typedef long long ll;

int n,m;
vector<int> seen;
vector<vector<int>> g;
int ans = 0;
int p = 0;

void dfs(int v){
  seen[v] = p++;
  if(p==n) ans++;
  for(auto nv:g[v]){
    if(seen[nv]!=-1) continue;
    dfs(nv);
  }
  seen[v] = -1;
  p--;
}

int main(){
  cin>>n>>m;
  g.resize(n);
  rep(i,m){
    int a,b;
    cin>>a>>b;
    a--; b--;
    g[a].pb(b);
    g[b].pb(a);
  }
 
  seen.resize(n,-1);
  dfs(0);
  
  cout << ans << endl;
}