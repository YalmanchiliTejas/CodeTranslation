#include<iostream>
#define MAX_N 8
using namespace std;
int n,m;
bool g[MAX_N][MAX_N];
bool visited[MAX_N];
int ans;
void dfs(int v){
  visited[v]=true;
  for(int i=0;i<n;i++){
    if(v==i) continue;
    if(visited[i]) continue;
    if(g[v][i]) dfs(i);
  }
  bool path=true;
  for(int i=0;i<n;i++){
    if(!visited[i]) path=false;
  }
  if(path) ans++;
  visited[v]=false;
}
int main(void){
  cin>>n>>m;
  for(int i=0;i<n;i++){
    for(int j=0;j<n;j++){
      g[i][j]=false;
    }
  }
  for(int i=0;i<m;i++){
    int a,b;
    cin>>a>>b;
    a--;b--;
    g[a][b]=g[b][a]=true;
  }
  ans=0;
  for(int i=0;i<n;i++) visited[i]=false;
  dfs(0);
  cout<<ans<<endl;
  return 0;
}