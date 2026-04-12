#include <bits/stdc++.h>
using namespace std;

int main() {
  int H;
  int W;
  cin >> H >> W;
  vector<vector<char>> data(H, vector<char>(W));
  for(int i=0; i<H; i++){
    for(int j=0; j<W; j++){
      cin >> data.at(i).at(j);
    }
  } 
  
  int count=0;
  int w=W;
  
  for(int i=0; i<H; i++){
    count = 0;
    for(int j=0; j<W; j++){
      if(data.at(i).at(j)=='.') count++;
      if(count==W){
        for(int k=0; k<W; k++){
          data.at(i).at(k) = 'x';
        }
      }
    }
  }
  
  for(int j=0; j<W; j++){
    count = 0;
    for(int i=0; i<H; i++){
      if(data.at(i).at(j)=='.' || data.at(i).at(j)=='x') count ++;
      if(count==H){
        for(int k=0; k<H; k++){
          data.at(k).at(j) = 'x';
        }
        w--;
      }
    }
  }
  
  for(int i=0; i<H; i++){
    count = 0;
    for(int j=0; j<W; j++){
      if(data.at(i).at(j)!='x'){
        cout << data.at(i).at(j);
        count++;
        if(count==w) cout <<endl;
      }
    }
  }
          
}
