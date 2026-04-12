#include <bits/stdc++.h>
using namespace std;

int main() {
  int H, W;
  cin >> H >> W;
  vector<vector<char>> C(H, vector<char>(W, '.'));
  vector<int> A(H, 0);
  vector<int> B(W, 0);

  for (int i = 0; i < H; i++) {
    for (int j = 0; j < W; j++) {
      cin >> C.at(i).at(j);
      if (C.at(i).at(j) == '#') {
        A.at(i) = 1;
        B.at(j) = 1;
      }
    }
  }
  
  for (int i = 0; i < H; i++) {
    for (int j = 0; j < W; j++) {
  		if (A.at(i) == 1 and B.at(j) == 1) {
        	cout << C.at(i).at(j);
        }
    }
    if (A.at(i) == 1) cout << endl;
  }  
}
