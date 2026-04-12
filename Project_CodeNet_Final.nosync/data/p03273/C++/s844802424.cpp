#include <bits/stdc++.h>
#define FOR(i, a, b) for(int i=(a); i<(b); i++)
#define REP(i, n) FOR(i, 0, n)
#define all(x) (x).begin(), (x).end()
#define bit(x) (1L << (x))
#define sz(x) static_cast<int>(x.size())
using ll = long long;
using namespace std;

int main() {
  int h, w; cin >> h >> w;
  vector<vector<char>> grid(h, vector<char>(w));
  REP(y, h)REP(x, w) cin >> grid[y][x];

  map<int, bool> mx, my;

  REP(y, h){
    bool f = false;
    REP(x, w){
      f |= grid[y][x] == '#';
    }
    if(!f) my[y] = true;
  }

  REP(x, w){
    bool f = false;
    REP(y, h){
      f |= grid[y][x] == '#';
    }
    if(!f) mx[x] = true;
  }

  REP(y, h){
    REP(x, w){
      if(my[y] || mx[x]) continue;
      cout << grid[y][x];
    }
    if(!my[y]) cout << endl;
  }
  return 0;
}
