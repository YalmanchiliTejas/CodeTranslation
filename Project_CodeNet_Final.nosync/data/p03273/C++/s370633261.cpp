#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int H, W;
  cin >> H >> W;
  vector<vector<char>> list (H, vector<char>(W));

  bool dele;

  for(int i = 0; i<H; i++){
    dele = true;
    for(int j = 0; j<W; j++){
      cin >> list.at(i).at(j);
      if(list.at(i).at(j)=='#') dele = false;
    }
    if(dele==true){
      i--;
      H--;
    }
  }

  vector<bool> flug(W);

  for(int j = 0; j<W; j++){
    dele = true;
    for(int i = 0; i<H; i++){
      if(list.at(i).at(j)=='#') {
        dele = false;
        break;
      }
    }
    flug.at(j) = dele;
  }

  for(int i = 0; i<H; i++){
    for(int j = 0; j<W; j++){
      if(flug.at(j)==false) {
        cout << list.at(i).at(j);
      }
    }
    cout << endl;
  }
}