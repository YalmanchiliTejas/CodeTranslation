#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
  int H, W;
  cin >> H >> W;
  vector<string> a(H);
  for (int i = 0; i < H; i++)
  {
    cin >> a[i];
  }
  vector<bool> rows(H, false);
  vector<bool> cols(W, false);
  for (int i = 0; i < H; i++)
  {
    for (int j = 0; j < W; j++)
    {
      if (a[i][j]=='#')
      {
        rows[i] = true;
        cols[j] = true;
      }
    }
  }
  for (int i = 0; i<H; i++) {
    if (rows[i]) {
      for (int j = 0; j < W; j++)
      {
        if (cols[j]) {
          cout << a[i][j];
        }
      }
      cout << endl;
    }
  }
}