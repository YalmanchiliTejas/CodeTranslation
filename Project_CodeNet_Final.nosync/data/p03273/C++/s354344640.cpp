#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define repr(i, n) for (int i = (n); i >= 0; --i)
#define FOR(i, m, n) for (int i = (m); i < (n); ++i)
#define FORR(i, m, n) for (int i = (m); i >= (n); --i)
#define ifaxb(a, x, b) if (a < x && x < b)
#define toInt(x) (x - '0')
#define vi vector<int>
#define vvi vector<vi>
#define vs vector<string>
#define vvs vector<vs>
#define all(x) x.begin(), x.end()
#define INF 2147483647
#define _INF -2147483647
#define pi 3.1415926536
#define MAXN 100004
using namespace std;
typedef long long ll;

int main() {
  int h, w;
  cin >> h >> w;
  vs a(h);
  rep(i, h) { cin >> a[i]; }
  // 一つでも行と列に#があればフラグが立つ
  vector<bool> row(h, false);
  vector<bool> col(w, false);
  rep(i, h) {
    rep(j, w) {
      if (a[i][j] == '#') {
        row[i] = true;
        col[j] = true;
      }
    }
  }
  // フラグが立っている文字のみを出力する
  rep(i, h) {
    if (row[i]) {
      rep(j, w) {
        if (col[j]) {
          cout << a[i][j];
        }
      }
      cout << endl;
    }
  }

  return 0;
}