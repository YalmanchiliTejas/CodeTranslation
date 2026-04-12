#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int H, W;
  cin >> H >> W;
  vector<vector<char>>A(H,vector<char>(W));
  vector<bool>h(H,false), w(W,false);
  for (int i = 0; i < H; i++) {
    for (int j = 0; j < W; j++) {
      cin >> A.at(i).at(j);
    }
  }
  for (int i = 0; i < H; i++) {
     for (int j = 0; j < W; j++) {
       if (A.at(i).at(j) == '#') {
         h.at(i) = true;
         w.at(j) = true;
       }
     }
  }
         
  for (int i = 0; i < H; i++) {
    if (h.at(i)) {
      for (int j = 0; j < W; j++) {
        if (w.at(j)) {
          cout << A.at(i).at(j);
        }        
      }
      cout << endl;
    }
  }
  return 0;
}