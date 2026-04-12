#include <bits/stdc++.h>
using namespace std;

#define int long long

signed main() {
  int s, t, p, q, M, y;
  cin >> s >> t >> p >> q >> M >> y;

  int sum = y;
  int a = 0;
  int cnt = 1e8;  
  for ( int i = 0; i < cnt; i++ ) {
    sum ^= a;
    a = (a*p + q)%M;
  }

  cout << sum << endl;
  
  return 0;
}

