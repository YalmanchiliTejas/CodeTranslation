#include <bits/stdc++.h>
using namespace std;

int main(){
  long a, b, c, x, y, ans = 1e13;
  cin >> a >> b >> c >> x >> y;
  
  for(long i=max(x, y)*2; i>=0; i-=2){
    long price = c*i + a*max(0L, x-i/2) + b*max(0L, y-i/2);
    ans = min(ans, price);
  }

  cout << ans << endl;
  return 0;
}
