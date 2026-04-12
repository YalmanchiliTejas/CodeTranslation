#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;

int main() {
  cin.tie(0);
  ios_base::sync_with_stdio(false);
  
  int h, w;
  cin >> h >> w;

  vector<string> a(h);
  for (int i = 0; i < h; i++) {
    cin >> a[i];
  }

  for (int i = 0; i < h; i++) {
    for (int j = 0; j < w; j++) {
      bool up = false, left = false;
      if (i > 0) up |= a[i - 1][j] == '#';
      if (j > 0) left |= a[i][j - 1] == '#';
      if (up && left) {
        cout << "Impossible" << endl;
        return 0;
      }
    }
  }
  cout << "Possible" << endl;

  return 0;
}