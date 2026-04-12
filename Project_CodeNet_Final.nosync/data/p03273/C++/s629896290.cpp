#include <bits/stdc++.h>
using namespace std;
#define dump(x) cout << (x) << endl
typedef long long ll;
typedef pair<int, int> pi;
typedef vector<int> V;

int main() {
  int h, w;
  char ma[100][100] = {};
  cin >> h >> w;
  
  for (int i = 0; i < h; i++) {
    for (int j = 0; j < w; j++) {
      cin >> ma[i][j];
    }
  }
  
  V y(h, 0), x(w, 0);
  for (int i = 0; i < h; i++) {
    int cnt = 0;
    for (int j = 0; j < w; j++) {
      if (ma[i][j] == '.') cnt++;
    }
    if (cnt == w) y[i] = 1;
  }
  
  for (int i = 0; i < w; i++) {
    int cnt = 0;
    for (int j = 0; j < h; j++) {
      if (ma[j][i] == '.') cnt++;
    }
    if (cnt == h) x[i] = 1;
  }
  
  for (int i = 0; i < h; i++) {
    if (y[i] == 1) continue;
    for (int j = 0; j < w; j++) {
      if (x[j] == 1) continue;
      cout << ma[i][j];
    }
    cout << endl;
  }
  return 0;
}
