#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <iomanip>
#include <map>
#include <set>
using namespace std;

void solve(){
  int a, b, c, x, y; cin >> a >> b >> c >> x >> y;
  int ans = 0;
  if(a + b > c * 2){
    if(x > y){
      x -= y;
      ans += c * 2 * y;
      if(a > c * 2) ans += c * 2 * x;
      else ans += a * x;
    }
    else{
      y -= x;
      ans += c * 2 * x;
      if(b > c * 2) ans += c * 2 * y;
      else ans += b * y;
    }
  }
  else{
    ans += a * x + b * y;
  }
  cout << ans << endl;
}

int main(){
  solve();
  return 0;
}
