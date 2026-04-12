#include <bits/stdc++.h>
using namespace std;
#define IO ios_base::sync_with_stdio(false); cin.tie(NULL);

#define endl '\n'
#define D(x) cout << #x << " = " << (x) << endl;

int is_valid(int i, int j, int h, int w) {
  return 0 <= i and i < h and 0 <= j and j < w;
}

int main() { IO;
  int h, w;
  cin >> h >> w;

  vector<string> grid(h);
  for (auto &x : grid) cin >> x;
  
  int i = 0, j = 0;
  while (true) {
    grid[i][j] = '.';
    bool move = false;

    if (is_valid(i + 1, j, h, w) and grid[i + 1][j] == '#') {
      i = i + 1;
      j = j;
      move = true;
    } else if (is_valid(i, j + 1, h, w) and grid[i][j + 1] == '#') {
      i = i;
      j = j + 1;
      move = true;
    }

    if (!move) break;
    move = true;
  }

  int cnt = 0;
  for (auto &x : grid) {
    cnt += count(x.begin(), x.end(), '#');
  }

  if (cnt == 0) {
    cout << "Possible" << endl;
  } else {
    cout << "Impossible" << endl;
  }

  return 0;
}
