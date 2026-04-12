#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define rep(i, n) for(int i = 0;i < (int)(n);i++)

int main() {
  int n;
  ll x, s = 0, s2 = 0, mod = 1000000007;
  cin >> n;
  rep(i, n) {
    cin >> x;
    s += x;
    s2 += (x * x)%mod;
  }
  s = s % mod;
  s2 = s2 % mod;
  x = s*s - s2;
  if(x < 0) x += mod;
  ll ans = x % mod;
  if(ans % 2 == 1) ans += mod;
  cout << ans/2 << endl;
}