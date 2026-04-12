#include<bits/stdc++.h>
using namespace std;

int main(){
  int H,W;
  cin >> H >> W;
  
  vector<vector<char>> table(H,vector<char>(W));
  for(int i=0;i<H;i++){
    for(int j=0;j<W;j++){
      cin >> table.at(i).at(j);
    }
  }
  
  vector<bool> flagH(H,false);
  vector<bool> flagW(W,false);
  for(int i=0;i<H;i++){
    for(int j=0;j<W;j++){
      if(table.at(i).at(j)=='#'){
        flagH.at(i)=true;
        flagW.at(j)=true;
      }
    }
  }
  
    for(int i=0;i<H;i++){
      if(flagH.at(i)){
        for(int j=0;j<W;j++){
          if(flagW.at(j))
            cout << table.at(i).at(j);
          if(j==W-1)
            cout << endl;
        }
      }
      
    } 
   
}