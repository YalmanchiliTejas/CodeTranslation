#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define int long long

signed main() {
  int h,w;
  cin >> h >> w;

  vector<vector<char>> board(h, vector<char> (w));

  vector<int> row(h, 0);
  vector<int> col(w, 0);
  rep(i,h) rep(j,w) {
    cin >> board[i][j];
    if(board[i][j] == '#') {
      row[i] = 1;
      col[j] = 1;
    }
  }

  for (int i = 0; i < h; i++) {
    if(!row[i]) continue;
    for (int j = 0; j < w; j++) {
      if(!col[j]) continue;
      cout << board[i][j];
    }
    cout << '\n';
  }


}
