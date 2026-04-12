#include <algorithm>
#include <cmath>
#include <cstdio>
#include <deque>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>

using namespace std;

typedef long long ll;

#define MOD 1000000007

int main() {
  int h, w;
  cin >> h >> w;
  char a[h][w];
  for (int i = 0; i < h; ++i) {
    for (int j = 0; j < w; ++j) {
      cin >> a[i][j];
    }
  }
  vector<bool> row(h, false);
  vector<bool> col(w, false);
  for (int i = 0; i < h; ++i) {
    for (int j = 0; j < w; ++j) {
      if (a[i][j] == '#') {
        row[i] = col[j] = true;
      }
    }
  }
  for (int i = 0; i < h; ++i) {
    if (row[i]) {
      for (int j = 0; j < w; ++j) {
        if (col[j]) {
          cout << a[i][j];
        }
      }
      cout << "\n";
    }
  }
  return 0;
}