#include <bits/stdc++.h>
using namespace std;

int main() {
  int h, w, count = 0;
  cin >> h >> w;
  char a[h][w];
  for (int i = 0; i < h; i++) {
    for (int j = 0; j < w; j++) {
      cin >> a[i][j];
      if (a[i][j] == '#')
        count++;
    }
  }
  if (count == h+w-1)
    cout << "Possible" << endl;
  else
    cout << "Impossible" << endl;
  return 0;
}
