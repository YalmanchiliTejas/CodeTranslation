#include <bits/stdc++.h>
using namespace std;

int main() {
  int H, W;
  cin >> H >> W;
  
  vector<vector<char>> A(H, vector<char>(W));
  
  for (int i = 0; i < H; i++) {
    for (int j = 0; j < W; j++) {
      cin >> A.at(i).at(j);
    }
  }
  
  vector<bool> h(H);
  vector<bool> w(W);
  
  for (int i = 0; i < H; i++) {
    for (int j = 0; j < W; j++) {
      if(A.at(i).at(j) == '#') {
        h.at(i) = true;
        w.at(j) = true;
      }
    }
  }
  
  for (int i = 0; i < H; i++) {
    if(h.at(i) == true) {
      for (int j = 0; j < W; j++) {
        if(w.at(j) == true) {
          cout << A.at(i).at(j);
        }
      }
      cout << endl;
    }
  }
}