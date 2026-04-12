#include <bits/stdc++.h>
using namespace std;

int main() {
  int H , W;
  cin >> H >> W;
  vector<string> M(H);
  for (int i = 0; i < H; i++) {
    cin >> M.at(i);
  }
  
  vector<bool> G(H,false) , R(W,false);
  for (int i = 0; i < H; i++) {
    for (int j = 0; j < W; j++) {
      if (M.at(i).at(j) == '#') {
        G.at(i) = true;
        R.at(j) = true;
      }
    }
  }
  
  for (int i = 0; i < H; i++) {
    if (G.at(i)) {
      for (int j = 0; j < W; j++) {
        if (R.at(j)) {
          cout << M.at(i).at(j);
        }
      }
      cout << endl;
    }
  }
}
