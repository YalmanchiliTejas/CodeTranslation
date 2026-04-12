#include <iostream>
using namespace std;

int N, M;
bool path[8][8];
bool used[8];
int ans = 0;

// 深さ優先探索（s:今いる頂点）
void dfs(int s) {
  bool all_used = true;
  for (int i = 0; i < N; i++) {
    if (!used[i]) all_used = false;
  }
  if (all_used) ans++;

  for (int i = 0; i < N; i++) {
    if (path[s][i] && !used[i]) {
      used[i] = true;
      dfs(i);
      used[i] = false;
    }
  }
}

int main() {
  cin >> N >> M;
  int a, b;
  for (int i = 0; i < M; i++) {
    cin >> a >> b;
    path[a-1][b-1] = path[b-1][a-1] = true;
  }

  used[0] = true;
  dfs(0);
  cout << ans << endl;
  return 0;
}
