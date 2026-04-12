#include <bits/stdc++.h>
#define rep(i, n) for(int i=0; i<n; ++i)
using namespace std;
int main()
{
  int H, W;
  cin >> H >> W;
  char grid[100][100];
  bool skip_h[100];
  bool skip_w[100];
  rep(i,H) { rep(j,W) { cin >> grid[i][j]; } }

  rep(i,H) {
    rep(j,W) {
      if(grid[i][j] != '.') goto nexti;
    }
    skip_h[i] = true;
    nexti:
      continue;
  }

  rep(j, W) {
    rep(i, H) {
      if(grid[i][j] != '.') goto nextj;
    }
    skip_w[j] = true;
    nextj:
      continue;
  }

  rep(i,H) {
    if(skip_h[i] == false) {
      rep(j,W) {
        if(skip_w[j] == false) {
          cout << grid[i][j];
        }
      }
      cout << endl;
    }
  }
  return 0;
}
