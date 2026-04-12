#include <bits/stdc++.h>

#define each(i, c) for (auto& i : c)
#define unless(cond) if (!(cond))

using namespace std;

typedef long long int lli;
typedef unsigned long long ull;
typedef complex<double> point;

template<typename P, typename Q>
ostream& operator << (ostream& os, pair<P, Q> p)
{
  os << "(" << p.first << "," << p.second << ")";
  return os;
}

int main(int argc, char *argv[])
{
  int h, w;
  while (cin >> h >> w) {
    char g[h][w];
    for (int i = 0; i < h; ++i) {
      for (int j = 0; j < w; ++j) {
        cin >> g[i][j];
      }
    }
    int i = 0;
    int j = 0;
    while (true) {
      if (g[i][j] != '#') break;
      g[i][j] = '@';
      if (i == h - 1 && j == w - 1) break;
      if (i + 1 < h && g[i + 1][j] == '#') {
        ++i;
        continue;
      }
      if (j + 1 < w && g[i][j + 1] == '#') {
        ++j;
        continue;
      }
      g[0][0] = '#';
      break;
    }
    cout << (i == h  - 1 && j == w - 1 && count(&g[0][0], &g[h - 1][w - 1] + 1, '#') == 0 ? "Possible" : "Impossible") << endl;
  }
  return 0;
}
