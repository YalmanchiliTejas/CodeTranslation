#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i=0; i<n; i++)

int main() {
  int H, W;
  cin >> H >> W;
  vector<vector<char>> map(H, vector<char>(W));
  rep(i, H) {
    rep(j, W) {
      cin >> map.at(i).at(j);
    }
  }
  
  bool flag;
  rep(i, H) {
    flag = true;
    rep(j, W) {
      if (map.at(i).at(j) == '#') {
        flag = false;
        break;
      }
    }
    if (flag) {
      rep(j, W)
        map.at(i).at(j) = 'x';
    }
  }
  rep(j, W) {
    flag = true;
    rep(i, H) {
      if (map.at(i).at(j) == '#') {
        flag = false;
        break;
      }
    }
    if (flag) {
      rep(i, H)
        map.at(i).at(j) = 'x';
    }
  }
  
  rep(i, H) {
    flag = false;
    rep(j, W) {
      if (map.at(i).at(j) != 'x') {
        flag = true;
        cout << map.at(i).at(j);
      }
    }
    if (flag)
      cout << endl;
  }
}