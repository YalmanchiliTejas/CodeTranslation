#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i=0; i<(n); i++)

int main() {
  int H,W;
  cin >> H >> W;
  
  vector<vector<char>> a(H, vector<char>(W));
  rep(i,H){
    rep(j,W){
      cin >> a.at(i).at(j);
    }
  }
  
  vector<bool> row(H,false);
  vector<bool> column(W,false);
  
  rep(i,H){
    rep(j,W){
      if (a.at(i).at(j) == '#') row.at(i) = true;
    }
  }
  
  rep(j,W){
    rep(i,H){
      if (a.at(i).at(j) == '#') column.at(j) = true;
    }
  }
  
  rep(i,H){
    if (!row.at(i)) continue;
    rep(j,W){
      if (column.at(j)) cout << a.at(i).at(j);
    }
    cout << endl;
  }

}
