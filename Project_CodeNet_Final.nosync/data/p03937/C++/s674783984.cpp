#include <algorithm>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <queue>
#include <map>
#include <set>

#define rep(i,n) for (int i = 0; i < (n); ++i)

using namespace std;

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  cout << setprecision(20) << fixed;

  int h, w;
  cin >> h >> w;

  char maze[10][10];

  rep(y, h) {
    cin >> maze[y];
  }
  int cnt = 0;
  rep(y, h) {
    rep(x, w) {
      if (maze[y][x] == '#') cnt++;
    }
  }
  cout << ((cnt == h+w-1) ? "Possible" : "Impossible") << endl;

  return 0;
}