#include <bits/stdc++.h>
using namespace std;

int main() {
  int H, W;
  cin >> H >> W;

  vector<vector<char>> a(H, vector<char>(W));
  vector<bool> flag_w(W,false);
  vector<bool> flag_h(H,false);
  
  for (int i = 0; i < H; i++) {
    for(int j = 0; j < W; j++){
      cin >> a.at(i).at(j);
      if(a.at(i).at(j) == '#'){
        flag_h.at(i) = true;
        flag_w.at(j) = true;
      }
    }
  }
  for (int i = 0; i < H; i++) {
    if(flag_h.at(i)){
      for(int j = 0; j < W; j++){
        if(flag_w.at(j)){
          cout << a.at(i).at(j);
        }
      }
      cout << endl;
    }
  }
return 0;
}
