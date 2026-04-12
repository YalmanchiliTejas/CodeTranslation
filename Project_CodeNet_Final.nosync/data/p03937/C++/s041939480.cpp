#include <bits/stdc++.h>

using namespace std;

using int64 = long long;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int h, w;
  cin >> h >> w;
  int count = 0;
  for (int i = 0; i < h; i++) {
    string line;
    cin >> line;
    for (char c : line) {
      if (c == '#') count++;
    }
  }
  if (count == h + w - 1) {
    cout << "Possible" << endl;
  } else {
    cout << "Impossible" << endl;
  }
}
