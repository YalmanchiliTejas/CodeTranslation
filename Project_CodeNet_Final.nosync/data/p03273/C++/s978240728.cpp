// 解説放送 天才か？？
#include <bits/stdc++.h>
#define ll long long
#define rep(i,n) for(ll i = 0; i < n; i++)
using namespace std;
// プログラム実行中に変わらない場所に宣言した場合はboolの初期値はfalse

int main() {
  int h, w;
  cin >> h >> w;
  string board[110];
  rep(i,h) cin >> board[i];
  bool bx[110];
  bool by[110];
  rep(i,h) bx[i] = false;
  rep(i,w) by[i] = false; // 関数内などに宣言すると初期値は不定
  rep(i,h) {
    rep(j,w) {
      if (board[i][j] == '#') {
        bx[i] = true;
        by[j] = true;
      }
    }
  }
  rep(i,h) {
    if (bx[i]) {
      rep(j,w) {
        if (by[j]) cout << board[i][j];
      }
      cout << endl;
    }
  }
}