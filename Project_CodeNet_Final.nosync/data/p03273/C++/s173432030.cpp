#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int H,W;
  cin >> H >> W;
  vector<vector<char>> vec(H,vector<char>(W));
  for (int i=0; i<H; ++i) {
    for (int j=0; j<W; ++j) {
      cin >> vec.at(i).at(j);
    }
  }
  while (1) {
    int b=0;
    int c=0;
    for (int i=0; i<H; ++i) {
      int a=1;
      for (int j=0; j<W; ++j) {
        if (vec.at(i).at(j) != '.') {
          a=0;
        }
      }
      if (a==1) {
        b=1;
        c=i;
        break;
      }
    }
    if (b==1) {
      for (int i=c; i<H-1; ++i) {
        for (int j=0; j<W; ++j) {
          vec.at(i).at(j) = vec.at(i+1).at(j);
        }
      }
      H -= 1;
    }
    int d=0;
    int e=0;
    for (int i=0; i<W; ++i) {
      int a=1;
      for (int j=0; j<H; ++j) {
        if (vec.at(j).at(i) != '.') {
          a=0;
        }
      }
      if (a==1) {
        d=1;
        e=i;
        break;
      }
    }
    if (d==1) {
      for (int i=e; i<W-1; ++i) {
        for (int j=0; j<H; ++j) {
          vec.at(j).at(i) = vec.at(j).at(i+1);
        }
      }
      W -= 1;
    }
    if (b == 0 && d == 0) {
      break;
    }
  }
  for (int i=0; i<H; ++i) {
    for (int j=0; j<W; ++j) {
      cout << vec.at(i).at(j);
    }
    cout << endl;
  }
}
        
        
        
        
        
        
        
