#include <bits/stdc++.h>
using namespace std;

int main(){
  int H,W;
  cin >> H >> W;
  
  int h = H;
  int w = W;
  
  vector<vector<char>> data(H, vector<char>(W));  

  for(int i=0; i<H;i++){
    for(int j=0;j<W;j++){
      char tmp;
      cin >> tmp;
      data.at(i).at(j) = tmp;
    }
  }

  
  vector<bool> row(h,false);
  vector<bool> col(w, false);
  for(int i=0; i<H;i++){
    for(int j=0;j<W;j++){
      if (data.at(i).at(j) == '#') {
        row.at(i) = true;
        col.at(j) = true;
      }
    }
  }
  
  for(int i=0; i<H;i++){
    if (row.at(i) == false) continue;
    for(int j=0;j<W;j++){
      if (col.at(j) == false) continue;
      
      cout << data.at(i).at(j);
    }
    cout << endl;
  }
  return 0;
}