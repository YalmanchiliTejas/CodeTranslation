#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
  int a, b, ab, x, y;
  cin >> a >> b >> ab >> x >> y;
  ab *= 2; // a++, b++
  ll sum = a * x + b * y;
  ll ma = max(x, y);
  for(ll i = 1; i <= ma; i++){
    ll tmp = ab * i;
    ll tx = x - i;
    ll ty = y - i;
    if(tx > 0) tmp += tx * a;
    if(ty > 0) tmp += ty * b;
    sum = min(tmp, sum);
  }
  cout << sum << endl;
  return 0;
}
