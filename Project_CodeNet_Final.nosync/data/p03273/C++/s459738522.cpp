#include <bits/stdc++.h>
using namespace std;

int main() {
  int H, W;
  cin >> H >> W;
  vector<vector<char>> tab(H, vector<char>(W));
  vector<int> row(H, 0);
  vector<int> col(W, 0);
  
  for(int i=0;i<H;i++){
    for(int j=0;j<W;j++){
      cin >> tab.at(i).at(j);
      if(tab.at(i).at(j) == '#'){
        row.at(i) = 1;
        col.at(j) = 1;
      }
    }
  }

  for(int i=0;i<H;i++){
    for(int j=0;j<W;j++){
      if(row.at(i)==1 && col.at(j)==1) cout << tab.at(i).at(j);
    }
    if(row.at(i)==1) cout << endl;
  }
  return 0;
}