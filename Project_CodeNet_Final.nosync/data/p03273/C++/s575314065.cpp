#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)

int main() {
  int H, W; cin >> H >> W;
  vector<vector<char>> mp(H, vector<char>(W));
  vector<vector<bool>> flag(H, vector<bool>(W, false));
  rep(i, H) {
    rep(j, W) {
      cin >> mp.at(i).at(j);
    }
  }
  rep(i, H) {
    int count =  0;
    rep(j, W) {
      if (mp.at(i).at(j) == '.') {
        count++;
      }
    }
    if (count == W) {
      rep(j, W) {
        flag.at(i).at(j) = true;
      }
    }
  }
  rep(i, W) {
    int count =  0;
    rep(j, H) {
      if (mp.at(j).at(i) == '.') {
        count++;
      }
    }
    if (count == H) {
      rep(j, H) {
        flag.at(j).at(i) = true;
      }
    }
  }
  
  rep(i, H) {
    int cnt = 0;
    rep(j, W) {
      if (flag.at(i).at(j) == false) {
        cout << mp.at(i).at(j);
        cnt++;
      }
      if (j == W-1) {
        if (cnt != 0) {
          cout << endl;
        }
      }
    }
  }
}

