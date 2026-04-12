#include <iostream>
#include <cmath>
typedef long long ll;
#define rep(i, n) for(ll i = 0; i < n; i++)
using namespace std;

int main(){
  ll a, b, c, x, y;
  cin >> a >> b >> c >> x >> y;
  
  ll less = min(x, y);
  ll ans = 0;
  ans += min(a + b, c * 2) * less;
  if (x > y){
    ans += min(a, c * 2) * (x - y);
  }
  else if (x < y){
    ans += min(b, c * 2) * (y - x);
  }
  cout << ans << endl;
  
  return 0;
}