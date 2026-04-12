#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(), (x).end()
static const int INF (1<<30);

int main() {
  int H, W;
  cin >> H >> W;
  vector<vector<char> > a(H, vector<char>(W));
  vector<vector<int> > del(H, vector<int>(W, 0));

  rep(i, H) {
    rep(j, W) {
      cin >> a[i][j];
    }
  }

  int ans = 0;
  rep(i, H) {
    bool black = false;
    rep(j, W) {
      if (a[i][j] == '#') black = true;
    }

    if (!black) {
      rep(j, W) del[i][j] = 1;
    }

  }


  rep(j, W) {
    bool black = false;
    rep(i, H) {
      if (a[i][j] == '#') black = true;
    }

    if (!black) {
      rep(i, H) del[i][j] = 1;
    }

  }


  rep(i, H) {
    bool nonexist = true;
    rep(j, W) {
      if (del[i][j] == 1) continue;
      else nonexist = false;

      cout << a[i][j];
    }
    if (!nonexist) cout << endl;
  }


  return 0;
}