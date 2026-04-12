#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < n; ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;
 
int main() {
  // Declare values
  int H, W; cin >> H >> W;
  vector<vector<char>> table(H, vector<char>(W));
  // input
  rep(i, H) {
    rep(j, W) {
      cin >> table.at(i).at(j); 
    }
  }
 
  // Checkpoint
  vector<bool> line(H, false);
  vector<bool> quene(W, false);
 
  rep(i, H) {
    rep(j, W) {
      if (table.at(i).at(j) == '#') {
        line.at(i) = true;
        quene.at(j) = true;
      }
    }
  }
 
 
  rep(i, H) {
    if (line.at(i)){
      rep(j, W) {
        if (quene.at(j)) {
          cout << table.at(i).at(j);
        }
      }
      cout << endl;
    }
  }
  
  return 0; 
}