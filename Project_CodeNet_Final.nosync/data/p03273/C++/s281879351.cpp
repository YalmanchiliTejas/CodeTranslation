#include <algorithm>
#include <cmath>
#include <deque>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <tuple>
#include <vector>
using namespace std;
typedef long long ll;
ll const INF = 1LL << 60;

int main() {
  ll H, W;
  cin >> H >> W;
  vector<string> MAP(H);
  for (int i = 0; i < H; i++) {
    cin >> MAP[i];
  }
  vector<bool> deletable_row(H, true);
  vector<bool> deletable_col(W, true);
  for (int i = 0; i < H; i++) {
    for (int j = 0; j < W; j++) {
      if (MAP[i][j] == '#') {
        deletable_row[i] = false;
        deletable_col[j] = false;
      }
    }
  }
  for (int i = 0; i < H; i++) {
    if (deletable_row[i]) continue;
    for (int j = 0; j < W; j++) {
      if (deletable_col[j]) continue;
      cout << MAP[i][j];
    }
    cout << endl;
  }
  return 0;
}