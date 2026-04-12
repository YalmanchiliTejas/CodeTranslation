#include <bits/stdc++.h>
using namespace std;
using ll = long long;
ll Mod = 1000000007;
int main() {
  ll A,B,C,X,Y;
  cin >> A >> B >> C >> X >> Y;
  ll ans = 9999999999999999;
  for (int i = 0; i <= max(X,Y)+1; i++) {
    ll res = (C * i * 2) + (B * max((ll)(0),Y-i)) + (A * max((ll)(0),X-i));
    ans = min(ans,res);
  }
  cout << ans << endl;
  return 0;
}