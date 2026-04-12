#include <bits/stdc++.h>
using namespace std;
int main(){
  int H,W;
  cin >> H >> W;
  vector<vector<char>> a(H,vector<char>(W));
  vector<bool> R(H,false);
  vector<bool> C(W,false);
  for (int i = 0; i < H; i++){
    for (int j = 0; j < W; j++){
      cin >> a[i][j];
      if (a[i][j] == '#'){
        R[i] = true;
        C[j] = true;
      }
    }
  }
  for (int i = 0; i < H; i++){
    for (int j = 0; j < W; j++){
      if (R[i] && C[j]) cout << a[i][j];      
    }
    if (R[i]) cout << endl;
  }
}