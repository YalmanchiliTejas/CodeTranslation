#include <bits/stdc++.h>

using namespace std;
int a,b,c,x,y;
int main() {
  cin >> a >> b >> c >> x >> y;
  if(x < y) {
    swap(a,b);
    swap(x,y);
  }
  
  int ans = 0;
  if(a + b >= 2 * c) {
    ans += 2 * c * y;
    if(a >= 2 * c) {
      ans += 2 * c * (x - y);
    }
    else ans += a * (x - y);
    
    cout << ans << endl;
  }
  else {
    cout << x * a + y * b << endl;
  }
    
}
