#include<bits/stdc++.h>
using namespace std;
#define int long long

struct edge{ int to,cost; };
const int N = 2e5+10;
vector< edge > G[N];

struct TreeDP{
  vector<int> d; //始点(n/2とする)から最も遠い距離
  vector<int> dp; //各点から最も遠い距離
  void init(int n){
    d.resize(n+1); dp.resize(n+1);
  }

  void dfs1(int u,int par){
    for(auto e : G[u]){
      if(e.to == par) continue;
      dfs1(e.to,u);
      d[u] = max(d[u],d[e.to] + e.cost);
    }
  }

  int dfs2(int u,int d_par,int par){
    vector< pair<int,int> > d_child;
    d_child.push_back({0,-1}); //番兵
    for(auto e : G[u]){
      if(e.to == par) d_child.push_back({d_par + e.cost,e.to});
      else d_child.push_back({e.cost + d[e.to],e.to});
    }
    sort(d_child.rbegin(),d_child.rend());

    int res = d_child[0].first + d_child[1].first;
    dp[u] = d_child[0].first;
    for(auto e : G[u]){
      if(e.to == par) continue;
      int v = d_child[0].second == e.to;
      res = max(res,dfs2(e.to,d_child[v].first,u));
    }
    return res;
  }
}Tree;

signed main(){

  int n; cin >> n;
  for(int i = 0; i < n-1; i++){
    int s,t,w; cin >> s >> t >> w;
    G[s].push_back({t,w});
    G[t].push_back({s,w});
  }

  Tree.init(n);
  Tree.dfs1(n/2,-1);
  Tree.dfs2(n/2,0,-1);
  for(int i = 0; i < n; i++){
    cout << Tree.dp[i] << endl;
  }

  return 0;
}

