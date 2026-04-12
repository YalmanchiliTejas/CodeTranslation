#include <bits/stdc++.h>
using namespace std;


int main(){
  int H, W;
  cin >> H >> W;
  vector<vector<char>> A(H, vector<char>(W));
  for(int ii=0; ii<H; ii++){
    for(int jj=0; jj<W; jj++){
      cin >> A[ii][jj];
    }
  }
  
  vector<bool> output_row(H, false);
  vector<bool> output_col(W, false);
  for(int ii=0; ii<H; ii++){
    for(int jj=0; jj<W; jj++){
      if(A[ii][jj] == '#'){
        output_row[ii] = true;
        output_col[jj] = true;
      }
    }
  }
  for(int ii=0; ii<H; ii++){
    if(output_row[ii]==false) continue;
    for(int jj=0; jj<W; jj++){
      if(output_col[jj]==false) continue;
      cout << A[ii][jj];
    }
    cout << endl;
  }
  return 0;
}