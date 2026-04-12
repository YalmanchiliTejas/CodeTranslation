#include <bits/stdc++.h>
using namespace std;

int main() {
  int H, W;
  cin >> H >> W;
  vector<vector<char>> A(H,vector<char>(W));
  for(int i=0; i<H; i++) {
    for(int j=0; j<W; j++) {
      cin >> A.at(i).at(j);
//      cout << A.at(i).at(j);
//      if(j==W-1) cout << endl;
    }
  }
  
  vector<int> GYOU(H);
  
  for(int i=0; i<H; i++) {
    for(int j=0; j<W; j++) {
      if(A.at(i).at(j)=='#') {
        GYOU.at(i)++;
      }
      if(j==W-1 && GYOU.at(i)==0) {
        for(int j=0; j<W; j++) {
          A.at(i).at(j)=' ';
        }
      }
    }
  }

  vector<int> RETSU(W);
  
  for(int j=0; j<W; j++) {
    for(int i=0; i<H; i++) {
      if(A.at(i).at(j)=='#') {
        RETSU.at(j)++;
      }
      if(i==H-1 && RETSU.at(j)==0) {
        for(int i=0; i<H; i++) {
          A.at(i).at(j)=' ';
        }
      }
    }
  }

  for(int i=0; i<H; i++) {
    for(int j=0; j<W; j++) {
      if(A.at(i).at(j)!=' ') {
        cout << A.at(i).at(j);
      }
      if(j==W-1 && GYOU.at(i)!=0) cout << endl;
    }
  }
  
}