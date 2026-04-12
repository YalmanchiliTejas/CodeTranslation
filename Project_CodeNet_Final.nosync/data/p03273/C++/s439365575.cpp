#include <iostream>
#include <string>
#include <vector>
#define rep(i, n) for(int i = 0; i < (n); ++i)
using namespace std;

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int h, w; cin >> h >> w;
  vector<string> s(h);
  rep(i, h) cin >> s[i];
  vector<bool> row(h, false), column(w, false);

  rep(i, h) rep(j, w) {
    if(s[i][j]=='#') {
      row[i] = column[j] = true;
    }
  }
  rep(i, h) {
    if(row[i]) {
      rep(j, w) {
        if(column[j]) {
          cout << s[i][j];
        }
      }
      cout << '\n';
    }
  }
  return 0;
}
