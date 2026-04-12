#include <bits/stdc++.h>
using namespace std;

int main () {
  int H, W;
  cin >> H >> W;
  vector<vector<char>> a(H, vector<char>(W));
  int count = 0;
  for (int i = 0; i < H; i++) {
    for (int j = 0; j < W; j++) {
      cin >> a.at(i).at(j);
      if (a.at(i).at(j) == '#') count++;
    }
  }
  if (count == H+W-1) cout << "Possible" << endl;
  else cout << "Impossible" << endl;
}