#include <bits/stdc++.h>
using namespace std;

int main() {
  int H, W;
  cin >> H >> W;
  vector<vector<char>> a(H, vector<char>(W));
  for(int i = 0; i < H; i++){
    for(int j = 0; j < W; j++)
      cin >> a.at(i).at(j);
  }
  int h = 0, w = 0;
 
    for(int i = 0; i < H - h; i++){
      int T = 1;
      for(int j = 0; j < W; j++){
        if(a.at(i).at(j) == '.')
          T *= 1;
        else
          T *= 0;
      }
      if(T == 1){
        h++;
        for(int k = i; k < (H - 1); k++){
          for(int j = 0; j < W; j++){
            a.at(k).at(j) = a.at(k + 1).at(j);
          }
        }
        for(int j = 0; j < W; j++)
          a.at(H - 1).at(j) = '.';
        i = i - 1;
      }
    }
    
    for(int i = 0; i < W - w; i++){
      int T = 1;
      for(int j = 0; j < H; j++){
        if(a.at(j).at(i) == '.')
          T *= 1;
        else
          T *= 0;
      }
      if(T == 1){
        w++;
        for(int k = i; k < (W - 1); k++){
          for(int j = 0; j < H; j++){
            a.at(j).at(k) = a.at(j).at(k + 1);
          }
        }
        for(int j = 0; j < H; j++)
           a.at(j).at(W - 1) = '.';
        i = i - 1;
      }
    }
  
  for(int i = 0; i < (H - h); i++){
    for(int j = 0; j < (W - w); j++){
      cout << a.at(i).at(j);
      if(j == (W - w - 1))
        cout << endl;
    }
  }
}
