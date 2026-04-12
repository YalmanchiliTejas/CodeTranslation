#include <cstdio>
#include <algorithm>
#include <iostream>
#include <vector>
#include <string>
#include <map>
#define pii pair<int,int>
#define pb push_back
using namespace std;
int n,m;
vector<vector<int> > edge;
int vis[10];
int dfs(int i,int num){

  if(vis[i]==1) return 0;
  if(num+1==n) return 1;
  vis[i]=1;

  int j,tmp;
  tmp=0;
  for(j=0;j<edge[i].size();j++){
    if(vis[edge[i][j]]==0) tmp+=dfs(edge[i][j],num+1);
  }
  vis[i]=0;
  return tmp;
}

int main(void){

  int i,a,b;

  cin>>n>>m;
  for(i=0;i<=n;i++){
    vector<int> v;
    edge.pb(v);
    vis[i]=0;
  }

  for(i=0;i<m;i++){
    cin>>a>>b;
    edge[a].pb(b);
    edge[b].pb(a);
  }
  cout<<dfs(1,0)<<endl;

  return 0;
}