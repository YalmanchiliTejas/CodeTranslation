#include <bits/stdc++.h>
#define rep(i, a, n) for (int i = a; i < n; i++)
#define repr(i, a, n) for (int i = n - 1; i >= a; i--)
using namespace std;
using ll = long long;
using P = pair<int, int>;
template <typename T> void chmin(T &a, T b) { a = min(a, b); }
template <typename T> void chmax(T &a, T b) { a = max(a, b); }

int dx[]{-1, 0, 1, 0};
int dy[]{0, -1, 0, 1};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int h, w;
  cin >> h >> w;

  vector<string> mp(h);
  rep(i, 0, h) cin >> mp[i];

  int sharp_count = 0;
  rep(i, 0, h) rep(j, 0, w) {
    if (mp[i][j] == '#')
      sharp_count++;
  }

  if (h + w - 1 != sharp_count) {
    cout << "Impossible" << endl;
    return 0;
  }

  vector<vector<int>> search(h, vector<int>(w, 0));
  search[0][0] = 1;
  queue<P> q;
  q.push(make_pair(0, 0));

  while (!q.empty()) {
    P p = q.front();
    q.pop();
    int y = p.first;
    int x = p.second;
    rep(i, 0, 4) {
      int ny = y + dy[i], nx = x + dx[i];
      if (ny < 0 || nx < 0 || ny >= h || nx >= w)
        continue;
      if (search[ny][nx] != 0)
        continue;
      if (mp[ny][nx] == '.')
        continue;
      search[ny][nx] = search[y][x] + 1;
      q.push(make_pair(ny, nx));
    }
  }

  if (h + w - 1 == search[h - 1][w - 1])
    cout << "Possible" << endl;
  else
    cout << "Impossible" << endl;
}
