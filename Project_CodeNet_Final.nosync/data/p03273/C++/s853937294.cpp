#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "../lib/dump.hpp"
#else
#define dump(...)
#define dumpv(...)
#endif

typedef long long ll;
typedef pair<int, int> P;
const int MOD = 1e9 + 7;
const int INF = 1001001001;
const ll LINF = 1001002003004005006ll;

int main()
{
  cin.tie(0);
  ios::sync_with_stdio(false);
  // freopen("temp.1", "r", stdin);

  int H, W;
  cin >> H >> W;
  vector<vector<char>> a(H, vector<char>(W));
  for (int i = 0; i < H; i++) {
    for (int j = 0; j < W; j++) {
      cin >> a[i][j];
    }
  }
  vector<int> removeh(H);
  vector<int> removew(W);
  for (int j = 0; j < W; j++) {
    int black = false;
    for (int i = 0; i < H; i++) {
      if (a[i][j] == '#') {
        black = true;
        break;
      }
    }
    if (black == false) {
      removew[j] = 1;
    }
  }
  for (int i = 0; i < H; i++) {
    int black = false;
    for (int j = 0; j < W; j++) {
      if (a[i][j] == '#') {
        black = true;
        break;
      }
    }
    if (black == false) {
      removeh[i] = 1;
    }
  }
  for (int i = 0; i < H; i++) {
    if (removeh[i])
      continue;
    for (int j = 0; j < W; j++) {
      if (removew[j])
        continue;
      cout << a[i][j];
    }
    cout << endl;
  }
  return 0;
}