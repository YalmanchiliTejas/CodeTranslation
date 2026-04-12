#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,n) for (ll i = 0; i < (n); i++)
typedef pair<ll,ll> P;

ll gcd(ll a, ll b) { return b?gcd(b,a%b):a;}
ll lcm(ll a, ll b) { return a/gcd(a,b)*b;}

ll mod = (ll)(1e9+7);

int main(){
  ll n;
  cin >> n;
  vector<ll> a(n);
  ll sum = 0;
  rep(i,n){
    cin >> a[i];
    sum += a[i];
  }

  ll ans = 0;
  rep(i,n-1){
    sum -= a[i];
    ll tmp = sum%mod;
    tmp *= a[i];
    tmp %= mod;
    ans += tmp;
    ans %= mod;
  }

  cout << ans << endl;

  return 0;
}