#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define all(v) (v).begin(), (v).end()

int main() {
  int h, w;
  cin >> h >> w;
  vector<string> v(h);
  vector<bool> flagcol(w, false);
  vector<bool> flagrow(h, false);
  rep(i, h) {
    cin >> v[i];
  }
  // 行チェック
  rep(i, h) {
    rep(j, w) {
      if(v[i][j] == '#') {
        flagrow[i] = true;
        break;
      }
    }
  }
  // 列チェック
  rep(j, w) {
    rep(i, h) {
      if(v[i][j] == '#') {
        flagcol[j] = true;
        break;
      }
    }
  }

  rep(i, h) {
    if(flagrow[i] == false) continue;
    rep(j, w) {
      if(flagcol[j] == false) continue;
      cout << v[i][j];
    }
    cout << endl;
  }
}
