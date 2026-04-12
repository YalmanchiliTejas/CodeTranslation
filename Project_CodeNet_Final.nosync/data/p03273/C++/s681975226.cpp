#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const double PI = acos(-1);
 
int main() {
  int H,W; cin >> H >> W;
  vector<string> board(H);
  for (int i = 0; i < H; i++) cin >> board[i];
  vector<bool> ycheck(H,false);
  vector<bool> xcheck(W,false);
  for (int i = 0; i < H; i++) {
    for (int j = 0; j < W; j++) {
      if (board[i][j] == '#') ycheck[i] = true;
    }
  }
  for (int j = 0; j < W; j++) {
    for (int i = 0; i < H; i++) {
      if (board[i][j] == '#') xcheck[j] = true;
    }
  }
  for (int i = 0; i < H; i++) {
    for (int j = 0; j < W; j++) {
      if (ycheck[i] && xcheck[j]) cout << board[i][j];
    }
    if (ycheck[i]) cout << endl;
  }
}