#include <bits/stdc++.h>
using namespace std;

int n,m,ans;
vector<bool> vis;
vector<vector<int>> tree;

void dfs(int x,int count){
  if(count==n){
    ans++;
    return;
  }
  vis[x]=true;
  for(int i=0;i<tree[x].size();i++){
    if(vis[tree[x][i]]) continue;
    dfs(tree[x][i],count+1);
  }
  vis[x]=false;
  return;
}

int main(){
  cin>>n>>m;
  tree.resize(n); vis.resize(n,false);
  for(int i=0;i<m;i++){
    int a,b; cin>>a>>b;
    a--; b--;
    tree[a].push_back(b);
    tree[b].push_back(a);
  }
  ans=0;
  dfs(0,1);
  cout<<ans<<endl;
}