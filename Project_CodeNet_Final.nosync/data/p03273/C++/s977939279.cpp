#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define _GLIBCXX_DEBUG

int main() {
  int H, W;
  cin >> H >> W;
  vector<string> a(H);
  rep(i,H) cin >> a[i];
  vector<bool> row(H);
  vector<bool> column(W);
  
  rep(i, H) {
    rep(j, W) {
      if (a[i][j]=='#') {
        row[i]=true;
        column[j]=true;
      }
    }
  }
  
  rep(i, H) {
    if (row[i]) {
      rep(j, W) {
        if (column[j]) cout << a[i][j];
      }
      cout << endl;
    }
  }
}
