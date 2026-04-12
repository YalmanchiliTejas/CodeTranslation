#include <bits/stdc++.h>
using namespace std;

const int nmaxval = 8;
bool g[nmaxval][nmaxval];

int DFS(int p, int N, bool visited[nmaxval]) {
  bool allvisited = true;
  for (int i=0; i<N; i++)
    if (visited[i] == false) allvisited = false;

  if (allvisited) {
    return 1;
  } else {
    int ret = 0;
    for (int i=0; i<N; i++) {
      if (g[p][i] == false) continue;
      if (visited[i]) continue;

      visited[i] = true;
      ret += DFS(i, N, visited);
      visited[i] = false;
    }
    return ret;
  }
}

int main() {
  int N, M;
  cin >> N >> M;
  for (int i=0; i<M; i++) {
    int a, b;
    cin >> a >> b;
    g[a-1][b-1] = g[b-1][a-1] = true;
  }

  bool v[nmaxval];
  for (int i=1; i<N; i++) v[i] = false;
  v[0] = true;

  cout << DFS(0, N, v) << endl;

  return 0;
}
