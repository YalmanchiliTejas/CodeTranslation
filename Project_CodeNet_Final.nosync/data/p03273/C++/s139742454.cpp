#include <bits/stdc++.h>
using namespace std;

int main(){
  int H, W;
  cin >> H >> W;
  vector<vector<char>> osero (H,vector<char>(W));
  
  for(int i=0;i<H;i++){
    for(int j=0;j<W;j++){
      cin >> osero.at(i).at(j);
    }
  }
  
  int K=0;
  vector<int> t(W), y(H);
  for(int i=0;i<H;i++){
    for(int j=0;j<W;j++){
      if(osero.at(i).at(j)=='#'){
        K=1;
      }
    }
    if(K==1){
      y.at(i)=1;
    }
    K=0;
  }
  for(int j=0;j<W;j++){
    for(int i=0;i<H;i++){
      if(osero.at(i).at(j)=='#'){
        K=1;
      }
    }
    if(K==1){
      t.at(j)=1;
    }
    K=0;
  }
  for(int i=0;i<H;i++){
    for(int j=0;j<W;j++){
      if(y.at(i)==1&&t.at(j)==1){
        cout << osero.at(i).at(j);
      }
    }
    cout << endl;
  }
}