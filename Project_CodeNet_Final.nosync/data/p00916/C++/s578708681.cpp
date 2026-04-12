#include <bits/stdc++.h>
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;
using P = pair<int, int>;

const int dy[] = {1, 0, -1, 0};
const int dx[] = {0, 1, 0, -1};
const int M = 300;

map<int, int> compress(vector<int>& unzip) {
  map<int, int> zip;
  for (auto x : unzip) zip[x] = -1;
  int idx = 0;
  unzip = vector<int>();
  for (auto& p : zip) {
    unzip.push_back(p.first);
    p.second = idx;
    idx++;
  }
  return zip;
}

vector<vector<int>> color;

void dfs(int sy, int sx, int c) {
  color[sy][sx] = c;
  REP(k, 4) {
    int ty = sy + dy[k];
    int tx = sx + dx[k];
    if (ty < 0 || M < ty || tx < 0 || M < tx) continue;
    if (color[ty][tx] > 0) continue;
    dfs(ty, tx, c);
  }
}

int main() {
  for (int n; cin >> n, n;) {
    vector<int> x(4 * n + 1, -1), y(4 * n + 1, -1);
    REP(i, n) {
      int l, t, r, b;
      cin >> l >> t >> r >> b;
      x[4 * i + 0] = 2 * l;
      x[4 * i + 1] = 2 * l + 1;
      x[4 * i + 2] = 2 * r;
      x[4 * i + 3] = 2 * r + 1;
      y[4 * i + 0] = 2 * b;
      y[4 * i + 1] = 2 * b + 1;
      y[4 * i + 2] = 2 * t;
      y[4 * i + 3] = 2 * t + 1;
    }
    auto tmpx = x;
    auto tmpy = y;
    auto X = compress(tmpx);
    auto Y = compress(tmpy);

    color = vector<vector<int>>(M + 1, vector<int>(M + 1, 0));
    REP(i, n) {
      int l = X[x[4 * i + 0]];
      int r = X[x[4 * i + 2]];
      int b = Y[y[4 * i + 0]];
      int t = Y[y[4 * i + 2]];
      color[b][l]++;
      color[b][r + 1]--;
      color[b + 1][l]--;
      color[b + 1][r + 1]++;
      color[t][l]++;
      color[t][r + 1]--;
      color[t + 1][l]--;
      color[t + 1][r + 1]++;
      color[b][l]++;
      color[b][l + 1]--;
      color[t + 1][l]--;
      color[t + 1][l + 1]++;
      color[b][r]++;
      color[b][r + 1]--;
      color[t + 1][r]--;
      color[t + 1][r + 1]++;
    }
    REP(i, M) REP(j, M + 1) color[i + 1][j] += color[i][j];
    REP(i, M + 1) REP(j, M) color[i][j + 1] += color[i][j];

    int c = 0;
    REP(i, M + 1) REP(j, M + 1) {
      if (color[i][j] > 0) continue;
      dfs(i, j, ++c);
    }
    cout << c << endl;
  }
}

