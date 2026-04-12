#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int H, W;
  cin >> H >> W;

  int count = 0;
  vector<string> a(H);
  string sa;
  string e = string(W, '.');

  for (int i = 0; i < H; i++) {
    cin >> sa;

    if (sa == e) count++;
    else a.at(i - count) = sa;
  }
  H -= count;

  vector<int> count_list(W, 0);
  int l_counter = 0;
  for (int i = 0; i < W; i++) {
    l_counter = 0;
    for (int j = 0; j < H; j++) {
      if (a.at(j).at(i) == '.') {
        l_counter++;
      }
      if (l_counter == H) count_list.at(i) = 1;
    }
  }

  for (int i = 0; i < H; i++) {
    count = 0;
    for (int j = 0; j < W; j++) {
      if (count_list.at(j) != 0) {
        a.at(i).erase(j - count, 1);
        count++;
      }
    }
  }

  for (int i = 0; i < H; i++) {
    cout << a.at(i) << endl;
  }
}