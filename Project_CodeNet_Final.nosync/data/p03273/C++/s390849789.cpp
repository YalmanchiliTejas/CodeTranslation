#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep_s(i, s, n) for (int i = (int)(s); i < (int)(n); i++)
using ll = long long;
using vi = vector<int>;
using vll = vector<ll>;

int main() {
  int h, w;
  cin >> h >> w;

  vector<char> a(h * w);
  vector<bool> enable(h * w);

  rep(i, h * w) {
    cin >> a[i];
    enable[i] = true;
  }

  // 横検索
  rep(_h, h) {
    bool is_white = true;
    rep(_w, w) {
      if (a[w * _h + _w] == '#') {
        is_white = false;
        break;
      }
    }
    if (is_white) {
      // 無効化しておく
      rep(_w, w) {
        enable[w * _h + _w] = false;
      }
    }
  }

  // 縦検索
  rep(_w, w) {
    bool is_white = true;
    rep(_h, h) {
      if (a[w * _h + _w] == '#') {
        is_white = false;
        break;
      }
    }
    if (is_white) {
      // 無効化しておく
      rep(_h, h) {
        enable[w * _h + _w] = false;
      }
    }
  }

  rep(_h, h) {
    bool is_out = false;
    rep(_w, w) {
      if (enable[w * _h + _w]) {
        is_out = true;
        cout << a[w * _h + _w];
      }
    }
    if (is_out) {
      cout << endl;
    }
  }

}
