#include <bits/stdc++.h>
#include <string>
#include <vector>
#include <algorithm>
#define rep(i,w) for (int i = 0;i < (w); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;
int INF = 1e9;

vector<vector<int>> G(8);
int dfs(const int &ind,int n,bool seen[8]){
  bool all = true;
  for(int i = 0;i<n;i++) if(!seen[i]) all = false;
  if(all) return 1;
  int ret = 0;
  for(auto nv:G[ind]){
    if(seen[nv]) continue;
    seen[nv] = true;
    ret += dfs(nv,n,seen);
    seen[nv] = false;
  }
  return ret;
}

int main(){
  int n,m;
  cin >> n >> m;
  G.assign(n,vector<int>());
  rep(i,m){
    int a,b;cin >> a >> b;
    --a;--b;
    G[a].push_back(b);
    G[b].push_back(a);
  }

  bool seen[8];
  rep(i,n) seen[i] = false;
  seen[0] = true;
  
  cout << dfs(0,n,seen) << endl;
  
}