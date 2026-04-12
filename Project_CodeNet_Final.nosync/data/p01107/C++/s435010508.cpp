#include <bits/stdc++.h>
using namespace std;
using P = pair<int, int>;

const int dx[] = {-1, 0, 1, 0};
const int dy[] = {0, 1, 0, -1};

int N, M;
vector<string> c;
vector<vector<bool>> g;
vector<bool> used;

void dfs(int sx, int sy) {
  used[sx * M + sy] = true;
  for (int i = 0; i < 4; ++i) {
    int tx = sx + dx[i];
    int ty = sy + dy[i];
    if (0 <= tx && tx < N && 0 <= ty && ty < M) {
      if (used[tx * M + ty]) continue;
      if (c[tx][ty] == '.') dfs(tx, ty);
    }
  }
}

bool check() {
  used = vector<bool>(N * M, false);
  dfs(0, 0);
  for (auto&& p : vector<P>{{N - 1, 0}, {N - 1, M - 1}, {0, M - 1}}) {
    if (!used[p.first * M + p.second]) return false;
  }
  return true;
}

bool solve() {
  if (!check()) return false;
  for (int i = 0; i < N; ++i) {
    for (int j = 0; j < M; ++j) {
      if (i == N - 1 && j == 0) continue;
      if (i == N - 1 && j == M - 1) continue;
      if (i == 0 && j == M - 1) continue;
      if (c[i][j] == '#') continue;

      c[i][j] = '#';
      if (!check()) return false;
      c[i][j] = '.';
    }
  }
  return true;
}

int main() {
  while (cin >> N >> M, N) {
    c = vector<string>(N);
    for (int i = 0; i < N; ++i) cin >> c[i];
    cout << ( (solve()) ? "YES" : "NO" ) << endl;
  }
  return 0;
}

