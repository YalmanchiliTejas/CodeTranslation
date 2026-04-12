#include <bits/stdc++.h>

using namespace std;

int m, d[102][102], a, b, ok[102][102];
struct skrr {
  int i, j, c;
} v[20002];

int main()
{
  cin >> a >> b;
  for (int i = 1; i <= a; i++)
    for (int j = 1; j <= b; j++)
      cin >> d[i][j];
  for (int i = 0; i <= 100; i++)
    for (int j = 0; j <= 100; j++) {
      int mx = 0;
      for (int x = 1; x <= a; x++)
        for (int y = 1; y <= b; y++)
          mx = max (mx, d[x][y] - i * x - j * y);
      v[++m] = {i + 1, 202 - j, mx};
      for (int x = 1; x <= a; x++)
        for (int y = 1; y <= b; y++)
          if (mx + i * x + j * y == d[x][y])
            ok[x][y] = 1;
    }
  for (int x = 1; x <= a; x++)
    for (int y = 1; y <= b; y++)
    if (!ok[x][y]) {
      cout << "Impossible";
      return 0;
    }
  cout << "Possible\n";
  cout << "202 " << m + 200 << "\n";
  for (int i = 1; i <= 100; i++)
    cout << i << " " << i + 1 << " X\n";
  for (int i = 1; i <= 100; i++)
    cout << i + 101 << " " << i + 102 << " Y\n";
  for (int i = 1; i <= m; i++)
    cout << v[i].i << " " << v[i].j << " " << v[i].c << "\n";
  cout << "1 202";
  return 0;
}
