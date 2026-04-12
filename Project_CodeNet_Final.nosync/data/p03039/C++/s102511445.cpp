#include <algorithm>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <stack>
#include <string>
#include <utility>
#include <vector>
 
using namespace std;
 
typedef long long ll;
 
const ll M = 1e9+7;
 
ll n, m, k, ans;
ll fact[220000];
 
ll mpow(ll a, ll n) {
  if (n == 0) return 1;
  if (n % 2) return mpow(a, n-1) * a % M;
  return mpow(a * a % M, n/2);
}
 
ll cmb(ll n, ll r) {
  return fact[n] * mpow(fact[r], M-2) % M * mpow(fact[n-r], M-2) % M;
}
 
int main() {
  cin >> n >> m >> k;
  
  fact[0] = 1;
  for (ll i = 1; i <= 220000; ++i) {
    fact[i] = fact[i-1] * i % M;
  }
  
  ans = 0;
  for (ll i = 1; i <= n-1; i++) {
    ans += i * (n-i) * m % M * m % M * cmb(n*m-2, k-2) % M;
    ans %= M;
  }
  
  for (ll i = 1; i <= m-1; i++) {
    ans += i * (m-i) * n % M * n % M * cmb(n*m-2, k-2) % M;
    ans %= M;
  }
  
  ans %= M;
  
  cout << ans << endl;
  return 0;
}