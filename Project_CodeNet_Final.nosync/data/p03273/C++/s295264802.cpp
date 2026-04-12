#include<bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;

int main() {
  int h,w; cin>>h>>w;
  vector<vector<char>> a(h, vector<char>(w));
  rep(i, h) rep(j, w) cin>>a[i][j];

  rep(i, h) {
    int cnt = 0;
    rep(j, w) if (a[i][j]=='.') cnt++;
    if (cnt==w) rep(j, w) a[i][j] = 'x';
  }
  rep(i, w) {
    int cnt = 0;
    rep(j, h) if (a[j][i]=='.'||a[j][i]=='x') cnt++;
    if (cnt==h) rep(j, h) a[j][i] = 'x';
  }
  rep(i, h) {
    int cnt = 0;
    rep(j, w) {
      if (a[i][j] != 'x') printf("%c", a[i][j]);
      else cnt++;
    }
    if (cnt != w) printf("\n");
  }
}
