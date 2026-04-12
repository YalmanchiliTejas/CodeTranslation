#include <bits/stdc++.h>
using namespace std;

int main(){
  int a, b, c, x, y; cin >> a >> b >> c >> x >> y;
  int ans = 1001001001;
  for(int i = 0; i <= 2*max(x, y); i++){
    int tmp = i * c;
    if(x - i/2 > 0) tmp += a * (x - i/2);
    if(y - i/2 > 0) tmp += b * (y - i/2);
    ans = min(ans, tmp);
  }
  cout << ans << endl;
}
    
      