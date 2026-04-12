/*
    問題をよく読もう！
    論理的に考えよう！
    サンプルを確認しよう!
    絶対に諦めるな！
    工夫をしろ！
    配列は少し多めにとっておく

    Twitterは終わるまでログアウト！
    （間違えて解法をツイートしてはいけないから）

*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <map>
#include <functional>
#include <cmath>
using namespace std;
#define rep(i, n) for(int i=0; i<n; ++i)
typedef long long ll;
//必要な宣言

void solve();
bool func(int, int);

int h, w;
char a[101][101];
int b[101][101] = {};
int c[101];

int main() {
  cin >> h >> w;
  rep(i, h) {rep(j, w) cin >> a[i][j]; }

  solve();

  return 0;
}

void solve() {

  rep(i, h) {
    if(func(0, i)) {
      c[i] = 1;
      rep(j, w) b[i][j] = 1;
    }
  }

  rep(i, w) {
    if(func(1, i)) {
      rep(j, h) b[j][i] = 1;
    }
  }

  rep(i, h) {
    rep(j, w) {
      if(!b[i][j]) cout << a[i][j];
    }
    if(!c[i]) cout << endl;
  }

}

bool func(int n, int m) {

  if(!n) {
    rep(j, w) {
      if(a[m][j]=='#') return false;
    }
    return true;
  }else {
    rep(j, h) {
      if(a[j][m]=='#') return false;
    }
    return true;
  }
}
