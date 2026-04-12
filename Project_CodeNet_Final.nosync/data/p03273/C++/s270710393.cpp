#include <bits/stdc++.h>
#define REP(i, n) for (int i = 0; i < n; i++)
#define FOR(i, m, n) for (int i = m; i < n; i++)
#define ll long long int
const int INF = 2147483647;

using namespace std;

int main()
{
  int h, w;
  int row[100][100] = {};
  int col[100][100] = {};
  cin >> h >> w;
  vector<string> m(h);
  REP(i, h)
  {
    cin >> m[i];
  }

  REP(i, h)
  {
    REP(j, w)
    {
      if (m[i][j] == '#')
      {
        REP(r, w)
        {
          row[i][r] = 1;
        }
        REP(c, h)
        {
          col[c][j] = 1;
        }
      }
    }
  }

  REP(i, h)
  {
    bool update = false;
    REP(j, w)
    {

      if (row[i][j] == 1 && col[i][j] == 1)
      {
        update = true;
        cout << m[i][j];
      }
    }
    if (update)
    {
      cout << endl;
    }
  }
}
