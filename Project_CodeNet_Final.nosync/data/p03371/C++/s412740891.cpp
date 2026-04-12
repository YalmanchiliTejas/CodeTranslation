// -----------------------------------
// Author     : MatsuTaku
// Affiliation: Tokushima University
// Country    : Japan
// Date       : 04/03/2020
// -----------------------------------

#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
  cin.tie(nullptr); ios::sync_with_stdio(false);

  int a,b,c,x,y; cin>>a>>b>>c>>x>>y;
  int ans = a*x+b*y;
  {
    int cc = min(x,y);
    int ans2 = cc*2*c + (cc==x ? (y-cc)*b : (x-cc)*a);
    int ans3 = max(x,y)*2*c;
    ans = min(ans, min(ans2, ans3));
  }
  cout << ans << endl;

  return 0;
}
