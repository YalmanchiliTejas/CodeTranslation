#include <bits/stdc++.h>
using namespace std;

int main() {
  int H, W;
  cin >> H >> W;
  
  vector<vector<char>> score(H, vector<char>(W));
  
  
  
  vector<bool> flagH(H), flagW(W);
  
  for(int i=0; i<H; i++){
    flagH.at(i)=false;
  }
  
  for(int i=0; i<W; i++){
    flagW.at(i)=false;
  }
  
  for(int i=0; i<H; i++){
    for(int j=0; j<W; j++){
      
      cin >> score.at(i).at(j);
      if(score.at(i).at(j)=='#'){
        flagH.at(i)=true;
        flagW.at(j)=true;
      }
      
    }
  }
  
  for(int i=0; i<H; i++){
    
    if(flagH.at(i)){
      
      for(int j=0; j<W; j++){
        
        if(flagW.at(j)){
          
          cout << score.at(i).at(j);
        }
        
      }
      
      cout << endl;
    }
  }
}