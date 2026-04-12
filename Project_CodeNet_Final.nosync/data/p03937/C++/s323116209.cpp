#include <bits/stdc++.h>
using namespace std;

int main() {
  int H, W, cnt = 0;
  cin >> H >> W;
  char C;
  while (cin >> C) if (C == '#') cnt++;
  cout << ((cnt == H + W - 1) ? "Possible" : "Impossible") << "\n";
}