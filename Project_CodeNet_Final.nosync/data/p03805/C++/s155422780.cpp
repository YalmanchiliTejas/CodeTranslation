#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

  vector<int> to[30];
  vector<bool> seen; 
  int ans=0,n;

void dfs(int v){
  for(auto w : to[v]){
    if(seen[w])continue;
    seen[w]=true;
    dfs(w);
    seen[w]=false;
  }
  rep(i,n){
    if(!seen[i])return;
  }
  ans++;
  return;
}


int main() {
  int m;
  cin>>n>>m;
  rep(i,m){
    int a,b;
    cin>>a>>b;
    a--;b--;
    to[a].push_back(b);
    to[b].push_back(a);
  }
  seen.resize(n);
  seen[0]=true;
  dfs(0);
  cout<<ans<<endl;
}