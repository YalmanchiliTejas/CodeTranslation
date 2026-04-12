#include <bits/stdc++.h>
using namespace std;

const int MAX = 8;
vector<int> G[MAX];
int ans = 0;

void dfs(int now, int n, vector<int> order) {
  if (order.size() == n) {
    ans++;
    return;
  }
  for (int i = 0; i < G[now].size(); i++) {
    bool flag = true;
    for (int j = 0; j < order.size(); j++) {
      if (G[now][i] == order.at(j)) flag = false;
    }
    if (flag) {
      order.emplace_back(G[now][i]);
      dfs(G[now][i], n, order);
      order.pop_back();
    }
  }
  return;
}

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  
  // 無向(有向)グラフの隣接リスト
  int n, m; // n:頂点数 m:辺数
  cin >> n >> m;
  
  // vector<int> G[n]; // G:頂点数がnのグラフを表す隣接リスト
  
  for (int i = 0; i < m; i++) {
    int u, v;
    cin >> u >> v;
    u--;
    v--;
    G[u].emplace_back(v);
    G[v].emplace_back(u); // 有向グラフではこの行をコメントアウト
  }
  
  vector<int> x = {0};
  dfs(0, n, x);
  
  cout << ans << '\n';
}