#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (n); ++i)
using ll = long long;
using P = pair<int, int>;

int main(){
  int a, b, c, x, y;
  cin >> a >> b >> c >> x >> y;

  int p;
  rep(i, x) p += a;
  rep(i, y) p += b;

  ll ans = p;
  rep(i, max(x, y)){
    p += c * 2;
    if (i < x) p -= a;
    if (i < y) p -= b;
    if (ans > p) ans = p;
  }
  cout << ans << endl;
  return 0;
}