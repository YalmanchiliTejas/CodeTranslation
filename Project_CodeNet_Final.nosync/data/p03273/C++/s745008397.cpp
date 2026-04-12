#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int H, W;
  cin >> H >> W;
  vector<string> table(H);
  for (int i = 0; i < H; i++) cin >> table.at(i);

  vector<string> result(H);
  for (int j = 0; j < W; j++) {
    bool flag = false;
    for (int i = 0; i < H; i++) {
      if (table.at(i).at(j) == '#') {
        flag = true;
        break;
      }
    }
    if (flag) {
      for (int i = 0; i < H; i++) {
        result.at(i) += table.at(i).at(j);
      }
    }
  }

  for (int i = 0; i < H; i++) {
    if (result.at(i).find('#') != string::npos) {
      cout << result.at(i) << endl;
    }
  }
}