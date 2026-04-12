#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
  int H, W;
  cin >> H >> W;
  vector<vector<char>> data(H, vector<char>(W));
  
  for (int i = 0; i < H; i++) {
      for (int j = 0; j < W; j++){
          cin >> data.at(i).at(j);
      }
  }
  
  for (int i = 0; i < H; i++) {
      for (int j = 0; j < W; j++){
          if (data.at(i).at(j) == '#'){
              cout << '#';
          }
          else {
              int a = 0;
              int b = 0;
              for (int k = 0; k < W; k++){
                  if (data.at(i).at(k) == '.'){
                      a++;
                  }
              }      
              if (a != W && a != 0){
                  for (int l = 0; l < H; l++){
                      if (data.at(l).at(j) == '.'){
                          b++;
                      }
                  }
              }
              if (b != H && b != 0){
                  cout << '.';
              }
          }
          if (j == W - 1){
              int c = 0;
              for (int k = 0; k < W; k++){
                  if (data.at(i).at(k) == '.'){
                      c++;
                  }
              }
              if (c != W){
                  cout << endl;
              }
          }
      }
  }  
}