#include <bits/stdc++.h>
using namespace std;

int main(){
  int H, W;
  cin >> H >> W;
  vector<vector<char>> A(H, vector<char>(W));
  for (int i=0; i<H; i++) {
    for (int j=0; j<W; j++) {
      cin >> A.at(i).at(j);
    }
  }
  bool flag;
  for (int i=0; i<H; i++) {
    flag = false;
    for (int j=0; j<W; j++) {
      if (A.at(i).at(j) == '#')
        flag = true;
    }
    if (!flag) {
      for (int x=i; x<H-1; x++) {
        for (int y=0; y<W; y++) {
          A.at(x).at(y) = A.at(x+1).at(y);
        }
      }
      H--;
      i--;
    }
  }
  for (int i=0; i<W; i++) {
    flag = false;
    for (int j=0; j<H; j++) {
      if (A.at(j).at(i) == '#')
        flag = true;
    }
    if (!flag) {
      for (int x=0; x<H; x++) {
        for (int y=i; y<W-1; y++) {
          A.at(x).at(y) = A.at(x).at(y+1);
        }
      }
      W--;
      i--;
    }
  }
  for (int i=0; i<H; i++) {
    for (int j=0; j<W; j++) {
      cout << A.at(i).at(j);
      if (j == W-1)
        cout << endl;
    }
  }
}