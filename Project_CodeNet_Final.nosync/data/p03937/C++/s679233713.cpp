#include <bits/stdc++.h>
using namespace std;
#define dump(x) cout << (x) << endl
typedef long long ll;
typedef pair<int, int> pi;
typedef vector<int> V;

int main() {
  int h, w;
  cin >> h >> w;
  int cnt = 0;
  char x[8][8] = {};
  for (int i = 0; i < h; i++) {
    for (int j = 0; j < w; j++) {
      cin >> x[i][j];
      if (x[i][j] == '#') cnt++;
    }
    getchar();
  }
  cnt == h+w-1 ? dump("Possible") : dump("Impossible");
  return 0;
}
