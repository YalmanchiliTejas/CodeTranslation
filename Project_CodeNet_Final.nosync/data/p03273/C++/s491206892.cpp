#include <bits/stdc++.h>
using namespace std;

int main() {
  int H, W;
  cin >> H >> W;
  vector<vector<char>> a(H, vector<char>(W));
  for(int i = 0; i < H; i++){
      for(int j = 0; j < W; j++){
          cin >> a.at(i).at(j);
      }
  }

  //行を空白に
  for(int i = 0; i < H; i++){
      int counter = 0;
      for(int j = 0; j < W; j++){
          if(a.at(i).at(j) == '.' || a.at(i).at(j) == ' ') counter++;
      }
      if(counter == W){
          for(int j = 0; j < W; j++){
              a.at(i).at(j) = ' ';
          }
      }
  }
  //列を空白に
  for(int i = 0; i < W; i++){
      int counter = 0;
      for(int j = 0; j < H; j++){
          if(a.at(j).at(i) == '.' || a.at(j).at(i) == ' ') counter++;
      }
      if(counter == H){
          for(int j = 0; j < H; j++){
              a.at(j).at(i) = ' ';
          }
      }
  }

  for(int i = 0; i < H; i++){
      int counter2 = 0;
      for(int j = 0; j < W; j++){
          if(a.at(i).at(j) != ' ') cout << a.at(i).at(j);
          else counter2++;
          if(j == W-1 && counter2 != W){
              cout << endl;
          }
      }
  }
}
