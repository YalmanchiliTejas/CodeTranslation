#include <bits/stdc++.h>
using namespace std;

int main() {
  int H,W;
  cin >> H >> W;
  vector<vector<char>> data(H,vector<char>(W));
  
  for(int i=0;i<H;i++){
    
    for(int j=0;j<W;j++){
      cin >> data.at(i).at(j);
      
    }
  }
  
  vector<int> ver(H,0);
  vector<int> sid(W,0);
  
  for(int i=0;i<H;i++){
    for(int j=0;j<W;j++){
      if(data.at(i).at(j) == '#'){
        break;
      }
      if(j==W-1){
        ver.at(i) = 1;
      }
    }
  }
  
  for(int i=0;i<W;i++){
    for(int j=0;j<H;j++){
      if(data.at(j).at(i) == '#')
        break;
      if(j==H-1)
        sid.at(i) = 1;
    }
  }
  
  for(int i=0;i<H;i++){
    
    if(ver.at(i))
      continue;
    
    for(int j=0;j<W;j++){
      
      if(sid.at(j))
        continue;
      else
        cout << data.at(i).at(j);
      
    }
    cout << endl;
  }
  
}
