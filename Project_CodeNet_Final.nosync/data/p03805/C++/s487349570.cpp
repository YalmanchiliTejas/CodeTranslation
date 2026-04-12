#include <bits/stdc++.h>
#define REP(i,n) for(int i=0;i<n;++i)
using namespace std;

const int MAX_N = 8;
const int MAX_M = 28;
int N, M;
bool G[MAX_N][MAX_N], visited[MAX_N];

int dfs(int u) {
  int v, sum;
  REP(i, N) {
    if (!visited[i]) break;
    if (i == N - 1) return 1;
  }
  sum = 0;
  REP(v, N) {
    if (!G[u][v]) continue;
    if (visited[v]) continue;

    visited[v] = true;
    sum += dfs(v);
    visited[v] = false;
  }
  return sum;
}

main() {
  cin >> N >> M;
  REP(i, M) {
    int a, b;
    cin >> a >> b;
    a--; b--;
    G[a][b] = G[b][a] = true;
  }
  REP(i, N) visited[i] = false;

  visited[0] = true;
  cout << dfs(0) << endl;
}
