#include <bits/stdc++.h>
using namespace std;

int main() {
  int H, W;
  cin >> H >> W;
  vector<vector<char>> a(H, vector<char>(W));
  vector<int> h, w;
  for (int i = 0; i < H; i++)
    for (int j = 0; j < W; j++)
      cin >> a.at(i).at(j);
  // ここまでOK
  for (int i = 0; i < H; i++) {
    bool allwhite = true;
    for (int j = 0; j < W; j++)
      if (a.at(i).at(j) == '#') {
        allwhite = false;
        break;
      }
    if (allwhite == false)
      h.push_back(i);
  }
  for (int i = 0; i < W; i++) {
    bool allwhite = true;
    for (int j = 0; j < H; j++)
      if (a.at(j).at(i) == '#') {
        allwhite = false;
        break;
      }
    if (allwhite == false)
      w.push_back(i);
  }
  // ここからOK
  for (int i = 0; i < h.size(); i++){
    for (int j = 0; j < w.size(); j++)
      cout << a.at(h.at(i)).at(w.at(j));
    cout << endl;
  }
  return 0;
}