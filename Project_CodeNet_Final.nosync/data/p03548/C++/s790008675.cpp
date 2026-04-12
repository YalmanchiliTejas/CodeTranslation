#include <bits/stdc++.h>
#define REP(i, n) for(int i = 0; i < n; i++)
using namespace std;
using ll = long long;

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int x, y, z;
  cin >> x >> y >> z;
  int ans = 0;
  x -= z;
  ans = x / (y + z);
  cout << ans << endl;
  return 0;
}