#include<bits/stdc++.h>
using namespace std;

int main(){
  int H,W;
  cin >> H >> W;
  
  int i,j = 0;
  
  vector<vector<char>> table(H,vector<char>(W));
  for(i=0;i<H;i++){
    for(j=0;j<W;j++){
      cin >> table.at(i).at(j);
    }
  }
  
  vector<bool> flagH(H,false);
  vector<bool> flagW(W,false);
  for(i=0;i<H;i++){
    for(j=0;j<W;j++){
      if(table.at(i).at(j)=='#'){
        flagH.at(i)=true;
        flagW.at(j)=true;
      }
    }
  }
  
    for(i=0;i<H;i++){
      if(flagH.at(i)){
        for(j=0;j<W;j++){
          if(flagW.at(j))
            cout << table.at(i).at(j);
        }
      }
      cout << endl;
    } 
   
}