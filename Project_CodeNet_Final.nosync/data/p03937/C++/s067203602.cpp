#include <bits/stdc++.h>
#define REP(i, n) for (int i = 0; i < n; i++)
#define FOR(i, m, n) for (int i = m; i < n; i++)
#define ll long long int
const int INF = 2147483647;

using namespace std;
int h, w;
string a[8];
bool used[8][8] = {};

bool dfs(int cx, int cy, int gx, int gy)
{
  used[cy][cx] = true;
  if (cx == gx && cy == gy)
    return true;
  bool ans = false;
  if (cx < w - 1 && a[cy][cx + 1] == '#')
  {
    ans = dfs(cx + 1, cy, gx, gy);
  }
  if (ans)
    return ans;
  if (cy < h - 1 && a[cy + 1][cx] == '#')
  {
    ans = dfs(cx, cy + 1, gx, gy);
  }
  if (ans)
    return ans;
  used[cy][cx] = false;
  return false;
}

int main()
{
  cin >> h >> w;
  REP(i, h)
  {
    cin >> a[i];
  }

  dfs(0, 0, w - 1, h - 1);
  REP(i, h)
  {
    REP(j, w)
    {
      if (a[i][j] == '#' && !used[i][j])
      {
        cout << "Impossible" << endl;
        return 0;
      }
    }
  }
  cout << "Possible" << endl;
}
