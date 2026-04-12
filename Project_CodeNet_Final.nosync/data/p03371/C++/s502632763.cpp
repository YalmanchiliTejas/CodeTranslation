#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main()
{
  int a, b, c, x, y;
  cin >> a >> b >> c >> x >> y;
  int upp = 2*max(x, y);
  ll ans = 1000000000;
  int i=0;
  while(i <= upp)
  {
    ll price = max(x-i/2, 0)*a + max(y-i/2, 0)*b + c*i;
    ans = min(ans, price);
    i+=2;
  }
  cout << ans << endl;
  
}
