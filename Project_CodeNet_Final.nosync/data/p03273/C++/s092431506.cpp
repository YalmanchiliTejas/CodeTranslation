#include <bits/stdc++.h>
using namespace std;

int main() {
  int H, W;
  cin >> H >> W;
  vector<vector<char>>A(H, vector<char>(W));
  
  for(int i = 0; i < H; i++){
    for(int j = 0; j < W; j++){
      cin >> A.at(i).at(j);
    }
  }
  
 for(int i = 0; i < H; i++){
    for(int j = 0; j < W; j++){
      if(A.at(i).at(j) == '#')
        j = W;
      if(j == W - 1){
        for(int k = 0; k < W; k++){
          A.at(i).at(k) = 'x';
        }
      }
    }
  }
  
   for(int i = 0; i < W; i++){
    for(int j = 0; j < H; j++){
      if(A.at(j).at(i) == '#')
        j = H;
      if(j == H - 1){
        for(int k = 0; k < H; k++){
          A.at(k).at(i) = 'x';
        }
      }
    }
  }
  
  for(int i = 0; i < H; i++){
    int C = 0;
    for(int j = 0; j < W; j++){
      if(A.at(i).at(j) != 'x')
        cout << A.at(i).at(j);
      else
        C++;
      if(j == W - 1 && C != W)
        cout << endl;
    }
  }
}
