#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int dx[4] = {1, 0};
int dy[4] = {0, 1};

int main() {
  int h, w;
  cin >> h >> w;
  int sx = 0, sy = 0, gx = h - 1, gy = w - 1;
  vector<string> maze(h);
  rep(i, h) cin >> maze[i];
  vector<vector<int>> dist(h, vector<int>(w, -1));

  queue<P> q;
  q.push(P(sx, sy));
  dist[sx][sy] = 0;
  while (!q.empty()) {
    P p = q.front();
    q.pop();
    int cx = p.first;
    int cy = p.second;
    // if (cx == gx && cy == gy) break;
    rep(i, 2) {
      int nx = cx + dx[i];
      int ny = cy + dy[i];
      if (0 > nx || nx >= h || 0 > ny || ny >= w) continue;
      if (maze[nx][ny] != '#' || dist[nx][ny] != -1) continue;
      dist[nx][ny] = dist[cx][cy] + 1;
      q.push(P(nx, ny));
      break;
      // cout << nx << " " << ny << endl;
    }
    // rep(i, h) {
    //   rep(j, w) printf("%+d", dist[i][j]);
    //   cout << endl;
    // }
    // cout << endl;
  }

  rep(i, h) {
    rep(j, w) {
      if (dist[i][j] == -1 && maze[i][j] == '#') {
        cout << "Impossible" << endl;
        return 0;
      }
    }
  }
  cout << "Possible" << endl;
  return 0;
}
