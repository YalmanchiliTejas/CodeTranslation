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

  // 空白行を探す
  for (auto i = a.begin(); i != a.end();) {
    vector<char> row = *i;
    bool empty = true;
    for (char r : row) {
      if (r == '#') {
        empty = false;
      }
    }
    if (empty) {
      i = a.erase(i);
    } else {
      i++;
    }
  }

  // 空白列を探す
  for (int j = 0; j < a.at(0).size();) {
    bool empty = true;
	for (int i = 0; i < a.size(); i++) {
      if (a.at(i).at(j) == '#') {
        empty = false;
      }
    } 

    if (empty) {
      for (auto i = a.begin(); i != a.end(); i++) {
        (*i).erase((*i).begin() + j);
      }
    } else {
      j++;
    }
  }

  // 出力する
  for (auto row : a) {
    for (auto col : row) {
      cout << col;
    }
    cout << endl;
  }

}
