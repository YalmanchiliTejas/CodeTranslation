#include <iostream>
#include <string>
#include <unordered_set>
 
using namespace std;
 
int main () {
  int H, W;
  cin >> H >> W;
  string data[H];

  for (int i = 0; i < H; i++) {
    string tmp;
    cin >> tmp;
    data[i] = tmp;
  }

  unordered_set<int> exclude_h;
  unordered_set<int> exclude_w;

  for (int h = 0; h < H; h++) {
    int flag = true;
    for (int w = 0; w < W; w++) {
      if (data[h][w] == '#') {
        flag = false;
        break;
      }
    }
    if (flag) {
      exclude_h.insert(h);
    }
  }

  for (int w = 0; w < W; w++) {
    int flag = true;
    for (int h = 0; h < H; h++) {
      if (data[h][w] == '#') {
        flag = false;
        break;
      }
    }
    if (flag) {
      exclude_w.insert(w);
    }
  }

  for (int h = 0; h < H; h++) {
    if (exclude_h.count(h) != 0) {
      continue;
    }
    for (int w = 0; w < W; w++) {
      if (exclude_w.count(w) != 0) {
        continue;
      }
      cout << data[h][w];
    }
    cout << endl;
  }
}
