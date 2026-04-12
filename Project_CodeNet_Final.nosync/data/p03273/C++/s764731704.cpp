#include <bits/stdc++.h>
using namespace std;

int main() {
  int W, H;
  int flg;
  cin >> H >> W;
   vector<vector<char>> A(H,vector<char>(W));
  vector<int> I(H,1);
  vector<int> J(W,1);
  
  for (int i = 0; i < H; i++) {
	for (int j = 0; j < W; j++) {
	  cin >> A.at(i).at(j);
    }
  }

  for (int j = 0; j < W; j++) {
	for (int i = 0; i < H; i++) {
      if (A.at(i).at(j) == '#') {
        J.at(j) = 0;
        break;
      }
    }
  }

  for (int i = 0; i < H; i++) {
    for (int j = 0; j < W; j++) {
      if (A.at(i).at(j) == '#') {
        I.at(i) = 0;
        break;
      }
    }
  }

  for (int i = 0; i < H; i++) {
    flg = 0;
	for (int j = 0; j < W; j++) {
 		if(I.at(i) == 0) {
          if(J.at(j) == 0) {
            cout << A.at(i).at(j);
            flg = 1;
          }
        }
        if (j == (W - 1)) {
          if (flg == 1) {
            cout << endl;
          }
        }
    }
  }
}