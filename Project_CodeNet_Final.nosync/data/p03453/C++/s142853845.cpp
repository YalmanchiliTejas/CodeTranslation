#include <bits/stdc++.h>

using namespace std;

typedef long long lli;
typedef double lld;
typedef vector<lli> vll;
typedef vector<bool> vbl;
typedef vector<double> vdl;
typedef vector<vector<lli>> mat;
typedef vector<vdl> mad;
typedef unordered_map<lli,unordered_map<lli,lli>> graph;
typedef complex<double> cmp;
typedef vector<cmp> vcl;

const lli mod = 1000000007;

lli n,m;
lli s,t;
graph g;
priority_queue<vll,vector<vll>,greater<vll>> q;
vll dist,tsid,way,yaw;
mat edge;
vll mid_point;
lli ans = 0;

int main(){
  cin >> n >> m;
  cin >> s >> t;
  for(lli i = 0;i < m;i++){
    lli u,v,d;
    cin >> u >> v >> d;
    g[u][v] = g[v][u] = d;
    edge.push_back(vll({u,v,d}));
  }
  q.push(vll({0,s,0}));
  dist = vll(n+1,LONG_MAX);
  way = vll(n+1);
  way[0] = 1;
  while(!q.empty()){
    lli x = q.top()[1];
    lli d = q.top()[0];
    lli from = q.top()[2];
    q.pop();
    if(dist[x] < d) continue;
    way[x] += way[from];
    way[x] %= mod;
    if(dist[x] == LONG_MAX){
      dist[x] = d;
      for(auto& y : g[x]){
        q.push(vll({d+y.second,y.first,x}));
      }
    }
  }
  q.push(vll({0,t,0}));
  tsid = vll(n+1,LONG_MAX);
  yaw = vll(n+1);
  yaw[0] = 1;
  while(!q.empty()){
    lli x = q.top()[1];
    lli d = q.top()[0];
    lli from = q.top()[2];
    q.pop();
    if(tsid[x] < d) continue;
    yaw[x] += yaw[from];
    yaw[x] %= mod;
    if(tsid[x] == LONG_MAX){
      tsid[x] = d;
      for(auto& y : g[x]){
        q.push(vll({d+y.second,y.first,x}));
      }
    }
  }
  if(dist[t] != tsid[s] || dist[t] == LONG_MAX){
    cout << "programing error" << endl;
    return 1;
  }
  for(auto& x : edge){
    if(dist[x[0]]+tsid[x[1]]+x[2] == dist[t]){
      if(dist[x[0]]*2 < dist[t] && tsid[x[1]]*2 < dist[t]){
        mid_point.push_back((way[x[0]]*yaw[x[1]])%mod);
      }
    }else if(dist[x[1]]+tsid[x[0]]+x[2] == dist[t]){
      if(dist[x[1]]*2 < dist[t] && tsid[x[0]]*2 < dist[t]){
        mid_point.push_back((way[x[1]]*yaw[x[0]])%mod);
      }
    }
  }
  for(lli i = 1;i <= n;i++){
    if(dist[i]*2 == dist[t]){
      mid_point.push_back((way[i]*yaw[i])%mod);
    }
  }
  lli sum = accumulate(mid_point.begin(),mid_point.end(),0ll)%mod;
  for(auto x : mid_point){
    ans += ((sum-x+mod)*x)%mod;
    ans %= mod;
  }
  cout << ans << endl;
  return 0;



}
