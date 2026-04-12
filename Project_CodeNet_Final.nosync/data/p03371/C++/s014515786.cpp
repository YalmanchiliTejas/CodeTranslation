#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main() {
  ll a, b, c, x, y;
  cin >> a >> b >> c >> x >> y;
  
  // x >= y を保証
  if(x < y){
    swap(x, y);
    swap(a, b);
  }
  
  ll ans = min({a * x + b * y, 2 * c * max(x, y), 2 * c * min(x, y) + a * (x - y)});
  
  cout << ans << endl;
}