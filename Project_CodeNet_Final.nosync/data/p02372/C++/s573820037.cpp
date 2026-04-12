#include <bits/stdc++.h>

using namespace std;



struct edge
{
  int to, cost;
};

vector< edge > g[10000];
int depth[10000], ans[10000];

int dfs(int idx, int par = -1)
{
  for(auto &e : g[idx]) {
    if(par == e.to) continue;
    depth[idx] = max(depth[idx], dfs(e.to, idx) + e.cost);
  }
  return (depth[idx]);
}

void dfs2(int idx, int far = 0, int par = -1)
{
  vector< pair< int, int > > row;
  row.emplace_back(far, par);
  for(auto &e : g[idx]) {
    if(par == e.to) continue;
    row.emplace_back(depth[e.to] + e.cost, e.to);
  }
  sort(row.rbegin(), row.rend());
  ans[idx] = row.front().first;
  for(auto &e : g[idx]) {
    if(par == e.to) continue;
    dfs2(e.to, row[e.to == row.front().second].first + e.cost, idx);
  }
}


void solve()
{
  int N;
  cin >> N;
  for(int i = 1; i < N; i++) {
    int s, t, w;
    cin >> s >> t >> w;
    g[s].emplace_back((edge) {t, w});
    g[t].emplace_back((edge) {s, w});
  }
  dfs(0);
  dfs2(0);
  for(int i = 0; i < N; i++) {
    cout << ans[i] << endl;
  }
}

int main()
{
  cin.tie(0);
  ios::sync_with_stdio(false);
  solve();
}