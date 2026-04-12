#include <bits/stdc++.h>
#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
#define sz(a) (int)a.size()
#define mp(a, b) make_pair(a, b)
#define all(a) a.begin(), a.end()
using namespace std;
typedef long long ll;
const int MAXN = 10;

int n, m;
char arr[MAXN][MAXN];
bool path[MAXN][MAXN];

int main()
{
  cin >> n >> m;

  forn(i, n)
    forn(j, m)
      cin >> arr[i][j];

  path[0][0] = true;

  forn(i, n)
    forn(j, m)
    {
      if (path[i][j])
      {
        if (arr[i + 1][j] == '#')
          path[i + 1][j] = true;
        else if (arr[i][j + 1] == '#')
          path[i][j + 1] = true;
      }
    }

  bool ok = true;

  forn(i, n)
    forn(j, m)
      ok &= path[i][j] ^ (arr[i][j] == '.');

  cout << (ok ? "Possible" : "Impossible");
	return 0;
}
