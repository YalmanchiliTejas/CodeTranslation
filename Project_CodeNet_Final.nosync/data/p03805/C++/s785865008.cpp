#include <bits/stdc++.h>
using namespace std;

const int N = 10;

int n, m, u, v, ans;
vector<int> adj[N];

void dfs(int u, int state) {
  // cout << u << ' ' << state << endl;
  int new_state = state | (1<<u);
  if (new_state == (1<<n)-1) ans++;
  else {
    for (int v : adj[u]) {
      if (((1<<v) & new_state) == 0) dfs(v,new_state);
    }  
  }
}

int main () {
  ans = 0;
  cin >> n >> m;
  for (int i = 0; i < m; i++) {
    cin >> u >> v;
    u--; v--;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  dfs(0,0);
  cout << ans << endl;
  
  return 0;
}