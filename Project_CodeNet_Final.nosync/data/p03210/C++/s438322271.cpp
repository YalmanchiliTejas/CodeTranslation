#include <bits/stdc++.h>
#define int long long
#define rep(i, a, n) for (int i = a; i < n; i++)
using namespace std;
using pii = pair<int, int>;

signed main() {
  cin.tie(0);
  ios_base::sync_with_stdio(false);
  cout << fixed << setprecision(10);
  
  int x;
  cin >> x;
  cout << (x == 7 || x == 5 || x == 3 ? "YES" : "NO") << endl;

  return 0;
}