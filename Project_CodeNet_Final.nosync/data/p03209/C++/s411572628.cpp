#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cmath>
using ll = long long;
#define rep(i, n) for(ll i = 0; i < n; i++)
using namespace std;

vector<ll> layer(51), p(51);
ll f(ll n, ll x){
  if (n == 0) return 1;
  if (x <= 1) return 0;
  if (x <= layer[n]/2) return f(n-1, x-1);
  if (x == layer[n]/2+1) return p[n-1] + 1;
  if (x < layer[n]) return p[n-1] + 1 + f(n-1, x-layer[n]/2-1);
  return p[n];
}

int main(){
  ll n, x;
  cin >> n >> x;
  layer[0] = 1;
  p[0] = 1;
  rep(i, n){
    layer[i+1] = 2 * layer[i] + 3;
    p[i+1] = 2 * p[i] + 1;
  }
  ll ans = f(n, x);
  cout << ans << endl;
  
  return 0;
}