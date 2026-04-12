#include <bits/stdc++.h>
using namespace std;

int main() {
  int H,W;
  cin >> H >> W;
  vector<int> row(H,0);
  vector<int> col(W,0);
  vector<string> V(H);
  for (int i = 0; i < H; i++) 
    cin >> V.at(i);
  for (int j = 0; j < H; j++) {
    for (int j2 = 0; j2 < W; j2++){
      if (V.at(j).at(j2) == '#') {
        row.at(j) = 1;
        col.at(j2) = 1;
      }
    }
  }
  for (int k = 0; k < H; k++) {
    if (row.at(k) == 1) {
      for(int k2 = 0; k2 < W; k2++) {
        if (col.at(k2) == 1)
          cout << V.at(k).at(k2);
      }
      cout << endl;
    }
  }
}
