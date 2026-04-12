#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
struct Edge{
  int u, v;
  ll w;
  Edge(){}
  Edge(int _u, int _v, ll _w) : u{_u}, v{_v}, w{_w}{}
  int other(int x){
    return x ^ u ^ v;
  }
};

const int N = 100001;
const int M = 200001;
const ll OO = 100000000000000000LL;
vector<int> adj[N];
Edge e[M];
ll waysS[N];
ll waysT[N];
ll distS[N];
ll distT[N];
const int MOD = 1e9 + 7;
void calc(int u, ll ways[], ll dist[]){
  for(int i = 0;i < N;i++)
    dist[i] = OO;
  dist[u] = 0;
  ways[u] = 1;
  priority_queue<pair<ll, int>> pr;
  pr.push({0, u});
  while(pr.size()){
    pair<ll, int> tp = pr.top();pr.pop();
    int cu = tp.second;
    ll cw = -tp.first;
    if(dist[cu] != cw)continue;
    for(auto el : adj[cu]){

      int v = e[el].other(cu);
      if(dist[cu] + e[el].w < dist[v]){
//        cout << v << endl;
        dist[v] = dist[cu] + e[el].w;
        ways[v] = ways[cu];
        pr.push({-dist[v], v});
      }else if(dist[cu] + e[el].w == dist[v]){
        ways[v] += ways[cu];
        ways[v] %= MOD;
      }
    }
  }
}
int main()
{
//  freopen("in.txt", "r", stdin);
//  freopen("out.txt", "w", stdout);
  int n, m;
  cin >> n >> m;
  int u, v, d;
  int s, t;
  cin >> s >> t;
  s--, t--;
  for(int i = 0;i < m;i++){
    cin >> u >> v >> d;
    u--, v--;
    e[i] = Edge(u, v, d);
    adj[u].push_back(i);
    adj[v].push_back(i);
  }
//  cout << distS[t] << endl;
//  return 0;
  calc(s, waysS, distS);
  calc(t, waysT, distT);
  ll res = waysS[t] * waysS[t] % MOD;
  ll D = distS[t];
//  cout << D << endl;
  for(int i = 0;i < n;i++){
    if(distS[i] == distT[i] && distS[i] + distT[i] == D)
      res -= waysS[i] * waysS[i] % MOD  * waysT[i] % MOD * waysT[i] % MOD;
    res %= MOD;
  }
  for(int i = 0;i < n;i++){
    for(auto el : adj[i]){
      Edge& ee = e[el];
      int u = i;
      int v = ee.other(u);
      int w = ee.w;
      if(distS[u] + w + distT[v] == D && 2 * distS[u] < D && 2 * distT[v] < D){
        res -= waysS[u] * waysS[u] % MOD * waysT[v] % MOD * waysT[v] % MOD;
        res %= MOD;
      }
    }
  }
  cout << (MOD + res) % MOD;
	return 0;
}
