#include <bits/stdc++.h>
using namespace std;

int main() {
  int H, W;
  cin >> H >> W;
  vector<string> a(H);
  for (int i = 0; i < H; i++) {
    cin >> a.at(i);
  }
  string str;
  for (int j = 0; j < W; j++) {
    str += ".";
  }
  int count = 0;
  for (int i = 0; i < a.size(); i++) {
    if (a.at(i) == str) {
      a.erase(a.begin() + i);
      i--;
      count++;
    }
  }
  int f = 1;
  for (int j = 0; j < a.at(0).size(); j++) {
    f = 1;
    for (int i = 0; i < H - count; i++) {
      if (a.at(i).at(j) == '#') {
        f = 0;
      }
    }
    if (f == 1) {
      for (int i = 0; i < H - count; i++) {
        a.at(i).erase(a.at(i).begin() + j);
      }
      j--;
    }
  }
  for (int i = 0; i < H - count; i++) {
    cout << a.at(i) << endl;
  }
}