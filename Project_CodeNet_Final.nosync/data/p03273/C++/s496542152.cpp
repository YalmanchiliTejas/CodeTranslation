#include <bits/stdc++.h>
using namespace std;

int main() {
  int H, W;
  cin >> H >> W;

  // Make grid
  vector<vector<char>> grid(H, vector<char>(W));

  for(int i=0; i<H; i++){
    for(int j=0; j<W; j++){
      cin >> grid.at(i).at(j);
    }
  }

  // change dot to ! at "W"
  for(int i=0, dot=0; i<H; i++){
    for(int j=0; j<W; j++){
      if(grid.at(i).at(j) == '.'){
        dot++;
      }
      if(dot == W){
        for(int k=0; k<W; k++){
          grid.at(i).at(k) = '!';
        }
      }
    }
    dot=0;
  }

  // change dot to ! at "H"
  for(int i=0, dot=0; i<W; i++){
    for(int j=0; j<H; j++){
      if(grid.at(j).at(i) == '.' || grid.at(j).at(i) == '!' ){
        dot++;
      }
      if(dot == H){
        for(int k=0; k<H; k++){
          grid.at(k).at(i) = '!';
        }
      }
    }
    dot=0;
  }

  // skip !
  for(int i=0, count=0; i<H; i++){
    for(int j=0; j<W; j++){
      if(grid.at(i).at(j) == '!'){
        count++;
        continue;
      }
      else{
        cout << grid.at(i).at(j);
      }
    }
    if(count == W){
      count=0;
      continue;
    }
    else if(i == H-1){
      break;
    }
    else{
      count=0;
      cout << endl;
    }
  }
}