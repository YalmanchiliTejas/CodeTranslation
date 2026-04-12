#include <bits/stdc++.h>
#include <vector>
#define rep(i, n) for(int i = 0; i < n; ++i)
#define ll long long
#define all(a) a.begin(), a.end() 
using namespace std;


int main() {
  int mod = 1000000007;
  ll n;
  cin >> n;
  ll ans = 0;
  ll num;
  cin >> num;
  
  rep(i, n-1) {
    ll a;
    cin >> a;
    ans += (num*a)%mod;
    ans %= mod;
    num += a;
    num %= mod;
  }
  
  cout << ans << endl;
}
