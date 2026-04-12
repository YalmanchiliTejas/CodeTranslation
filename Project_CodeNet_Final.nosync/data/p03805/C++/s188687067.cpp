#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
const int INF = 1<<30;
int n, m;
int dfs(int v, vector<bool> &visited, vector<vector<bool>> &edge){
  bool all_visited = true;
  for(int i=0;i<n;i++){
  	if(!visited[i]){all_visited=false;break;}
  }
  if(all_visited)return 1;
  int ret=0;
  for(int i=0;i<n;i++){
  	if(!edge[v][i] || visited[i])continue;
    visited[i]=true;
    ret+=dfs(i, visited, edge);
    visited[i]=false;
  }
  return ret;
}

int main(){
  cin>>n>>m;
  vector<bool> visited(n, false);
  vector<vector<bool>> edge(n, vector<bool>(n));
  for(int i=0;i<m;i++){
  	int a, b;cin>>a>>b;a--;b--;
    edge[a][b]=edge[b][a]=true;
  }
  visited[0]=true;
  cout<<dfs(0, visited, edge)<<endl;
}
