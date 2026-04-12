#include <bits/stdc++.h>
using namespace std;

int main() {

  int line;
  int row;
  cin >> line;
  cin >> row;
  
  vector<vector<char>> masu(line + 1, vector<char>(row + 1));

  for (int i = 0; i < line; i++) {
    for (int j = 0; j < row; j++) {
      cin >> masu.at(i).at(j) ;
    }
  }
  
  // for (int i = 0; i < line; i++) {
  //  for (int j = 0; j < row; j++) {
  //    cout << masu.at(i).at(j);
  //  }
  //  cout <<endl;
  // }
  // cout << "----" << endl;
  int line_flg;
  int flg;

  int line_out_flg;
  for (int i = 0; i < line; i++) {			// i --> line
    line_out_flg = 0;
    if (masu.at(i).at(0) != '#') {
      for (int j = 1; j < row; j++) {
        if (masu.at(i).at(j) == '#') {
            line_out_flg = 1;
            // cout << "line = " << i << ", row = " << j << "find #" << endl;
            break;
        }
      }
    } else {
      line_out_flg = 1;
    }
    if (line_out_flg == 0) {
      // cout << i << " skip " << endl;
      continue;
    }
    line_flg = 0;
    for (int j = 0; j < row; j++) {			// j --> row
        flg = 0;
        if (masu.at(i).at(j) != '#') {
          for (int k = 0; k < line; k++) {
            if (k != i) {
               if (masu.at(k).at(j) == '#') {
                 flg = 1;
                 break;
               }
            }
          }
        } else {
          flg = 1;
        }
        // cout << "line = " << i << ", row = " << j << ", flg = " << flg << endl;    
        if (flg == 1) {
          cout << masu.at(i).at(j);
          line_flg = 1;
        }
    }
    if (line_flg == 1) {
      cout << endl;
    }
  }
}