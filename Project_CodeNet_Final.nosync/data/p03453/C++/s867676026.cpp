#include <bits/stdc++.h>
using namespace std;
#define REP(i,a,n) for(int i=(a); i<(int)(n); i++)
#define rep(i,n) REP(i,0,n)
#define FOR(it,c) for(__typeof((c).begin()) it=(c).begin(); it!=(c).end(); ++it)
#define ALLOF(c) (c).begin(), (c).end()
typedef long long ll;
typedef unsigned long long ull;

#define MOD 1000000007

struct Edge {
  int src, dest;
  ll weight;
};
bool operator>(const Edge& a, const Edge& b){
  return a.weight > b.weight;
}

#define INF 100000000000000000LL

int N, M;
int S, T;
vector<Edge> G[100005];
ll costS[100005];
ll costT[100005];
ll dpS[100005];
ll dpT[100005];

void dijkstra(int start, int goal, ll* cost){
  rep(i,N+1){
    cost[i] = INF;
  }
  priority_queue<Edge,vector<Edge>,greater<Edge>> q;
  q.push((Edge){-1,start,0});
  
  ll min_time = 0;
  while(!q.empty()){
    Edge e=q.top();
    q.pop();
    if(cost[e.dest] != INF) continue;
    cost[e.dest]=e.weight;
    FOR(it,G[e.dest])
      if(cost[it->dest]==INF) q.push((Edge){it->src,it->dest,e.weight+it->weight});
  }
}

int dfs(int node, ll* cost, ll* dp){
  if(dp[node] != -1) return dp[node];
  if(cost[node] == 0) return dp[node] = 1;
  int ret = 0;
  FOR(it,G[node]){
    int dest = it->dest;
    ll weight = it->weight;

    if(cost[dest] + weight == cost[node]){
      ret += dfs(dest, cost, dp);
      ret %= MOD;
    }
  }
  return dp[node] = ret;
}


int main(){
  cin >> N >> M;
  cin >> S >> T;
  rep(i,M){
    int u, v;
    ll d;
    cin >> u >> v >> d;
    G[u].push_back((Edge){u,v,d});
    G[v].push_back((Edge){v,u,d});
  }

  rep(i,100005){
    dpS[i] = dpT[i] = -1;
  }
  
  dijkstra(S, T, costS);
  dijkstra(T, S, costT);

  dfs(T, costS, dpS);
  dfs(S, costT, dpT);

  ll ans1 = (dpS[T]%MOD) * (ll)(dpS[T]%MOD);
  ans1 %= MOD;
  ll ans2 = 0;
  
  rep(i,N){
    int node = i+1;

    if(2LL * costS[node] == costS[T]){
      ans2 += (((dpS[node]%MOD * (ll)(dpS[node]%MOD))%MOD) *
        ((dpT[node]%MOD * (ll)(dpT[node]%MOD))%MOD))%MOD;
      ans2 %= MOD;
    }
    
    FOR(it,G[node]){
      int dest = it->dest;
      ll weight = it->weight;
      if(costS[dest] + weight != costS[node]) continue;
      if(dpS[dest] == -1 || dpS[node] == -1) continue;
      if(dpT[dest] == -1 || dpT[node] == -1) continue;
      if(2LL * costS[dest] < costS[T] && costS[T] < 2LL * costS[node]){
        ans2 += (((dpS[dest]%MOD * (ll)(dpS[dest]%MOD))%MOD) *
                 ((dpT[node]%MOD * (ll)(dpT[node]%MOD))%MOD))%MOD;
        ans2 %= MOD;
      }
    }
  }

  ans1 += MOD - ans2;
  ans1 %= MOD;

  cout << ans1 << endl;
  return 0;
}

