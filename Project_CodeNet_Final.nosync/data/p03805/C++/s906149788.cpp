using namespace std;

#include <iostream>
#include <vector>
#include <cmath>

int N, M;
bool edge[8][8];

int dfs(int node, bool alr[]) {
  alr[node] = true;
  int res = 0;
  for (int i = 0; i < N; i++) {
    if (!alr[i]) break;
    if (i == N-1) {
      alr[node] = false;
      return 1;
    }
  }
  for (int i = 0; i < N; i++) {
    if (edge[node][i] && !alr[i]) {
      res += dfs(i, alr);
    }
  }
  alr[node] = false;
  return res;
}

int main() {
  cin >> N >> M;
  memset(edge, 0, sizeof(edge));
  for (int i = 0; i < M; i++) {
    int x, y;
    cin >> x >> y;
    edge[x-1][y-1] = true;
    edge[y-1][x-1] = true;
  }
  
  bool alr[N];
  for (int i = 0; i < N; i++) alr[i] = false;
  
  
  cout << dfs(0, alr) << endl;
  
  
  return 0;
  
  
}