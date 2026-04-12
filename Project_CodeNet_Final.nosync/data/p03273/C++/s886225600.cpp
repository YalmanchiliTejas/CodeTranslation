#include <bits/stdc++.h>
using namespace std;

int main() {
  int H, W;
  cin >> H >> W;

  vector<vector<char>> a(H, vector<char>(W));

  for (int i = 0; i < H; i++) {
    for (int j = 0; j < W; j++) {
      cin >> a.at(i).at(j);
    }
  }

  vector<int> goodH(110);
  vector<int> goodW(110);
  for (int i = 0; i < H; i++) {
    for (int j = 0; j < W; j++) {
      if (a.at(i).at(j) == '#') {
        goodH.at(i) = true;
        goodW.at(j) = true;
      }
    }
  }

  for (int i = 0; i < H; i++) {
    if (goodH.at(i)) {
      for (int j = 0; j < W; j++) {
        if (goodW.at(j)) {
          cout << a.at(i).at(j);
        }
      }
       cout << endl;
    }
  }
  
}