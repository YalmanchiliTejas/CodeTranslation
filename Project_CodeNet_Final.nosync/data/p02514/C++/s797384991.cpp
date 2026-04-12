#include<iostream>
#include<cstdio>
#include<cmath>
#include<climits>
#include<ctime>
#include<cstdlib>
#include<vector>
#include<algorithm>
#include<cassert>
using namespace std;
#define REP(i,b,n) for(int i=b;i<n;i++)
#define rep(i,n)   REP(i,0,n)
#define pb push_back
#define mp make_pair
#define ALL(C) (C).begin(),(C).end()
#define fi first
#define se second

const int N = 10000;
struct Edge{
  int to,cost;
};
//solve connected graph
vector<int> edgeOnCycle;//only cost is enough
vector<int> edgeOnTree;//only cost is enough
int minEdgeOnCycle[2];//[0] < [1]
int minEdgeOnTree;
vector<Edge> edge[N];//
int dig[N];//for assertion

int vis[N];
bool dfs(int now,int color){
  if (vis[now])return vis[now] == color;
  vis[now]=color;
  bool oncycle=false;
  rep(i,(int)edge[now].size()){
    bool tmp=dfs(edge[now][i].to,color);
    if (tmp){
      oncycle=true;
      if (edge[now][i].cost < minEdgeOnCycle[0]){
	minEdgeOnCycle[1]=minEdgeOnCycle[0];
	minEdgeOnCycle[0]=edge[now][i].cost;
      }else if (edge[now][i].cost < minEdgeOnCycle[1]){
	minEdgeOnCycle[1]=edge[now][i].cost;
      }
    }else minEdgeOnTree=min(minEdgeOnTree,edge[now][i].cost);
  }
  return oncycle;
}

//find connect ?
vector<int> udedge[N];//undirect
void dfs2(int now){
  if (vis[now])return;
  vis[now]=true;
  rep(i,(int)udedge[now].size()){
    dfs2(udedge[now][i]);
  }
}

bool isconnected(int n){
  rep(i,n)vis[i]=0;
  dfs2(0);
  rep(i,n){
    if (vis[i]==0)return false;
  }
  return true;
}

int solve(int n){
  if (!isconnected(n))return 0;
  int color=1;
  rep(i,n)vis[i]=0;
  rep(i,n){
    if (vis[i] == 0)dfs(i,color),color++;
  }
  if (minEdgeOnCycle[0] == INT_MAX)return minEdgeOnTree;
  return min(minEdgeOnCycle[0]+minEdgeOnCycle[1],minEdgeOnTree);
}

main(){
  int n,m;
  while(cin>>n>>m && n){
    rep(i,n){
      udedge[i].clear();
      edge[i].clear();
      dig[i]=0;
    }
    edgeOnCycle.clear();
    edgeOnTree.clear();
    minEdgeOnCycle[0]=INT_MAX;
    minEdgeOnCycle[1]=INT_MAX;
    minEdgeOnTree=INT_MAX;
    int ans=0;
    rep(i,m){
      int f,t,c;
      cin>>f>>t>>c;
      dig[t]++;
      if (c <= 0){//elminate negative edge (also negative seledge)
	ans+=c;//c<0
      }else if (f == t){//ignore self edge of positive cost
      }else {
	edge[f].push_back((Edge){t,c});
	udedge[f].push_back(t);
	udedge[t].push_back(f);
      }
    }
    rep(i,n)if (dig[i] >1)assert(false);

    int sum=solve(n);
    cout << ans+sum << endl;
  }
  return false;
}