#include <iostream>
#include <vector>
#include <queue>
#include <utility>
using namespace std;

long long int INF = (1e15), mod = 1e9 + 7;
#define int long long

struct Edge{
  int cost, from, to;
  Edge(int cost, int from, int to):
    cost(cost), from(from), to(to) {}
};

bool operator<(const Edge& a, const Edge& b){
  return a.cost != b.cost ? a.cost < b.cost : a.from != b.from ? a.from < b.from : a.to < b.to;
}

int solve(vector< vector< pair<int,int> > > &G, int s, int t){
  int n = G.size();
  vector<int> D(n,INF), C(n,0), D_rev(n,INF), C_rev(n,0);
  C[s] = 1;
  C_rev[t] = 1;
  priority_queue< Edge > wait;
  wait.emplace(0,s,s);
  while(!wait.empty()){
    int d = -wait.top().cost, v = wait.top().to, from = wait.top().from;
    wait.pop();
    if(d > D[v]) continue;
    if(d == D[v]){
      C[v] += C[from];
      C[v] %= mod;
      continue;
    }else{
      C[v] = C[from];
      D[v] = d;
    }
    for(int i = 0; i < G[v].size(); ++i){
      int d_ = G[v][i].first, v_ = G[v][i].second;
      if(d + d_ <= D[v_]) wait.emplace(-(d+d_),v,v_);
    }
  }
  wait.emplace(0,t,t);
  while(!wait.empty()){
    int d = -wait.top().cost, v = wait.top().to, from = wait.top().from;
    wait.pop();
    if(d > D_rev[v]) continue;
    if(d == D_rev[v]){
      C_rev[v] += C_rev[from];
      C_rev[v] %= mod;
      continue;
    }else{
      C_rev[v] = C_rev[from];
      D_rev[v] = d;
    }
    for(int i = 0; i < G[v].size(); ++i){
      int d_ = G[v][i].first, v_ = G[v][i].second;
      if(d + d_ <= D_rev[v_]) wait.emplace(-(d+d_),v,v_);
    }
  }
  /*
  for(int i = 0; i < n; ++i) cout << D[i] << " " ;
  cout << endl;
  for(int i = 0; i < n; ++i) cout << D_rev[i] << " " ;
  cout << endl;
  for(int i = 0; i < n; ++i) cout << C[i] << " " ;
  cout << endl;
  for(int i = 0; i < n; ++i) cout << C_rev[i] << " " ;
  cout << endl;
  */

  int ans = (C[t]*C[t])%mod;
  //cout << ans << endl;
  int min_time = D[t];
  for(int i = 0; i < n; ++i){
    if(2*D[i] == min_time && D[i] == D_rev[i]){
      ans -= (((C[i]*C_rev[i])%mod)*((C[i]*C_rev[i])%mod))%mod;
      ans += mod;
      ans %= mod;
    }
  }
  for(int i = 0; i < n; ++i){
    if(2*D[i] >= min_time) continue;
    for(int j = 0; j < G[i].size(); ++j){
      int v = G[i][j].second, d = G[i][j].first;
      if(D[i]+D_rev[v]+d == min_time &&
         2*D[i] < min_time && 2*D_rev[v] < min_time){
        ans -= (((C[i]*C_rev[v])%mod)*((C[i]*C_rev[v])%mod))%mod;
        //cout << i << " " << v << endl;
        ans += mod;
        ans %= mod;
      }
    }
  }
  return ans;
}

signed main(){
  int n, m, s, t;
  cin >> n >> m >> s >> t;
  --s;--t;
  vector< vector< pair<int,int> > > G(n);
  int u, v, d;
  for(int i = 0; i < m; ++i){
    cin >> u >> v >> d;
    --u;--v;
    G[u].emplace_back(d,v);
    G[v].emplace_back(d,u);
  }
  cout << solve(G,s,t) << endl;
  return 0;
}
