#include <bits/stdc++.h>
#define rep(i,n) for (int i=0; i<(int)(n); i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
  int a, b, c, x, y;
  cin >> a >> b >> c >> x >> y;
  int ans=0;
  int c2 = c*2;
  
  if (a > c2 && b > c2) {
    ans = max(x,y) * c2;
  }
  else {
    if (a+b > c2) { 
      ans += c2 * min(x,y);
      if (x<y) ans+=(y-x) * min(b,c2);
      else     ans+=(x-y) * min(a,c2);
    }
    else ans = a*x + b*y;
  }
  cout << ans << endl;
  return 0;
  }
