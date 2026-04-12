#include <bits/stdc++.h>
#define rep(i,cc,n) for(int i=cc;i<=n;++i)
using namespace std;
 
int main() {
  int H, W;
  cin >> H >> W;
 
  vector<string> board(H);
  vector<bool> row(H, false);
  vector<bool> col(W, false);
  rep(i,0,H-1) {
    cin >> board[i];
    rep(j,0,W-1) {
      if (board[i][j] == '#') {
        row[i] = true;
        col[j] = true;
      }
    }
  }
 
  rep(i,0,H-1) {
    if (row[i]) {
      rep(j,0,W-1) {
        if (col[j]) {
          cout << board[i][j];
        }
      }
      cout << endl;
    }
  }
 
  return 0;
}
