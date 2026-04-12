#include <iostream>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int H, W;
  cin >> H >> W;
  char c;
  int n = 0;
  for (int i = 0; i < H; ++i) {
    for (int j = 0; j < W; ++j) {
      cin >> c;
      if (c == '#') ++n;
    }
  }
  if (n == H + W - 1)
    cout << "Possible" << endl;
  else
    cout << "Impossible" << endl;

  return 0;
}
