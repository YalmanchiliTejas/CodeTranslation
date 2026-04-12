#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < n; i++)
#define per(i,n) for(int i = n-1; i >= 0; i--)
typedef long long ll;
typedef pair<int, int> P;
typedef pair<long long, long long> Pll;
typedef vector<int> vi;
typedef vector<ll> vll;
const long long mod = 1000000007LL;

int main() {
  ll n;
  cin >> n;
  vll a(n);
  rep(i,n) cin >> a[i];
  ll sum = 0LL;
  rep(i,n) sum += a[i];
  ll ans = 0LL;
  rep(i,n) {
    sum -= a[i];
    ll num = sum%mod;
    ans += (num*a[i]);
    ans %= mod;
  }
  if(ans<0) ans += mod;
  cout << ans << endl;
  return 0;
}
