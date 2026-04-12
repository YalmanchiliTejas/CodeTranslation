#include <bits/stdc++.h>

using namespace std;

#define int long long
#define pb push_back
#define FOR(i, a, b) for(int i=(a);i<(b);i++)
#define REP(i, n) FOR(i, 0, n)

signed main () {
  cin.tie(0);
  cout << setprecision(10);

  int h, w; cin >> h >> w;

  vector<vector<char>> a(h);

  char tmp;
  REP(i, h) {
    REP(j, w) {
      cin >> tmp;
      a[i].pb(tmp);
    }
  }

  map<int, int> b, c;

  bool ok = false;
  REP(i, h) {
    ok = false;
    REP(j, w) {
      if(a[i][j] == '#') break;
      if(j == w-1) ok = true;
    }
    if(ok) b[i] = 1;
  }

  REP(i, w) {
    ok = false;
    REP(j, h) {
      if(a[j][i] == '#') break;
      if (j == h-1) ok = true;
    }
    if(ok) c[i] = 1;
  }

  //REP(i, h) //cout << b[i];
  //cout << endl;
  //REP(i, w) //cout << c[i];
  //cout << endl;

  

  REP(i, h) {
    if(b[i] == 1) continue;
    REP(j, w) {
      if(c[j] != 1) cout << a[i][j];
    }
    cout << endl;
  }
}
