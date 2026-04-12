#include <bits/stdc++.h>
using namespace std;
 
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int h, w;
  cin >> h >> w;
  int count = 0;
  for (int i = 0; i < h * w; i++) {
    char c;
    cin >> c;
    if (c == '#') {
      count++;
    }
  }
  if (count == h + w - 1) {
    cout << "Possible" << '\n';
  }
  else {
    cout << "Impossible" << '\n';
  }
}