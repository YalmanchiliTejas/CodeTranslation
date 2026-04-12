#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int n, m, ans;
vector<int> edge[8];
bool done[8];

int dfs(int u) {
  done[u] = true;
  for (int v: edge[u]) {
    if (done[v]) continue;
    dfs(v);
  }
  
  bool f = true;
  for (int i = 0; i < n; i++) {
    if (not done[i]) {
      f = false;
    }
  }
  if (f) ans++;
  
  done[u] = false;
}

int main() {
  cin >> n >> m;
  for (int i = 0; i < m; i++) {
    int a, b;
    cin >> a >> b;
    a--, b--;
    edge[a].push_back(b);
    edge[b].push_back(a);
  }
  
  dfs(0);
  
  cout << ans << endl;
  return 0;
}
