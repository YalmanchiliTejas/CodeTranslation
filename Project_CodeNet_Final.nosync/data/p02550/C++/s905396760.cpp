#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (int)n; i++)
using ll = long long;

int main(){
  ll n, x, m;
  cin >> n >> x >> m;
  vector<ll> u(m+1);
  u[x] = 1;
  ll p = 2;
  ll c = (x*x) % m;
  while(!u[c]) {
    u[c] = p++;
    c = (c * c) % m;
  }
  ll ans = 0;
  if(n <= u[c]) {
    for(int i = 1; i <= n; i++) {
      ans += x;
      x = (x * x) % m;
    }
  } else {
    for(int i = 1; i < u[c]; i++) {
      ans += x;
      x = (x * x) % m;
    }
    ll cycle = p - u[c];
    ll sum = c;
    ll y = (c * c) % m;
    while(y != c) {
      sum += y;
      y = (y * y) % m;
    }
    ans += sum * ((n-u[c]+1)/cycle);
    ll res = (n-u[c]+1) % cycle;
    rep(i,res) {
      ans += c;
      c = (c * c) % m;
    } 
  }
  cout << ans << endl;
  return 0;
}
