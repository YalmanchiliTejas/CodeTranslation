#include <bits/stdc++.h>

using namespace std;

void dfs(int pos, int bit, vector<int> &p, int n, vector<vector<bool>> &g, int &cnt){
  if(pos == n){
    if(p[0] != 0) return;
    for(int i = 0; i < n - 1; ++i){
      if(!g[p[i]][p[i + 1]]) return;
    }
    ++cnt;
  }
  for(int i = 0; i < n; ++i){
    if((bit >> i) & 1) continue;
    p[pos] = i;
    dfs(pos + 1, bit | (1 << i), p, n, g, cnt);
  }
}

int main() {
  int n, m;
  cin >> n >> m;
  vector<vector<bool>> g(n, vector<bool>(n));
  for(int i = 0; i < m; ++i){
    int a, b;
    cin >> a >> b;
    --a, --b;
    g[a][b] = g[b][a] = true;
  }
  int cnt = 0;
  vector<int> p(n);
  dfs(0, 0, p, n, g, cnt);
  cout << cnt << endl;
}