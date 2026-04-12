#include <bits/stdc++.h>
#define rep(i,cc,n) for(int i=cc;i<=n;++i)
using namespace std;

int main() {
  int H, W;
  cin >> H >> W;

  int sharps = 0;
  string s;
  rep(i,0,H-1) {
    cin >> s;
    for (char c : s)
      if (c == '#') sharps++;
  }

  if (sharps == H + W - 1)
    cout << "Possible" << endl;
  else
    cout << "Impossible" << endl;
  return 0;
}
