#include <bits/stdc++.h>
using namespace std;

int main() {
  int H, W;
  cin >> H >> W;
  vector<vector<char>> vec(H, vector<char>(W));
  
  for(int i=0; i<H; i++){
    for(int j=0; j<W; j++){
      cin >> vec.at(i).at(j);
    }
  }
  for(int j=0; j<W; j++){
    for(int i=0; i<H; i++){
      if(vec.at(i).at(j)=='.'){
        if(i==H-1){
          for(int i=0; i<H; i++){
            vec.at(i).at(j)='+';
          }
        }
      }
      else{
        break;
      }
    }
  }
  for(int i=0; i<H; i++){
    for(int j=0; j<W; j++){
      if(vec.at(i).at(j)=='.'||vec.at(i).at(j)=='+'){
        if(j==W-1){
          for(int j=0; j<W; j++){
            vec.at(i).at(j)='-';
          }
        }
      }
      else{
        break;
      }
    }
  }

  for(int i=0; i<H; i++){
    for(int j=0; j<W; j++){
      if(vec.at(i).at(j)=='-'){
        if(j==W-1){
          
        }
      }
      else{
        if(vec.at(i).at(j)!='+'){
          cout << vec.at(i).at(j);
        }
        if(j==W-1){
          cout << endl;
        }
      }
    }
  }
}
