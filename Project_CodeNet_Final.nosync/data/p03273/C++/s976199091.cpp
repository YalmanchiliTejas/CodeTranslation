#include <bits/stdc++.h>
using namespace std;

int main() {
  int H, W;
  cin >> H >> W;
  vector<vector<char>> mp(H, vector<char>(W));
  for (int i = 0; i < H; i++) {
	  for (int j = 0; j < W; j++) {
		cin >> mp.at(i).at(j);
      }
  }
  
  vector<vector<char>> rt(H);
  for (int i = 0; i < W; i++) {
    bool f = false;
    for (int j = 0; j < H; j++) {
      if (mp.at(j).at(i) != '.') {
        f = true;
        break;
      }
    }
    if (f) {
      for (int j = 0; j < H; j++) {
        rt.at(j).push_back(mp.at(j).at(i));
      }
    }
  }
  for (int i = 0; i < H; i++) {
    bool f = false;
    for (char c:rt.at(i)) {
      if (c != '.') {
        f = true;
        break;
      }
    }
    if (f) {
	  for (char c:rt.at(i)) {
        cout << c;
      }
      cout << endl;
    }
  }
}
