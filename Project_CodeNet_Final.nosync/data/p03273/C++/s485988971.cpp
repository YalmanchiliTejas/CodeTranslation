#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int H,W;
  cin >> H >> W ;
  vector<vector<char>> a(H,vector<char>(W));
  for(int i=0;i<H;i++){
    for(int j=0;j<W;j++){
      cin >> a.at(i).at(j);
    }
  }
  vector<int> x(0),y(0);
  for(int i=0;i<H;i++){
    for(int j=0;j<W;j++){
      if(a.at(i).at(j)=='#'){
        x.push_back(i);
        break;
      }
    }
  }
  for(int j=0;j<W;j++){
    for(int i=0;i<H;i++){
       if(a.at(i).at(j)=='#'){
        y.push_back(j);
        break;
      }
    }
  }
  for(int i : x){
    for(int j : y){
      cout << a.at(i).at(j);
    }
    cout <<endl;
  }
  
      
  
}