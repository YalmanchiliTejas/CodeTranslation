#include<iostream>
typedef long long ll;
using namespace std;
ll p[55];
ll a;
ll f(ll n, ll x) {
  // cin >> a;
  //cout << n <<"   "<<x << endl;
  if(x <= 0 || n < -1) return 0;

  ll res = 0;
  
  if(x <= p[n+1] - 2ll) {
    res = f(n-1,x-1ll);
  }
  else {
    res = f(n-1,x-p[n+1]+1) + p[n];
  }
  return res;
}
  
int main() {
  ll n;
  ll x;
  cin >> n >> x;
  p[0] = 1;
  for(int i = 1; i <= n+1; i++) {
    p[i] = p[i-1] * 2;
  }

  cout << f(n,x) << endl;
}
 
  
