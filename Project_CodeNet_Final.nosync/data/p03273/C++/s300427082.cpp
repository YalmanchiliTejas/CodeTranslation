#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int H, W;
  cin >> H >> W;
  vector<vector<char>> matrix(H, vector<char>(W));
  for (int i = 0; i < H; i++){
    string s;
    cin >> s;
    for (int j = 0; j < W; j++){
      matrix.at(i).at(j) = s.at(j);
    }
  }
  
  bool a = true;
  
  for (int i = 0; i < H; i++){
    for (int j = 0; j < W; j++){
      if (matrix.at(i).at(j) == '#'){
        a = false;
      }
    }
    if (a){
      for (int j = 0; j < W; j++){
        matrix.at(i).at(j) = '\0';
      }
    }
    a = true;
  }
  
  for (int j = 0; j < W; j++){
    for (int i = 0; i < H; i++){
      if (matrix.at(i).at(j) == '#'){
        a = false;
      }
    }
    if (a){
      for (int i = 0; i < H; i++){
        matrix.at(i).at(j) = '\0';
      }
    }
    a = true;
  }
  
  bool b = false;
  
  for (int i = 0; i < H; i++){
    for (int j = 0; j < W; j++){
      if (matrix.at(i).at(j) == '.' || matrix.at(i).at(j) == '#'){
        cout << matrix.at(i).at(j);
      }
      if (matrix.at(i).at(j) == '.' || matrix.at(i).at(j) == '#'){
        b = true;
      }
    }
    if (b){
      cout << endl;
    }
  }
}