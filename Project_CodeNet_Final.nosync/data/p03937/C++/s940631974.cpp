#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
  int h, w;
  cin >> h >> w;
  vector<string> a(h);
  rep(i, h) cin >> a[i];
  int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};
  vector<vector<int>> dist(h, vector<int>(w, -1));
  queue<P> q;
  q.push(P(0, 0));
  dist[0][0] = 0;
  while(!q.empty()) {
    P now = q.front(); q.pop();
    
    rep(i, 4) {
      int nx = now.first+dx[i], ny = now.second+dy[i];
      if (nx >= 0 && nx <h && ny >= 0 && ny < w && a[nx][ny] == '#' && dist[nx][ny] == -1) {
        if (i == 0 || i == 1) {
          q.push(P(nx, ny));
          dist[nx][ny] = 0;
        }
        if (i == 2 || i == 3) {
          cerr << "nx=" << nx << " ny=" << ny << endl;
          cerr << "i= " << i << endl;
          cerr << "dist[" << nx << "][" << ny << "]=" << dist[nx][ny] << endl;
          cout << "Impossible" << endl;
          return 0;
        }
      }
    }
    if (now == P(h-1, w-1)) break;
    if ((int)q.size() > 1 || q.size() == 0) {
      cout << "Impossible" << endl;
      return 0;
    }
  }
  cout << "Possible" << endl;
  return 0;
}
