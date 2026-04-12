#include <bits/stdc++.h>
using namespace std;

int main() {
  int H, W;
  cin >> H >> W;
  vector<vector<char>> matrix(H, vector<char>(W));
  for (int i=0; i<H; i++) {
    for (int j=0; j<W; j++) {
      cin >> matrix.at(i).at(j);
    }
  }
  
  for (int j=0; j<W; j++) {
    for (int i=0; i<H; i++) {
      if (matrix.at(i).at(j) == '#') {
        break;
      }
      if (i==H-1) {
        if (j==W-1) {
          for (int k=0; k<H; k++) {
            matrix.at(k).at(j)='o';
          }
        }
        else {
          for (int k=0; k<H; k++) {
            matrix.at(k).at(j)='x';
          }
        }
      }
    }
  }
  
  for (int i=0; i<H; i++) {
    for (int j=0; j<W; j++) {
      if (matrix.at(i).at(j) == '#') {
        break;
      }
      if (j==W-1) {
        for (int k=0; k<W; k++) {
          matrix.at(i).at(k)='x';
        }
      }
    }
  }

  for (int i=0; i<H; i++) {
    for (int j=0; j<W; j++) {
      if (matrix.at(i).at(j) != 'x' && matrix.at(i).at(j) != 'o') {
        cout << matrix.at(i).at(j);
        if (j==W-1) {
          cout << endl;
        }
      }
      if (matrix.at(i).at(j) == 'o') {
        cout << endl;
      }
    }
  }
}
