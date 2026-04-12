#include <iostream>
#include <vector>
using namespace std;

int N, M;
vector<vector<bool>> g;
vector<bool> vertex;
int ans;

void Dfs(int v) {
  vertex[v] = true;

  int visit = 0;
  for (int i = 0; i < N; ++i)
    visit += vertex[i];
  if (visit == N)
    ++ans;

  for (int i = 0; i < N; ++i)
    if (!vertex[i] && g[v][i])
      Dfs(i);

  vertex[v] = false;
}

int main() {
  cin >> N >> M;
  vector<int> a(M), b(M);
  for (int i = 0; i < M; ++i)
    cin >> a[i] >> b[i];

  g.resize(N, vector<bool>(N));
  for (int i = 0; i < M; ++i)
    g[a[i] - 1][b[i] - 1] = true, g[b[i] - 1][a[i] - 1] = true;

  vertex.resize(N);
  Dfs(0);
  cout << ans << endl;
}