#include <bits/stdc++.h>
using namespace std;

int main() {
  int a,b,c,x,y;
  cin >> a >> b >> c >> x >> y;
  int z = min(x,y);
  int m = max(x,y);
  int ans1 = a*x+b*y;
  int ans2 = a*(x-z)+b*(y-z)+c*2*z;
  int ans3 = c*2*m;
  int ans = min(ans1,min(ans2,ans3));
  cout << ans <<endl;
}
