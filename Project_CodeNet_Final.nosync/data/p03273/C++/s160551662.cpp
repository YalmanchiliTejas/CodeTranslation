#include <bits/stdc++.h>
using namespace std;

int main()
{
  int h, w, i, j;
  cin >> h >> w;
  vector<string> a(h);
  for (i = 0; i < h; i++)
    cin >> a[i];
  vector<bool> a1(h, false), a2(w, false);
  for (i = 0; i < h; i++)
    for (j = 0; j < w; j++)
      if (a[i][j] == '#')
        a1[i] = a2[j] = true;
  for (i = 0; i < h; i++) {
    if (!a1[i]) continue;
    for (j = 0; j < w; j++)
      if (a1[i] && a2[j]) cout << a[i][j];
    cout << endl;
  }
}