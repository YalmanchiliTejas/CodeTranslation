#include <bits/stdc++.h>
using namespace std;

#define int long long

#define ii pair<int,int>
#define fi first
#define sc second

#define all(x) (x).begin(),(x).end()

signed main() {
#ifdef _DEBUG
  // freopen("in" , "r", stdin );
  // freopen("out", "w", stdout);
#endif
  ios::sync_with_stdio(0); cin.tie(0);
  int a, b, c;
  cin >> a >> b >> c;
  if ((a * 100 + b * 10 + c) % 4) {
    cout << "NO" << '\n';
  }
  else cout << "YES" << '\n';
}
