#include <bits/stdc++.h>
using namespace std;

int main() {
  int H,W;
  cin >> H >> W;
  
  vector<string> temp(H);
  vector<vector<char>> data(H, vector<char>(W));
  vector<int> flag_h(H,0);
  vector<int> flag_w(W,0);
  
  for(int i=0;i<H;i++){
    cin >> temp.at(i);
    for(int j=0;j<W;j++){
      data.at(i).at(j) = temp.at(i).at(j);
      if(temp.at(i).at(j)=='#'){
        flag_h.at(i) = 1;
      }
    }
  }
  for(int i=0;i<W;i++){
    for(int j=0;j<H;j++){
      if(temp.at(j).at(i)=='#'){
        flag_w.at(i) = 1;
      }
    }
  }
  for(int i=0;i<H;i++){
    for(int j=0;j<W;j++){
      if(flag_h.at(i)==1 && flag_w.at(j)==1){
        cout << data.at(i).at(j) ;
      }
    }
    if(flag_h.at(i)==1){
      cout <<  endl;
    }
  }   


}