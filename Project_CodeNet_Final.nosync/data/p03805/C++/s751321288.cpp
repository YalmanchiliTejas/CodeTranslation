#include <iostream>
#include <cstdio>
using namespace std;

int N, M;
bool path[10][10];
bool used[10];
int ans = 0;

void dfs(int n) {
  bool all_used = true;
  for (int i=0; i<N; i++) {
    if (!used[i]) all_used = false;
  }
  if (all_used) ans++;

  for (int i=1; i<N; i++) {
    if (!path[n][i]) continue;  // 辺がなければcontinue
    if (used[i]) continue;      // 訪問済みであればcontinue
    used[i] = true;
    dfs(i);
    used[i] = false;
  }
}

int main() {
  cin >> N >> M;
  int a, b;
  for (int i=0; i<M; i++) {
    cin >> a >> b;
    path[a-1][b-1] = path[b-1][a-1] = true;
  }
  used[0] = true;
  dfs(0);
  cout << ans << endl;
  return 0;
}
