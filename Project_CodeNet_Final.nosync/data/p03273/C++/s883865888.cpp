#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
#define repi(i, a, b) for (int i = (a); i < (b); i++)
#define all(a) (a).begin(), (a).end()

using namespace std;
using i32 = int;
using i64 = long long;
using f64 = double;
using vi32 = vector<i32>;
using vvi32 = vector<vi32>;
using vi64 = vector<i64>;
using vvi64 = vector<vi64>;
using vstr = vector<string>;

template<typename T> inline bool amin(T &x, T y) { if (y < x) { x = y; return true; } return false; }
template<typename T> inline bool amax(T &x, T y) { if (x < y) { x = y; return true; } return false; }

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int h, w;
  cin >> h >> w;
  vi32 hi, wi;
  vstr board(h);
  rep(i, h) cin >> board[i];
  rep(i, h) {
    bool b = false;
    rep(j, w) {
      if (board[i][j] == '#') b = true;
    }
    if (b) hi.push_back(i);
  }
  rep(i, w) {
    bool b = false;
    rep(j, h) {
      if (board[j][i] == '#') b = true;
    }
    if (b) wi.push_back(i);
  }
  rep(i, hi.size()) {
    rep(j, wi.size()) {
      cout << board[hi[i]][wi[j]];
    }
    cout << endl;
  }
  return 0;
}