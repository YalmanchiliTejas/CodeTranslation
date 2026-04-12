#include <bits/stdc++.h>
#include <vector>

#define rep(x, n) for(int i = x; i < (n); ++i)

using namespace std;
using ll = long long;

ll H, W;
vector<string> a(100);

int main(void)
{
  cin >> H >> W;
  rep(0, H) cin >> a.at(i);

  vector<bool> row(H, false);
  vector<bool> col(W, false);
  for (int y = 0; y < H; ++y) {
    for (int x = 0; x < W; ++x) {
      if (a[y][x] == '#') {
        row[y] = true;
        col[x] = true;
      }
    }
  }

  for (int i = 0; i < H; ++i) {
    if(row[i]) {
      for (int j = 0; j < W; ++j) {
        if (col[j]) {
          cout << a[i][j];
        }
      }
      cout << endl;
    }
  }
}