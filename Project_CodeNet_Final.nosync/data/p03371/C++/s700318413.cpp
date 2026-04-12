#include <bits/stdc++.h>
using namespace std;
using ll = long long; 
#define rep(i, n) for (int i = 0; i < (int)n; i++)
ll inf = 1e10;

ll gcd(ll a, ll b){
  return (b != 0) ? gcd(b, a%b) : a;
}

int main(){
  int a, b, c, x, y;
  cin >> a >> b >> c >> x >> y;
  ll ans = 0;
  int maxab = (x > y) ? a : b;
  if(a+b > 2*c){
    ans += 2*c*min(x,y);
    if(maxab > 2*c) ans += 2*c*abs(x-y);
    else ans += maxab*abs(x-y);
  }
  else ans += a*x+b*y;
  cout << ans << endl;
}