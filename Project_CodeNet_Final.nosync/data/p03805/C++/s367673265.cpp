#include <bits/stdc++.h>

using namespace std;


vector<int> g[9];
int bio[9];
int ans = 0;
int N, M;
int sumbio = 0;

void dfs(int u) {
  bio[u] = 1;
  sumbio++;
  if (sumbio == N) ans++;
  for (auto v : g[u]) {
    if (bio[v]) continue;
    dfs(v);
  }
  bio[u] = 0;
  sumbio--;
}


int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cin >> N >> M;
  for (int i = 0; i < M; ++i) {
    int u, v;
    cin >> u >> v;
    g[u].push_back(v);
    g[v].push_back(u);
  }
  dfs(1);
  cout << ans << endl;
  return 0;
}
