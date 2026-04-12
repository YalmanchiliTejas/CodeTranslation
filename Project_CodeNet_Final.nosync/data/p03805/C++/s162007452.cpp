#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> P;

vector<vector<bool>> g(10, vector<bool>(10, 0));

int n, m;

int dfs(int v, vector<bool> visit) {
  bool allv = true;
  for (int i = 0; i < n; i++) {
    if (!visit[i]) {
      allv = false;
      break;
    }
  }

  if (allv) {
    return 1;
  }

  int sum = 0;
  for (int i = 0; i < n; i++) {
    if (g[v][i] && !visit[i]) {
      visit[i] = 1;
      sum += dfs(i, visit);
      visit[i] = 0;
    }
  }

  return sum;
}

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);

  cin >> n >> m;

  for (int i = 0; i < m; i++) {
    int a, b;
    cin >> a >> b;
    --a;
    --b;
    g[a][b] = 1;
    g[b][a] = 1;
  }

  vector<bool> visit(n);
  visit[0] = 1;
  int ans = dfs(0, visit);

  cout << ans << endl;

  return 0;
}