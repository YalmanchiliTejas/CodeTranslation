#include <bits/stdc++.h>
using namespace std;

int main() {
  int H, W;
  cin >> H >> W;
  vector<vector<char>> A(H, vector<char>(W));
  for (int i = 0; i < H; i++) {
    for(int j = 0; j < W; j++){
      cin >> A.at(i).at(j);
    }
    cout << endl;
  }
  
  // 何行目を削るか
  vector<int> B(100, -1);
  int b = 0;

  for(int i = 0; i < H; i++){
    for(int j = 0; j < W; j++){
      if(A.at(i).at(j) != '.'){
        break;
      }
      if(j == W-1){
        B.at(b) = i;
        b++;
      }
    }
  }

  // 何列目を削るか
  vector<int> C(100, -1);
  int c = 0;

  for(int i = 0; i < W; i++){
    for(int j = 0; j < H; j++){
      if(A.at(j).at(i) != '.'){
        break;
      }
      if(j == H-1){
        C.at(c) = i;
        c++;
      }
    }
  }
  
  b = 0;
  c = 0;

  for(int i = 0; i < H; i++){
    if(B.at(b) == i){
      b++;
      continue;
    }
    for(int j = 0; j < W; j++){
     if(C.at(c) == j){
       if(j == W-1){
         cout << endl;
         c = 0;
         break;
       }
        c++;
        continue;
      }
      cout << A.at(i).at(j);
      if(j == W-1){
        cout << endl;
        c = 0;
        break;
      }
    }
  }

}
