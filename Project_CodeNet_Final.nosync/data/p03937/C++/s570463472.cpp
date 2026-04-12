#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int H, W;
  cin >> H >> W;
  char a;
  int cnt = 0;
  for (int i = 0; i < H; i++) {
    for (int j = 0; j < W; j++) {
      cin >> a;
      if (a == '#') cnt++;
    }
  }
  cout << (cnt == H + W - 1 ? "Possible" : "Impossible") << '\n';
  return 0;
}
