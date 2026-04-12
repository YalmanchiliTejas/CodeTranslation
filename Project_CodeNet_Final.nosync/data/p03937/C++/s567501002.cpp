#include <bits/stdc++.h>

using namespace std;
#define int int64_t
#define fi first
#define se second
#define endl '\n'

int dx[2] = {0, 1};
int dy[2] = {1, 0};
int h, w;
vector<string> a;
vector<vector<int>> used;
void dfs(int x, int y) {
     used[x][y] = true;
     for (int dir = 0;dir < 2; ++dir) {
          int nx = x + dx[dir];
          int ny = y + dy[dir];
          if (nx < h && ny < w && !used[nx][ny] && a[nx][ny] == '#') {
               dfs(nx, ny);
          }
     }
}



signed main()
{
     srand(time(nullptr));
     ios::sync_with_stdio(false);
     cin.tie(0);
     cout.tie(0);
     cin >> h >> w;
     a.resize(h);
     used.resize(h, vector<int>(w));
     int cnt = 0;
     for (int i = 0; i < h; ++i) {
          cin >> a[i];
          cnt += count(a[i].begin(), a[i].end(), '#');
     }
     dfs(0, 0);
     for (int i = 0; i < h; ++i) {
          for (int j = 0; j < w; ++j) {
               if (a[i][j] == '#' && !used[i][j]) {
                    cout << "Impossible";
                    return 0;
               }
          }
     }
     if (!used[h-1][w-1] || cnt != h + w - 1) {
          cout << "Impossible";
     } else {
          cout << "Possible";
     }
     return 0;
}
