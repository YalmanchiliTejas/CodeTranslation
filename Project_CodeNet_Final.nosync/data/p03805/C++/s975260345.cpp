#include <iostream>
#include <algorithm>
using namespace std;
#define MAX 10

int n, m;
int edge[MAX][MAX];
int countnum = 0;
bool visited[MAX];

void dfs(int v, int res) {
  if (res == n) {
    countnum++;
    return;
  }
  for (int i = 1; i <= n; i++) {
    if (edge[v][i] && !visited[i]) {
      visited[i] = true;
      dfs(i, res + 1);
      visited[i] = false;
    }
  }
}

int main() {
  for (int i = 0; i < MAX; i++) {
    for (int j = 0; j < MAX; j++) {
      edge[i][j] = 0;
    }
  }
  cin >> n >> m;
  for (int i = 0; i < m; i++) {
    int a, b;
    cin >> a >> b;
    edge[a][b] = 1;
    edge[b][a] = 1;
  }
  for (int i = 0; i < MAX; i++) {
    visited[i] = false;
  }
  visited[1] = true;
  dfs(1, 1);
  cout << countnum << endl;
  return 0;
}
