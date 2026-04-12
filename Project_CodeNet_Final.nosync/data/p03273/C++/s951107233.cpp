#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int H,W;
  cin >> H >> W;
  vector<vector<char>> chart(H,vector<char>(W));
  for(int i=0;i<H;i++){
    for(int j=0;j<W;j++){
      cin >> chart[i][j];
    }
  }
  for(int i=H-1;i >= 0;i--){
    bool triger = false;
    for(int j = 0;j<W;j++){
      if(chart[i][j]=='#'){
        triger = true;
        break;
      }
    }
    if(triger==false){
      chart.erase(chart.begin()+i);
    }  
  }
  for(int i=W-1;i >= 0;i--){
    bool triger = false;
    for(int j = 0;j<chart.size();j++){
      if(chart[j][i]=='#'){
        triger = true;
        break;
      }
    }
    if(triger==false){
      for(int k=0;k<chart.size();k++){           
        chart[k].erase(chart[k].begin()+i);
      }
    }   
  }
  for(int i=0;i<chart.size();i++){
  	for(int j=0;j<chart[0].size();j++){
    	cout << chart[i][j];
    }
    cout << endl;
  }
}