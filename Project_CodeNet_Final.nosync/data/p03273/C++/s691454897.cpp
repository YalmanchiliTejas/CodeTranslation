#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
  int h, w;
  cin >> h >> w;
  vector<string> a(h);
  rep(i, h) cin >> a[i];
  vector<bool> row(h);
  vector<bool> line(w);
  rep(i, h) {
    rep(j, w) {
      if(a[i][j] == '#') {
        row[i] = true;
        line[j] = true;
      }
    }
  }
  rep(i, h) {
    if(row[i]) {
      rep(j, w) {
        if(line[j]) cout << a[i][j];
      }
    }
    cout << endl;
  }
  return 0;
}