#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;

const int dy[4] = {-1, 0, 0, 1};
const int dx[4] = {0, -1, 1, 0};
int R, C, M;
string s[50];
int p[50][50];
int q[50][50];
int r[50][50];
int yy[1010], xx[1010];
vector<int> t[50][50];
pii pre[50][50];

bool contain(int y, int x) {
  return y >= 0 && y < R && x >= 0 && x < C;
}

vector<pii> getPath(int idx) {
  int sy = yy[idx], sx = xx[idx];
  int gy = yy[idx+1], gx = xx[idx+1];
  fill_n((pii*)pre, 50*50, pii(-1, -1));
  pre[sy][sx] = pii(sy, sx);
  queue<pii> que;
  que.emplace(sy, sx);
  while (!que.empty()) {
    int y, x;
    tie(y, x) = que.front();
    que.pop();
    for (int i = 0; i < 4; i++) {
      int ny = y + dy[i];
      int nx = x + dx[i];
      if (contain(ny, nx) && s[ny][nx] == '.' && pre[ny][nx].first < 0) {
        pre[ny][nx] = pii(y, x);
        que.emplace(ny, nx);
      }
    }
  }
  int y = gy, x = gx;
  vector<pii> res;
  while (!(y == sy && x == sx)) {
    res.emplace_back(y, x);
    tie(y, x) = pre[y][x];
  }
  reverse(res.begin(), res.end());
  return res;
}

int main() {
  cin.tie(0);
  ios_base::sync_with_stdio(false);
  cout << fixed << setprecision(10);
  
  cin >> R >> C >> M;
  for (int i = 0; i < R; i++) {
    cin >> s[i];
  }
  for (int i = 0; i < R; i++) {
    for (int j = 0; j < C; j++) {
      cin >> p[i][j];
    }
  }
  for (int i = 0; i < R; i++) {
    for (int j = 0; j < C; j++) {
      cin >> q[i][j];
    }
  }
  for (int i = 0; i < R; i++) {
    for (int j = 0; j < C; j++) {
      cin >> r[i][j];
    }
  }
  for (int i = 0; i < M; i++) {
    cin >> yy[i] >> xx[i];
  }

  int tm = 0, y = yy[0], x = xx[0];
  t[y][x].emplace_back(tm++);
  for (int i = 0; i < M-1; i++) {
    vector<pii> path = getPath(i);
    for (int j = 0; j < path.size(); j++) {
      tie(y, x) = path[j];
      t[y][x].emplace_back(tm++);
    }
  }
  int ans = 0;
  for (int i = 0; i < R; i++) {
    for (int j = 0; j < C; j++) {
      if (s[i][j] != '.') continue;
      if (t[i][j].size() == 0) continue;
      ans += q[i][j] + r[i][j];
      for (int k = 0; k+1 < t[i][j].size(); k++) {
        ans += min((t[i][j][k+1] - t[i][j][k]) * p[i][j], q[i][j] + r[i][j]);
      }
    }
  }
  cout << ans << endl;

  return 0;
}
