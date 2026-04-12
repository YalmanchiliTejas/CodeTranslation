#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)

int main(){
  int H, W; cin >> H >> W;
  vector<vector<char>> a(H, vector<char>(W));
  for(int i = 0; i < H; i++){
    for(int j = 0; j < W; j++){
      cin >> a.at(i).at(j);
    }
  }
  
  vector<bool> row(H, false);
  vector<bool> column(W, false);
  
  for(int i = 0; i < H; i++){
    for(int j = 0; j < W; j++){
      if(a.at(i).at(j) == '#'){
        row[i] = true;
        column[j] = true;
      }
    }
  }
  
  for(int i = 0; i < H; i++){
    bool disp = false;
    for(int j = 0; j < W; j++){
      if(row[i] && column[j]){
        cout << a.at(i).at(j);
        disp = true;
      }
    }
    if(disp) cout << endl;
  }
}