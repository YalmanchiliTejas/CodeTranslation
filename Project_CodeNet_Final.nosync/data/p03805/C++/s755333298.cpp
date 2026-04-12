#include <bits/stdc++.h>

using namespace std;

void dfs(int now, int bit, int complete, int &cnt, vector<vector<int>> &g){
  bit |= (1 << now);
  if(bit == complete){
    ++cnt;
    return;
  }
  for(const auto &x : g[now]){
    if((bit >> x) & 1) continue;
    dfs(x, bit, complete, cnt, g);
  }
}

int main() {
  int n, m;
  cin >> n >> m;
  vector<vector<int>> g(n);
  for(int i = 0; i < m; ++i){
    int a, b;
    cin >> a >> b;
    --a, --b;
    g[a].push_back(b);
    g[b].push_back(a);
  }
  int cnt = 0;
  dfs(0, 0, (1 << n) - 1, cnt, g);
  cout << cnt << endl;
  return 0;
}