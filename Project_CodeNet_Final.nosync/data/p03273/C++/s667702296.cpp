#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int H, W;
  int i, j;
  cin >> H >> W;
  vector<int> h(H, 0);
  vector<int> w(W, 0);
  vector<vector<char>> a(H, vector<char>(W));
  for (i = 0; i < H; i++) {
    for (j = 0; j < W; j++) {
      cin >> a.at(i).at(j);
    }
  }

  for (i = 0; i < H; i++) {
    for (j = 0; j < W-1; j++) {
      if(a.at(i).at(j)!=a.at(i).at(j+1)) break;
      if(j == W-2 && a.at(i).at(j) == '.') h.at(i) = 1;
    }
  }
  for (j = 0; j < W; j++) {
    for (i = 0; i < H-1; i++) {
      if(a.at(i).at(j)!=a.at(i+1).at(j)) break;
      if(i == H-2 && a.at(i).at(j) == '.') w.at(j) = 1;
    }
  }

  for (i = 0; i < H; i++) {
    for (j = 0; j < W; j++) {
      if(h.at(i)==0 && w.at(j) == 0) cout << a.at(i).at(j);
    }
    if(h.at(i)==0) cout << endl;
  }
}