#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int H, W;
  cin >> H >> W;
  vector<vector<char>> a(H,vector<char>(W));
  for (int i = 0; i < H; i++){
    for (int j = 0; j < W; j++){
      cin >> a[i][j];
    }
  }
  
  vector<bool> cols(H,false);
  vector<bool> rows(W,false);
  
  
  for (int i = 0; i < H; i++){
    for (int j = 0; j < W; j++){
      if(a[i][j]=='#'){
        cols[i] = true;
        rows[j] = true;
      }
    }
  }

  for (int i = 0; i < H; i++){
    if(cols[i]){
      for (int j = 0; j < W; j++){
        if(rows[j]){
          cout << a[i][j];
        }
      }
      cout << endl;
    }
  }
  
}