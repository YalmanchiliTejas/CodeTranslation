#include <bits/stdc++.h>
using namespace std;

constexpr int n_max = 8;
bool edge[n_max][n_max];
int N, M;
int cnt;
void dfs(int n, bool* reached) {
  //for (int i = 0; i < N; ++i) {
  //  cout << ((i == n) ? 2 : reached[i]) << " ";
  //}
  //cout << endl;
  bool completed = true;
  reached[n] = true;
  for (int i = 0; i < N; ++i) {
    if (!reached[i]) {
      completed = false;
      break;
    }
  }
  reached[n] = false;
  if (completed) {
    ++cnt;
    return;
  }
  for (int i = 0; i < N; ++i) {
    if(!reached[i] && edge[n][i]) {
      reached[n] = true;
      dfs(i, reached);
      reached[n] = false;
    }
  }
}

int main() {
  cin >> N >> M;
  for (int i = 0; i < M; ++i) {
    int a, b;
    cin >> a >> b;
    edge[a-1][b-1] = edge[b-1][a-1] = true;
  }
  bool reached[N];
  memset(reached, 0, sizeof(reached));
  reached[0] = true;
  dfs(0, reached);

  cout << cnt << endl;
  return 0;
}
