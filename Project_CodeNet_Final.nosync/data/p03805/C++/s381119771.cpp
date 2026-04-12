#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;


int N, M;

const int INF = 1000000;

typedef vector<int> VI;

VI visited;

const int N_MAX = 10;
int G[N_MAX][N_MAX];


int dfs(int v, int n) {
  if (n == 1) return 1;

  visited[v] = 1;

  int res = 0;
  for (int i = 0; i < N; i++) {
    if (G[v][i] && visited[i] == 0) {
      res += dfs(i, n-1);
    }
  }

  visited[v] = 0;

  return res;
}


int main() {
  cin >> N >> M;
  visited = VI(N, 0);

  for (int i = 0; i < M; i++) {
    int a, b;
    cin >> a >> b;
    a--; b--;
    G[a][b] = 1;
    G[b][a] = 1;
  }
  cout << dfs(0, N) << endl;

  return 0;
}
