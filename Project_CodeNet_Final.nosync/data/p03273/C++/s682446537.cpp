#include <bits/stdc++.h>
#include <vector>
#define rep(i, n) for(int i = 0; i < n; ++i)
#define ll long long
using namespace std;

int main() {
  int h, w;
  cin >> h >> w;
  vector<vector<char>> glid(h, vector<char> (w));
  
  rep(i, h) {
    rep(j, w) {
      cin >> glid[i][j];
    }
  }
  
  //行検索
  vector<bool> row(h);
  rep(i, h) {
    bool flg = true;
    char color = glid[i][0];
    rep(j, w) {
      if(glid[i][j] == '.') {
//        cout << "true (" << i+1 << "," << j+2 << ")" << endl;
        continue;
      } else {
//        cout << "false" << endl;
        flg = false;
        break;
      }
    }
    if(flg) {
//        cout << "flgtrue" << endl;
        row[i] = true;
    }
  }
  
  //列検索
  vector<bool> col(w);
  rep(i, w) {
    bool flg = true;
    rep(j, h) {
      if(glid[j][i] == '.') continue;
      else {
        flg = false;
        break;
      }
    }
    if(flg) col[i] = true;
  }
  
  //
  rep(i, h) {
    if(!row[i]) {
      rep(j, w) {
        if(!col[j]) cout << glid[i][j];
      }
      cout << endl;
    }
  }   
  
  return 0;
}
