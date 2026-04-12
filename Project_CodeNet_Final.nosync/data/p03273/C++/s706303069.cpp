#include <bits/stdc++.h>
using namespace std;

int main() {
  int H, W;
  cin >> H >> W;

  vector<vector<char>> data(H, vector<char>(W));
  vector<bool> h(H, false);
  vector<bool> w(W, false);
  
  for (int i = 0; i < H; i++) {
    for (int j = 0; j < W; j++) {
      cin >> data.at(i).at(j);
      
      if (data.at(i).at(j) == '#') {
        h.at(i) = true;
        w.at(j) = true;
      }
    }
  }
  
  for (int i = 0; i < H; i++) {
    for (int j = 0; j < W; j++) {
      if (h.at(i) && w.at(j)) {
        cout << data.at(i).at(j);
      }
    }
    if (h.at(i))  cout << endl;
  }
}