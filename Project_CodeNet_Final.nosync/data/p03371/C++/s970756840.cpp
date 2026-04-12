#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  
  ll a, b, c, x, y, i, j, k;
  cin >> a >> b >> c >> x >> y;
  
  if(x >= y) {
    i = 2*c*y +a*(x-y);
    j = 2*c*x;
  }
  else {
    i = 2*c*x +b*(y-x);
    j = 2*c*y;
  }
  k = a*x + b*y;
  
  cout << min({i, j, k}) << "\n";
}
