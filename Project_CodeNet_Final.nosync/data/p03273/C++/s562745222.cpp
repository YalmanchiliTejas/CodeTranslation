#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main(){
  int H, W;
  cin >> H >> W;
  vector<vector<char>> A(H, vector<char>(W));
  for(int i = 0; i < H; i++){
    for(int j = 0; j < W; j++){
      cin >> A.at(i).at(j);
    }
  }
  
  for(int i = 0; i < H; i++){
    bool blank = true;
    for(int j = 0; j < W; j++){
      if(A.at(i).at(j) == '#'){
        blank = false;
        break;
      }
    }
    if(blank == true){
      for(int j = 0; j < W; j++){
        A.at(i).at(j) = '*';
      }
    }
  }
  
  for(int j = 0; j < W; j++){
    bool blank = true;
    for(int i = 0; i < H; i++){
      if(A.at(i).at(j) == '#'){
        blank = false;
        break;
      }
    }
    if(blank == true){
      for(int i = 0; i < H; i++){
        A.at(i).at(j) = '*';
      }
    }
  }
  
  
  for(int i = 0; i < H; i++){
    bool blank = true;
    for(int j = 0; j < W; j++){
      if(A.at(i).at(j) != '*'){
        cout << A.at(i).at(j);
        blank = false;
      }
    }
    if(blank == false) cout << endl;
  }
  
}