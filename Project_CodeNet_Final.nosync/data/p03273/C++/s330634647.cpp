#include <bits/stdc++.h>
using namespace std;

int main()
{
  int h, w;
  cin >> h >> w;
  char a[h][w];
  bool hflag[h];
  for (int i = 0; i < h; i++) hflag[i] = false;
  bool wflag[w];
  for (int i = 0; i < w; i++) wflag[i] = false;

  for (int i = 0; i < h; i++) {
    for (int j = 0; j < w; j++) {
      cin >> a[i][j];
      if (a[i][j] == '#') {
        hflag[i] = true;
        wflag[j] = true;
      }
    }
  }

  for (int i = 0; i < h; i++) {
    for (int j = 0; j < w; j++) {
      if (hflag[i] && wflag[j]) cout << a[i][j];
    }
    if (hflag[i])cout << endl;
  }
}
