#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;

int main() {
  int h,w;
  cin >> h >> w;

  vector<vector<char>> board(h, vector<char> (w));
  vector<vector<int>> visited(h, vector<int> (w, 0));
  rep(i,h) rep(j,w) cin >> board[i][j];

  bool ok = true;
  int curx = 0, cury = 0;
  while (true) {
    visited[curx][cury] = 1;
    if(curx == h - 1 && cury == w - 1) break;
    if(curx + 1 < h && board[curx + 1][cury] == '#') curx++;
    else if(cury + 1 < w && board[curx][cury + 1] == '#') cury++;
    else {
      ok = false;
      break;
    }
  }

  rep(i,h) rep(j,w) {
    if(board[i][j] == '#' && visited[i][j] == 0) ok = false;
  }
  if(ok) cout << "Possible" << '\n';
  else cout << "Impossible" << '\n';
}
