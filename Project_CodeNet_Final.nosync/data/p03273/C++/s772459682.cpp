#include <bits/stdc++.h>

using namespace std;

int main()
{
  int H, W; cin >> H >> W;
  vector<string> a(H);
  for (int i = 0; i < H; ++i) {
    cin >> a[i];
  }

  vector<bool> row(H), col(W);
  for (int i = 0; i < H; ++i) {
    for (int j = 0; j < W; ++j) {
      if (a[i][j] == '#') {
        row[i] = true;
        col[j] = true;
      }
    }
  }

  for (int i = 0; i < H; ++i) {
    if (!row[i]) continue;
    for (int j = 0; j < W; ++j) {
      if (!col[j]) continue;
      cout << a[i][j];
    }
    cout << endl;
  }
}