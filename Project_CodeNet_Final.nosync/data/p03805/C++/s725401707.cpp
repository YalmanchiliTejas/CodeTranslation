#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int n,m;
bool u[10]={false};
vector<int> g[10];
int dfs(int v,int uv);

int main(void){
  int i,a,b;
  cin >> n >> m;
  for (i=0;i<m;i++){
    cin >> a >> b;
    g[a].push_back(b);
    g[b].push_back(a);
  }
  u[1]=true;
  cout << dfs(1,1) << endl;
  return 0;
}

int dfs(int v,int uv){
  int i,ret=0;
  if (uv==n) return 1;
  for (i=0;i<g[v].size();i++){
    if (u[g[v][i]]) continue;
    u[g[v][i]]=true;
    ret+=dfs(g[v][i],uv+1);
    u[g[v][i]]=false;
  }
  return ret;
}