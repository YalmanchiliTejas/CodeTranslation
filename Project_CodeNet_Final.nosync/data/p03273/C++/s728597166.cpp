// https://atcoder.jp/contests/abc107/tasks/abc107_b

#include <bits/stdc++.h>
#define REP(i, n) for (int(i) = 0; (i) < (n); (i)++)
#define REPR(i, n) for (int(i) = (n); (i) >= 0; (i)--)
#define FOR(i, m, n) for (int(i) = (m); (i) < (n); i++)
#define INF 1e9
#define ALL(v) (v).begin(), (v).end()
using namespace std;
typedef long long ll;

int main()
{
  /* Magic word */
  // cin.tie(0);
  // ios::sync_with_stdio(false);
  /* ---------- */

  int h, w;
  vector<string> a;

  cin >> h >> w;

  REP(i, h)
  {
    string ai;
    cin >> ai;
    if (ai.find('#') != string::npos)
      a.push_back(ai);
  }

  h = a.size();
  REPR(i, w - 1)
  {
    bool d = true;
    REP(j, h)
    {
      if (a[j][i] == '#')
      {
        d = false;
        break;
      }
    }
    if (d)
    {
      w--;
      REP(j, h)
      {
        a[j].erase(i, 1);
      }
    }
  }

  for (auto &aa : a)
  {
    cout << aa << '\n';
  }

  return 0;
}
