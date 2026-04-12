#include <bits/stdc++.h>
using namespace std;

int main() {
  int H, W; cin >> H >> W;
  int cnt = 0;
  for (int i = 0; i < H; i++) {
    string S; cin >> S;
    for (int j = 0; j < S.size(); j++) {
      if (S.at(j) == '#') cnt++;
    }
  }
  if (cnt == H+W-1) cout << "Possible" << endl;
  else cout << "Impossible" << endl;
}