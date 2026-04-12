#include <bits/stdc++.h>
using namespace std;

struct edge
{
  int to, cost;
};

vector< edge > g[100000];
long long dist[100000], ans[100000];


void dfs1(int idx, int par)//全方位木dp
{
  for(edge e : g[idx]) {
    if(e.to==par) continue;
    dfs1(e.to, idx);
    dist[idx] = max(dist[idx], dist[e.to] + e.cost);
  }
}

void dfs2(int idx, int d_par, int par)
{
  vector< pair< int, int > > d_child;
  d_child.push_back(make_pair(0, -1));
  for(edge &e : g[idx]) {
    if(e.to == par) d_child.push_back(make_pair(d_par + e.cost, e.to));
    else d_child.push_back(make_pair(e.cost + dist[e.to], e.to));
  }
  sort(d_child.rbegin(), d_child.rend());
  
  ans[idx] = max(d_child[0].first, d_child[1].first); 
  for(edge &e : g[idx]) {
    if(e.to == par) continue;
    dfs2(e.to, d_child[d_child[0].second == e.to].first, idx);
  }
}


int main()
{
  int N;
  cin >> N;
  for(int i = 0; i < N - 1; i++) {
    int a, b, w;
    cin >> a >> b >> w;
    g[a].push_back((edge) {b, w});
    g[b].push_back((edge) {a, w});
  }
  
  dfs1(0, -1);
  dfs2(0, 0, -1);
  for(int i=0; i<N; i++){
      cout << ans[i] << "\n";
  }
}
