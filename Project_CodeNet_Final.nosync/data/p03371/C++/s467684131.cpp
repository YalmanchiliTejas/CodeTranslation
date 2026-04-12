#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {

  int a,b,c,x,y;
  cin >> a >> b >> c >> x >> y;

  int res = 0,ans = 0;
  int m = min(x,y);
  while( m-- ) res += 2;
  if(x >= y) res = c*res + a*(x-y);
  else res = c*res + b*(y-x);
  ans = min( min(a*x+b*y,2*c*max(x,y)),res );

  cout << ans << endl;

  return 0;
}
