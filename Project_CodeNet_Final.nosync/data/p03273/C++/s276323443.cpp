#include <bits/stdc++.h>
using namespace std;
int main() {
  int H;
  cin >> H;
  int W;
  cin >> W;
  vector<string> A(H);
  for (int i = 0; i < H; i++) {
    cin >> A.at(i);
  }
  vector<bool> gyo(H, false);
  vector<bool> retsu(W, false);
  for (int i = 0; i < H; i++) {
    for (int j = 0; j < W; j++) {
      if (A.at(i).at(j) == '#') {
        gyo.at(i) = true;
        retsu.at(j) = true;
      }
    }
  }
  for (int i = 0; i < H; i++) {
    if (gyo.at(i)) {
      for (int j = 0; j < W; j++) {
        if (retsu.at(j)) {
          cout << A.at(i).at(j);
        }
      }
      cout << endl;
    }
  }
}
        
  
                 
