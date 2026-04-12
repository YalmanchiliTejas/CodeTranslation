#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<vector>
#include<map>
#include<set>
#include<string>
#include<queue>
#include<stack>
using namespace std;
#define MOD 1000000007
#define INF (1<<29)
#define LINF (1LL<<60)
#define EPS (1e-10)
typedef long long Int;
typedef pair<Int, Int> P;

Int n, m;
Int s, t, u, v, d;
Int dists[108000], distt[108000];
Int ways[108000], wayt[108000];
Int res;

vector<P> edge[108000];
bool done[108000];

Int  dfs(Int x, Int *way, Int *dist){
  if(way[x] != -1)return way[x];
  way[x] = 0;
  for(auto e: edge[x]){
    Int to = e.first;
    Int cost = e.second;
    if(dist[to] + cost == dist[x]){
      (way[x] += dfs(to, way, dist)) %= MOD;
    }
  }
  return way[x];
}

void dijkstra(Int s, Int t,Int *dist, Int *way){
  fill(dist, dist + n, LINF);
  dist[s] = 0;
  way[s] = 1;
  priority_queue<P, vector<P>, greater<P> > pq;
  pq.push(P(0, s));
  while(!pq.empty()){
    P tmp = pq.top();pq.pop();
    Int from = tmp.second;
    Int d = tmp.first;
    if(dist[from] < d)continue;
    for(auto e:edge[from]){
      Int to = e.first;
      Int cost = e.second;
      if(dist[to] > dist[from] + cost){
	dist[to] = dist[from] + cost;
	pq.push(P(dist[to], to));
      }
    }
  }
  fill(way, way + 108000, -1);
  way[s] = 1;
  for(int i = 0;i < n;i++)dfs(i, way, dist);
}



int main(){
  cin >> n >> m;
  cin >> s >> t;s--,t--;
  for(Int i = 0;i < m;i++){
    cin >> u >> v >> d;
    u--,v--;
    edge[u].push_back(P(v, d));
    edge[v].push_back(P(u, d));
  }
  dijkstra(s, t, dists, ways);
  dijkstra(t, s, distt, wayt);
  
  Int st = dists[t];
  for(Int i = 0;i < n;i++){
    if(dists[i] + distt[i] != st)continue;
    if(dists[i] == distt[i]){
      //      cout << i << " same " << ways[i] << " " << wayt[i] << endl;
      (res -= ways[i] * wayt[i] %MOD * ways[i] % MOD*wayt[i] % MOD) %MOD;
    }
    else{
      for(auto e:edge[i]){
	Int to = e.first;
	Int cost = e.second;
	if(dists[i] + cost + distt[to] != st)continue;
	//cout << i << " same " << ways[i] << " " << wayt[i] << endl;
	if(dists[i] * 2 < st & distt[to] * 2 < st){
	  (res -= ways[i] * wayt[to] %MOD *ways[i] % MOD * wayt[to] %MOD) %MOD;
	}
      }
    }
  }
  res += ways[t] * ways[t] % MOD;
  res %= MOD;
  if(res < 0)res += MOD;
  cout << res << endl;
  
  return 0;
}