#include <iostream>
#include <vector>
using namespace std;
int ans;
int e[8][8];
bool visited[8];
int n, m;
void dfs(int vis, int last) {
  if (vis == n) ans++;
  for (int i = 0; i < n; i++) {
    if (!e[last][i] || visited[i]) continue;
    visited[i] = 1;
    dfs(vis + 1, i);
    visited[i] = 0;
  }
}
int main(void) {
  cin >> n >> m;
  for (int i = 0; i < m; i++) {
    int a, b;
    cin >> a >> b;
    e[a - 1][b - 1]++;
    e[b - 1][a - 1]++;
  }
  visited[0] = 1;
  dfs(1, 0);
  cout << ans << endl;
  return 0;
}