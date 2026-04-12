#include <bits/stdc++.h>
using namespace std;

int main() {
  
  int H, W; cin >> H >> W; int count = 0;
  
  char table[H][W];
  
  for (int i = 0; i < H; i++) {
    for (int j = 0; j < W; j++) {
      char A; cin >> A;
      if (A == '#') count++;
    }
  }
  
  if (count == H + W - 1) cout << "Possible" << endl;
  
  else cout << "Impossible" << endl;
  
}