#include <bits/stdc++.h>
using namespace std;

int main() {
  int H;
  int W;
  cin >> H;
  cin >> W;
  vector<string> a(H);
  for (int i = 0; i < H; i++) {
    cin >> a.at(i);
  }

  // 表示しない行と列をtrueとする
  vector<int> row(H, false);
  vector<int> col(W, false);
  
  for (int i = 0; i < H; i++) {
    for (int j = 0; j < W; j++) {
      if (a.at(i).at(j) == '#') {
        row.at(i) = true;
        col.at(j) = true;
      }
    }
  }
  
  for (int i = 0; i < H; i++) {
	if (row.at(i)) {
      for (int j = 0; j < W; j++) {
        if (col.at(j)) {
          cout << a.at(i).at(j);
        }
      }
      cout << endl;
    }
  }  
}
