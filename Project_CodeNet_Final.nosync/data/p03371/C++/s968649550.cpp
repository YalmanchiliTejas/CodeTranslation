#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;

int main() {
  int a,b,c,x,y;
  cin >> a >> b >> c >> x >> y;


  ll res = 0;
  int z = min(x,y);
  if(a + b > 2 * c) {
    res += z * c * 2;
    x -= z;
    y -= z;
  }
  if(a > 2 * c) {
    res += x * c * 2;
  } else {
    res += x * a;
  }
  if(b > 2 * c) {
    res += y * c * 2;
  } else {
    res += y * b;
  }
  cout << res << '\n';
}