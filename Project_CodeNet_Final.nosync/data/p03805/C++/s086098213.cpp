#include<bits/stdc++.h>
using namespace std;
vector<vector<int>>E(100);
int ans=0;
int n,m;
void dfs(int now,int vis){
  if(vis==(1<<n)-1){ans++;return;}
  for(auto a:E[now]){
    if(!(vis&(1<<a))){
      dfs(a,vis|(1<<a));
    }
  }
  return;
}
int main(){
  cin>>n>>m;
  for(int i=0;i<m;i++){
    int a,b;cin>>a>>b;
    E[--a].push_back(--b);
    E[b].push_back(a);
  }
  dfs(0,1);
  cout<<ans<<endl;
}
