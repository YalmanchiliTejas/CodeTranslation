#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int N;
int edge[8][8];

int dfs(int cur, vector<bool> visited, int cnt) {
  if (cnt == N) {
    return 1;
  }
  int ret = 0;
  for (int i = 0; i < N; i++) {
    if (edge[cur][i] && !visited[i]) {
      visited[i] = true;
      ret += dfs(i, visited, cnt + 1);
      visited[i] = false;
    }
  }
  return ret;
}

int main() {
  int M;
  cin >> N >> M;
  for (int i = 0; i < M; i++) {
    int a, b;
    cin >> a >> b;
    a--, b--;
    edge[a][b] = edge[b][a] = 1;
  }
  vector<bool> visited(N);
  visited[0] = true;
  cout << dfs(0, visited, 1) << endl;
}