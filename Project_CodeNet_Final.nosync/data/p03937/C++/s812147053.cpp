#include <iostream>
using namespace std;

int main() {
  int H, W;
  cin >> H >> W;

  int cnt = 0;
  for (int i = 0; i < H; i++) {
    for (int j = 0; j < W; j++) {
      char a;
      cin >> a;
      if (a == '#') cnt++;
    }
  }

  if (H + W - 1 == cnt)
    cout << "Possible" << endl;
  else
    cout << "Impossible" << endl;
}