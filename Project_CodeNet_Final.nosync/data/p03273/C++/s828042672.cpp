#include <bits/stdc++.h>
using namespace std;

int main() {
  int H, W;
  cin >> H >> W;
  vector<vector<char>> A(H+1, vector<char>(W+1));
  for(int i=0; i<H; i++){
    for(int j=0; j<W; j++){
      cin >> A.at(i).at(j);
      if(A.at(i).at(j)=='#'){
        A.at(i).at(W)='#';
        A.at(H).at(j)='#';
      }
    }
  }
  
  for(int i=0; i<H; i++){
    if(A.at(i).at(W)!='#'){
      continue;
    }
    for(int j=0; j<W; j++){
      if(A.at(H).at(j)!='#'){
        continue;
      }
      cout << A.at(i).at(j);
    }
    cout << endl;
  }
}
