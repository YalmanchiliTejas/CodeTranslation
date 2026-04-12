#include <algorithm>
#include <cmath>
#include <chrono>
#include <cstdio>
#include <ctime>
#include <iostream>
#include <map>
#include <random>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

#define FOR(i,m,n) for(int i=(m);i<(n);++i)
#define REP(i,n) FOR(i,0,n)
#define ALL(v) (v).begin(),(v).end()
/*---------------------------------------*/

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  // freopen("input.txt", "r", stdin);

  int h, w; cin >> h >> w;
  vector<vector<char> > a(h, vector<char>(w));
  REP(i, h) REP(j, w) cin >> a[i][j];

  REP(i, a.size()) {
    bool white = true;
    REP(j, w) {
      if (a[i][j] == '#') {
        white = false;
        break;
      }
    }
    if (white) {
      a.erase(a.begin() + i);
      --i;
    }
  }
  REP(j, a[0].size()) {
    bool white = true;
    REP(i, a.size()) {
      if (a[i][j] == '#') {
        white = false;
        break;
      }
    }
    if (white) {
      REP(i, a.size()) a[i].erase(a[i].begin() + j);
      --j;
    }
  }

  REP(i, a.size()) {
    REP(j, a[i].size()) {
      cout << a[i][j];
    }
    cout << "\n";
  }
  return 0;
}
