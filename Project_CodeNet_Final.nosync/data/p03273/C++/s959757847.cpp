#include <bits/stdc++.h>
using namespace std;

int main() {
  int H,W;
  cin >> H >> W;
  
  vector<vector<char>> masu(H,vector<char>(W));
  
  for (int i=0; i<H; i++) {
    for (int j=0; j<W; j++) {
      cin >> masu.at(i).at(j);
    }
  }
  
  vector<vector<int>> A(H,vector<int>(W));
  
  for (int i=0; i<H; i++) {
    int I=0, count=0;
    
    while (I<W && masu.at(i).at(I) == '.') {
      count ++;
      I ++;
    }
    
    if (count == W) {
      for (int j=0; j<W; j++) {
        A.at(i).at(j) = 1;
      }
    }
  }
  
  for (int i=0; i<W; i++) {
    int I=0, count=0;
    
    while (I<H && masu.at(I).at(i) == '.') {
      count ++;
      I ++;
    }
    
    if (count == H) {
      for (int j=0; j<H; j++) {
        A.at(j).at(i) = 1;
      }
    }
  }
  
  for (int i=0; i<H; i++) {
    int C=0;
    
    for (int j=0; j<W; j++) {
      if (A.at(i).at(j) == 1) {
        C ++;
      }
    }
    
    if (C == W) {
      continue;
    }
    
    for (int j=0; j<W; j++) {
      if (A.at(i).at(j) == 0) {
        cout << masu.at(i).at(j);
      }
    }
    
    cout << endl;
  }
}