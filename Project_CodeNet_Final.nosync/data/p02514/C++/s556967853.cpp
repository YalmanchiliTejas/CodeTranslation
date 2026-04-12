#include<iostream>
#include<climits>
#include<cstdlib>
#include<vector>
#include<algorithm>
using namespace std;

struct Edge{int f,t,c;};

const int N = 100;
bool vis[N],adj[N][N];
vector<Edge>all;
vector<int>edge[N];
void dfs(int now){
  if (vis[now])return;
  vis[now]=true;
  for(int i=0;i < edge[now].size();i++)
    if (adj[now][edge[now][i]])dfs(edge[now][i]);
}

bool isconnect(int n){
  fill(vis,vis+n,false);dfs(0);return count(vis,vis+n,true) == n;
}

int solve(int n){
  int ret=INT_MAX;
  if (!isconnect(n))return 0;
  for(int i=0;i < (int)all.size();i++){
    adj[all[i].f][all[i].t]=adj[all[i].t][all[i].f]=false;
    for(int j=i+1;j < (int)all.size();j++){
      adj[all[j].f][all[j].t]=adj[all[j].t][all[j].f]=false;
      if (!isconnect(n))ret=min(ret,all[i].c+all[j].c);
      adj[all[j].f][all[j].t]=adj[all[j].t][all[j].f]=true;
    }
    if (!isconnect(n))ret=min(ret,all[i].c);
    adj[all[i].f][all[i].t]=adj[all[i].t][all[i].f]=true;
  }
  return ret;
}

main(){
  int n,m;
  while(cin>>n>>m && n){
    all.clear();
    for(int i=0;i < n;i++){
      edge[i].clear();
      for(int j=0;j < n;j++){
	adj[i][j]=false;
      }
    }
    
    int ans=0;
    for(int i=0;i < m;i++){
      int f,t,c;
      cin>>f>>t>>c;
      if (c <= 0)ans+=c;
      else {
	all.push_back((Edge){f,t,c});
	edge[f].push_back(t);
	edge[t].push_back(f);
	adj[f][t]=adj[t][f]=true;
      }
    }
    cout << ans+solve(n) <<endl;
  }
  return false;
}