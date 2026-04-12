#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
using namespace std;

int main() {
  int H, W;
  cin >> H >> W;
  
  vector<vector<char>> masu(H, vector<char>(W));
  
  for(int i = 0; i < H; i++){
    for(int j = 0; j < W; j++){
      cin >> masu.at(i).at(j);
    }
  }
  
  vector<bool> h_w(H, true);
  vector<bool> w_w(W, true);
  
  for(int i = 0; i < H; i++){
    for(int j = 0; j < W; j++){
      if(masu.at(i).at(j) == '#'){
        h_w.at(i) = false;
        break;
      }
    }
  }
  
  for(int i = 0; i < W; i++){
    for(int j = 0; j < H; j++){
      if(masu.at(j).at(i) == '#'){
        w_w.at(i) = false;
        break;
      }
    }
  }
  
  for(int i = 0; i < H; i++){
    if(h_w.at(i) == false){
      for(int j = 0; j < W; j++){
        if(w_w.at(j) == false)
          cout << masu.at(i).at(j);
      }
      cout << endl;
    }
  }

}
