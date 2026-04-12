#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main(void){
  int a,b,c,x,y;
  cin >> a >> b >> c >> x >> y;
  ll value; ll ans_first = a*x + b*y;
  ll ans = 1000000007;
  int x_now; int y_now;
  for (ll i=0; i<=max(x,y)*2; i+=2){
    if (x-i/2 < 0) x_now = x;
    else x_now = i/2;
    if (y-i/2 < 0) y_now = y;
    else y_now = i/2;
    value = ans_first + c*i - a*x_now - b*y_now;
    if (value < ans) ans = value;
  }
  cout << ans << "\n";
  return 0;
}