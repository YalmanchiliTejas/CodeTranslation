#include <bits/stdc++.h>
using namespace std;

int main() {
  int H, W; cin >> H >> W;
  vector<string> S(H); for (int i = 0; i < H; i++) cin >> S[i];
  
  int num = H+W-1;
  int ret = 0;
  for (string s : S) {
    for (char a : s) {
      if (a == '#') ret++;
    }
  }
  
  if (ret == num) cout << "Possible" << endl;
  else cout << "Impossible" << endl;
}
