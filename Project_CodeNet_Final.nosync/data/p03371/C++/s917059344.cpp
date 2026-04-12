#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); i++)
using ll = long long;

int main() {
  int a,b,c,x,y;
  cin >> a >> b >> c >> x >> y;
  ll total = 0;
  ll ans = 100000000000000;
  rep(i,100001) {
    total = 2 * c * i + max(x-i,0) * a + max(y-i,0) * b;
    ans = min(ans,total);
  }
  cout << ans << endl;
}
