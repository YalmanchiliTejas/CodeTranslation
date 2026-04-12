#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int H, W;
  cin >> H >> W;
  vector< vector<char> > A(H, vector<char>(W));
  for ( int i = 0; i < H; i++){
      for ( int k = 0; k < W; k++){
          cin >> A.at(i).at(k);
      }
  }
  
  vector<bool> A_row(H,false);
  vector<bool> A_col(W,false);

  for(int i = 0; i < H; i++){
      for(int k = 0; k < W; k++){
          if(A.at(i).at(k) == '#') A_row.at(i) = true;
      }
  }

  for(int k = 0; k < W; k++){
      for(int i = 0; i < H; i++){
          if(A.at(i).at(k) == '#') A_col.at(k) = true;
      }
  }
 
  for ( int i = 0; i < H; i++){
      if(A_row.at(i) == true){
          for ( int k = 0; k < W; k++){
              if(A_col.at(k) == true){
                  cout << A.at(i).at(k);
              }
          }
      }
      cout << endl;
      
  }
  return 0;


}