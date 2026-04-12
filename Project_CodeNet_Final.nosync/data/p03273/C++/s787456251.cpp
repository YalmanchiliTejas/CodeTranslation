#include <bits/stdc++.h>
using namespace std;

int main() {
  int H, W;
  cin >> H >> W;
  vector<vector<char>> T(H,vector<char>(W));
  for (int i = 0; i < H; i++) {
    for (int j = 0; j < W ; j++){
      cin >> T.at(i).at(j);
    }
  }
  int p1=0;
  vector<int> H1(H,0);
  vector<int> W1(W,0);
  
  for (int i = 0; i < H; i++) {
    for (int j = 0; j < W ; j++){
      if (T.at(i).at(j)=='#'){
        p1++;
      }
    }
  if (p1==0){
    H1.at(i)=1;
  }
    p1=0;
  }

  for (int i = 0; i < W; i++) {
    for (int j = 0; j < H ; j++){
      if (T.at(j).at(i)=='#'){
        p1++;
      }
    }
  if (p1==0){
    W1.at(i)=1;
  }
    p1=0;
  }


  for (int i=0;i<H;i++){
    if (H1.at(i)==0){
      for (int j=0;j<W;j++){
        if (W1.at(j)==0){
          cout << T.at(i).at(j);
        }
        if (j==W-1){
          cout << endl;
        }
      }
    }
  }
     
}