#include <iostream>
#include <algorithm>
using namespace std;
#define int long long
#define MAX 10

bool edge[MAX][MAX];
bool visited[MAX];
int n, m, cnt;

void dfs(int current, int number) {
  if (n == number) {
    cnt++;
  }
  for (int i = 1; i <= n; i++) {
    if (!visited[i] && edge[i][current]) {
      visited[i] = true;
      dfs(i, number + 1);
      visited[i] = false;
    }
  }
}


signed main() {
  cin >> n >> m;
  for (int i = 0; i < MAX; i++) {
    for (int j = 0; j < MAX; j++) {
      edge[i][j] = false;
    }
  }
  for (int i = 0; i < m; i++) {
    int a, b;
    cin >> a >> b;
    edge[a][b] = true;
    edge[b][a] = true;
  }
  fill(visited, visited + MAX, false);
  visited[1] = true;
  dfs(1, 1);
  cout << cnt << endl;
  return 0;
}
