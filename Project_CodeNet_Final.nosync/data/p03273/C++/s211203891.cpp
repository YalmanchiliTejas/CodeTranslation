#include <bits/stdc++.h>
using namespace std;

#define DEBUG 1

#if (DEBUG == 1)

#endif

int main()
{
  int H;
  int W;
  cin >> H >> W;

  vector<vector<char>> a(H, vector<char>(W, '.'));
  for (int i = 0; i < H; i++) {
    for (int j = 0; j < W; j++) {
      cin >> a.at(i).at(j);
    }
  }

  // row
  vector<int> checked_row;
  for (int i = 0; i < H; i++) {
    bool is_blank = true;
    for (int j = 0; j < W; j++) {
      if (a.at(i).at(j) == '#') {
	is_blank = false;
      }
    }
    if (is_blank != true) {
      checked_row.push_back(i);
    }
  }

  // col
  vector<int> checked_col;
  for (int j = 0; j < W; j++) {
    bool is_blank = true;
    for (int i = 0; i < H; i++) {
      if (a.at(i).at(j) == '#') {
	is_blank = false;
      }
    }
    if (is_blank != true) {
      checked_col.push_back(j);
    }
  }

  for (int i : checked_row) {
    for (int j : checked_col) {
      cout << a.at(i).at(j);
    }
    cout << endl;
  }

  return 0;
}
