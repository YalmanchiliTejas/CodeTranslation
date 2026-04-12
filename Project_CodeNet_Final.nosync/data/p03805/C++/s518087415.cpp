#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int n, m;
int vis[16];
vector<int> g[16];

ll dfs(int u, int c) {
  if(c == n)
    return 1;

  vis[u] = 1;

  ll cnt = 0;
  for(int v : g[u])
    if(not vis[v])
      cnt += dfs(v, c+1);

  vis[u] = 0;

  return cnt;
}

int main() {
  cin.tie(0);
  cin.sync_with_stdio(0);

  cin >> n >> m;
  while(m--) {
    int u, v;
    cin >> u >> v;
    g[u].emplace_back(v);
    g[v].emplace_back(u);
  }
  ll cnt = dfs(1, 1);
  cout << cnt;
}