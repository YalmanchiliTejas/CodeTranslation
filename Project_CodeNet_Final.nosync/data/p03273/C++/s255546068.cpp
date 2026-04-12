#include <bits/stdc++.h>
using namespace std;

int main(){
  int H,W;
  cin >> H >> W;
  vector<bool> tate(H),yoko(W);
  vector<vector<char>> A(H,vector<char>(W));
  for(int i=0;i<H;i++){
    for(int j=0;j<W;j++){
      cin >> A.at(i).at(j);
      if(A.at(i).at(j)=='#'){
        tate.at(i)=true;
        yoko.at(j)=true;
      }
    }
  }
  for(int i=0;i<H;i++){
    for(int j=0;j<W;j++){
      if(tate.at(i) && yoko.at(j)){
        cout << A.at(i).at(j);
      }
      if(j==W-1 && tate.at(i)){
        cout << endl;
      }
    }
  }
} 