#include <iostream>

using namespace std;

bool G[8][8] = {{false}};
bool visited[8] = {false};

bool IsComplete(int N) {
  for (int i = 0; i < N; ++i)
    if (!visited[i])
      return false;
  return true;
}

int DFS(int u, int N) {
  if (IsComplete(N))
    return 1;

  int ret = 0;
  for (int v = 0; v < N; ++v) {
    if (!G[u][v])
      continue;
    if (visited[v])
      continue;
    visited[v] = true;
    ret += DFS(v, N);
    visited[v] = false;
  }
  return ret;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int N, M;
  cin >> N >> M;

  int a, b;
  for (int i = 0; i < M; ++i) {
    cin >> a >> b;
    a--;
    b--;
    G[a][b] = G[b][a] = true;
  }
  visited[0] = true;
  cout << DFS(0, N) << endl;

  return 0;
}
