#include "bits/stdc++.h"
using namespace std;
const int maxn  = 100100;
vector<pair<int, int> > nxt[maxn];
set<tuple<int, int, int> > direct;
long long dist[maxn], ways[maxn];
const long long inf = 1ll<<60;
const long long mod = 1000000007;
long long aug(int s){
  if(ways[s] != -1) return ways[s];
  long long ans = 0;
  for(auto e : nxt[s]){
    int v, w;
    tie(v, w) = e;
    if(dist[v] == dist[s] + w){
      ans += aug(v);
      if(ans >= mod) ans -= mod;
    }
  }
  return ways[s] = ans;
}
int n;
void djk(int s, int t){
  for(int e = 0; e < maxn; e++) dist[e] = inf;
  priority_queue<pair<long long, int> > pq;
  pq.push({0, s});
  dist[s] = 0;
  while(!pq.empty()){
    long long dis; int cur;
    tie(dis, cur) = pq.top(); pq.pop();
    dis *= -1;
    if(dis != dist[cur]) continue;
    for(auto e : nxt[cur]){
      int v, w;
      tie(v, w) = e;
      if(dist[v] > dist[cur] + w){
        dist[v] = dist[cur] + w;
        pq.push({-dist[v], v});
      }
    }
  }
  memset(ways, -1, sizeof(ways));
  ways[t] = 1;
  aug(s);
  direct.clear();
  for(int u = 0; u < n; u++){
    for(auto e : nxt[u]){
      int v, w;
      tie(v, w) = e;
      if(dist[v] == dist[u] + w){
        direct.insert(make_tuple(u, v, w));
      }
    }
  }
  for(int u = 0; u < n; u++) if(ways[u] == -1) ways[u] = 0;
}
int MAIN(){
  int m;
  if(!(cin >> n >> m)) return 0;
  for(int e = 0; e < n; e++) nxt[e].clear();
  int s, t;
  cin >> s >> t; s--; t--;
  for(int e = 0; e < m; e++){
    int u, v, w;
    scanf("%d %d %d", &u, &v, &w);
    u--; v--;
    nxt[u].push_back({v, w});
    nxt[v].push_back({u, w});
  }
  djk(s, t);
  vector<long long> ways_s(n, 0);
  vector<long long> dist_s(n, 0);
  for(int e = 0; e < n; e++) ways_s[e] = ways[e];
  for(int e = 0; e < n; e++) dist_s[e] = dist[e];
  set<tuple<int, int, int> > dir_s = direct;
  djk(t, s);
  vector<long long> ways_t(n, 0);
  vector<long long> dist_t(n, 0);
  for(int e = 0; e < n; e++) ways_t[e] = ways[e];
  for(int e = 0; e < n; e++) dist_t[e] = dist[e];
  set<tuple<int, int, int> > dir_t = direct;
  long long walk = dist_s[t];
  long long ans = ways_s[s] * ways_t[t] % mod;
  auto mul = [&](long long a, long long b){
      return a * b % mod;
  };
  for(auto e : dir_s){
    int u, v, w; tie(u, v, w) = e;
    if(dir_t.count(make_tuple(v, u, w))){
      if(dist_s[u] + dist_t[v] + w != dist_s[t]) continue;
      // long long md = min(dist_s[u], dist_t[v]);
      if(dist_s[u] >= dist_s[t] / 2) continue;
      if(dist_t[v] >= dist_s[t] / 2) continue;
      // cout << "intersect at " << u << " " << v << endl;
      long long bad = mul(mul(mul(ways_s[v], ways_s[v]), ways_t[u]), ways_t[u]);
      ans -= bad;
      // cout << "bad "<< bad << endl;
      if(ans < 0) ans += mod;
    }
  }
  for(int e = 0; e < n; e++){
    if(dist_s[e] + dist_t[e] != walk) continue;
    if(dist_s[e] == dist_t[e]){
      long long bad = mul(mul(mul(ways_s[e], ways_s[e]), ways_t[e]), ways_t[e]);
      ans -= bad;
      if(ans < 0) ans += mod;
    }
  }
  cout << ans << endl;
  return 1;
}
int main(){
  while(MAIN());
  return 0;
}
