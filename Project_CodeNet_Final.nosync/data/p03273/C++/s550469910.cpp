#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int H,W;
  cin>>H>>W;
  int ja=0;
  int ja2=0;
  vector<vector<char>> data(H,vector<char>(W));
  for(int i=0;i<H;i++){
    for(int j=0;j<W;j++){
      cin>>data.at(i).at(j);
    }
  }
  vector<int> row(H, 0);
  vector<int> col(W, 0);
  
  for (int i = 0; i < H; i++) {
    for (int j = 0; j < W; j++) {
      if (data.at(i).at(j)=='#') {
        row.at(i) = 1;
        col.at(j) = 1;
      }
    }
  }
  
  for (int i = 0; i < H; i++) {
	  if (row.at(i)==1) {
      for (int j = 0; j < W; j++) {
        if (col.at(j)==1) {
          cout << data.at(i).at(j);
        }
      }
      cout << endl;
    }
  }  
}
