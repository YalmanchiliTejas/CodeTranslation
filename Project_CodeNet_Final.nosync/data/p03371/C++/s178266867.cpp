#include<bits/stdc++.h>
using namespace std;

signed main() {
  int a,b,c,x,y; cin >>a>>b>>c>>x>>y;
  int ans = 1e9;
  int xy = max(x,y);
  for(int ab=0; ab<=xy * 2; ab+=2) {
    int xx = max(0, x - ab/2);
    int yy = max(0, y - ab/2);
    ans = min(ans, ab * c + xx * a + yy * b); 
  }
  cout << ans << endl;
}
