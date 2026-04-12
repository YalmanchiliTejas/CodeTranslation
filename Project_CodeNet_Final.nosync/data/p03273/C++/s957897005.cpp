#include <bits/stdc++.h>
#define REP(i, n) for(int i = 0; i < n; i++)
using namespace std;
using ll = long long;

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int H, W;
  cin >> H >> W;
  vector<vector<char>> a(H, vector<char>(W));
  REP(i, H) REP(j, W) cin >> a[i][j];
  set<int> retu;
  for(int i = 0; i < H; i++) {
    bool flag = true;
    for(int j = 0; j < W; j++) {
      if(a[i][j] == '#') {
        flag = false;
        break;
      }
    }
    if(flag) { retu.insert(i); }
  }
  set<int> gyo;
  for(int j = 0; j < W; j++) {
    bool flag = true;
    for(int i = 0; i < H; i++) {
      if(a[i][j] == '#') {
        flag = false;
        break;
      }
    }
    if(flag) { gyo.insert(j); }
  }

  for(int i = 0; i < H; i++) {
    if(retu.count(i) > 0) { continue; }
    for(int j = 0; j < W; j++) {
      if(gyo.count(j) > 0) { continue; }
      cout << a[i][j];
    }
    cout << endl;
  }

  return 0;
}