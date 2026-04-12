#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;

int main() {
  int H, W;
  cin >> H >> W;

  vector<vector<char>> a(H, vector<char>(W));
  rep(i, H) rep(j, W) cin >> a[i][j];

  set<int> I, J;

  rep(i, H) {
    int n = 0;
    rep(j, W) {
      if (a[i][j] == '.')
        n++;
    }
    if (n == W)
      I.insert(i);
  }

  rep(j, W) {
    int n = 0;
    rep(i, H) {
      if (a[i][j] == '.')
        n++;
    }
    if (n == H)
      J.insert(j);
  }

  rep(i, H) {
    if (I.find(i) != I.end())
      continue;
    rep(j, W) {
      if (J.find(j) == J.end())
        cout << a[i][j];
    }
    cout << endl;
  }
}