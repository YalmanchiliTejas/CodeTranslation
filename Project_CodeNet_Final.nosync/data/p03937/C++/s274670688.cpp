#include <bits/stdc++.h>
#define REP(i, n) for(int i = 0; i < n; i++)
#define ALL(v) (v).begin(), (v).end()

using namespace std;
using ll = long long;

int main()
{
  int H, W; cin >> H >> W;
  int cnt = 0;
  REP(h, H) REP(w, W) {
    char c; cin >> c;
    cnt += (c == '#' ? 1 : 0);
  }

  if (cnt == H+W-1) {
    cout << "Possible" << endl;
  } else {
    cout << "Impossible" << endl;
  }
}