#include <bits/stdc++.h>
using namespace std;

int mysum(vector<int> a){
  int result=0;
  for(auto x: a) result += x;
  return result;
}

int main() {
  int H, W;
  cin >> H >> W;
  vector<vector<char>> a(H, vector<char> (W, '.'));
  for (int i=0; i<H; i++){
    for (int j=0; j<W; j++){
      cin >> a[i][j];
    }
  }
  vector<int> rowGood(H, 0), colGood(W, 0);
  for (int i=0; i<H; i++){
    int isGood = 0;
    for (int j=0; j<W; j++){
      if (a[i][j] != '.') isGood = 1;
    }
    rowGood[i] = isGood;
  }
  for (int j=0; j<W; j++){
    int isGood = 0;
    for (int i=0; i<H; i++){
      if (a[i][j] != '.') isGood = 1;
    }
    colGood[j] = isGood;
  }
  vector<vector<char>> b(mysum(rowGood), vector<char> (mysum(colGood), '.'));

  for (int i=0, ib = 0; i<H; i++){
    if (rowGood[i]) {
      for (int j=0, jb=0; j<W; j++){
        if(colGood[j]) {
          b[ib][jb] = a[i][j];
          jb ++;
        }
      }
      ib++;
    }
  }

  for (int i=0; i< b.size(); i++){
    for (int j=0; j< b[i].size(); j++){
      cout << b[i][j];
      if (j == b[i].size() - 1) cout << endl;
    }
  }
}
