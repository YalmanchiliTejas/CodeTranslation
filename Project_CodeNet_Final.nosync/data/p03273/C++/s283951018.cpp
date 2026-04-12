#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < (int)(n); i++)

int main() {
  int H, W;
  cin >> H >> W;
  
  vector<vector<char>> before(H, vector<char>(W));
  rep(i, H)
    rep(j, W)
      cin >> before.at(i).at(j);
  
  vector<int> tate(H, 0);
  vector<int> yoko(W, 0);
  
  rep(i, H) {
    rep(j, W) {
      if (before.at(i).at(j) == '#') {
        break;
      }
      if (j == W -1)
        tate.at(i) = 1;
    }
  }
  
  rep(j, W) {
    rep(i, H) {
      if (before.at(i).at(j) == '#') {
        break;
      }
      if (i == H -1)
        yoko.at(j) = 1;
    }
  }
  
  rep(i, H) {
    if (tate.at(i) == 1) 
      continue;
    
    rep(j, W) {
      if (yoko.at(j) == 1)
        continue;
      
      cout << before.at(i).at(j);
    } 
    cout << endl;
    
  }
}