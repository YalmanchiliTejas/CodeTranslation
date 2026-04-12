#include <bits/stdc++.h>
#define rep(i,x,n) for(int i=x; i<(int)(n); i++)
#define rep_eq(i,x,n) for(int i=x; i<=(int)(n); i++)
using namespace std;

int main() {
  int H,W; cin >>H >>W;
  vector<string> a(H);
  rep(i,0,H) cin >>a[i];
  vector<bool> row(H);
  vector<bool> col(W);
  rep(i,0,H) {
    rep(j,0,W) {
      if (a[i][j] == '#') {row[i] = true; col[j] = true;}
    }
  }
  rep(i,0,H) {
    if (row[i]) {
      rep(j,0,W) {
        if (col[j]) cout <<a[i][j];
      }
      cout << endl;
    }
  }
  return 0;
}
