#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <cstring>
#include <ctime>
#include <queue>
using namespace std;
typedef long long ll;
const int maxn = 10;

vector<int>e[maxn];
int n,ret,m;

bool vis[maxn];
void dfs(int u,int fa,int cnt){
  if(cnt==n){
    ret++;
    return;
  }
  for(int i=0;i<e[u].size();i++){
    int v = e[u][i];
    if(v==fa||vis[v])continue;
    vis[v]=1;
    dfs(v,u,cnt+1);
    vis[v]=0;
  }
}

int main() {
//  freopen("in.cpp","r",stdin);
  cin>>n>>m;
  for(int i=0;i<m;i++){
    int x,y;
    cin>>x>>y;
    e[x].push_back(y);
    e[y].push_back(x);
  }
  vis[1]=1;
  dfs(1,0,1);
  cout<<ret<<endl;
  return 0;
}
