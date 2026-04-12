#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
  int h, w;
  cin >> h >> w;

  vector<vector<char>> a(h, vector<char>(w,'*'));

  rep(i,h) rep(j,w) cin >> a[i][j];

  rep(i,h) {
      bool flag = true;
      rep(j,w) if (a[i][j] == '#') flag = false;
      if (flag) rep(j,w) a[i][j] = 'o';

  }
  rep(i,w) {
      bool flag = true;
      rep(j,h) if (a[j][i] == '#') flag = false;
      if (flag) rep(j,h) a[j][i] = 'o';
  }
  
  rep(i,h){
    rep(j,w) {
      if (a[i][j] != 'o') cout << a[i][j];
    }
    rep (j,w) {
      if (a[i][j] != 'o') {
        cout << endl;
        break;
      }
    }
  }
}