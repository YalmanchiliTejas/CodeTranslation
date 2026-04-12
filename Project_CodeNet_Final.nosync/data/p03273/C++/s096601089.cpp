#include <algorithm>
#include <cmath>
#include <functional>
#include <iostream>
#include <string>
#include <vector>
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define repR(i, n) for(int i = (n) - 1; i > -1; i--)
#define rep1(i, n) for(int i = 1; i < (int)(n + 1); i++)
#define rep1R(i, n) for(int i = (n); i > 0; i--)
typedef long long ll;
typedef unsigned long long ull;
using namespace std;

int main() {
  int H, W;
  cin >> H >> W;
  vector<vector <char> > grid(H, vector<char>(W, 0));
  rep(y, H) {
    rep(x, W) {
      cin >> grid[y][x];
    }
  }
  vector<bool> blank_rows(W);
  vector<bool> blank_lines(H);
  rep(x, W) {
    bool blank = true;
    rep(y, H) {
      if (grid[y][x] == '#') { blank = false; break; }
    }
    if (blank) blank_rows[x] = true;
  }
  rep(y, H) {
    bool blank = true;
    rep(x, W) {
      if (grid[y][x] == '#') { blank = false; break; }
    }
    if (blank) blank_lines[y] = true;
  }
  rep(y, H) {
    if (blank_lines[y]) continue;
    rep(x, W) {
      if (blank_rows[x]) continue;
      cout << grid[y][x];
    }
    cout << endl;
  }
  return 0;
}
