/*{{{*/
#include<bits/stdc++.h>

typedef long long ll;

#define REP(i,n) for(ll i=0;i<n;i++)
#define FOR(i,a,b) for(ll i=a;i<b;i++)
#define FORR(i,a,b) for(ll i=b-1;i>=a;i--)

#define vl vector<ll>
#define pll pair<ll,ll>

#define DEBUG(x) cout<<#x<<": "<<x<<endl

using namespace std;
/*}}}*/

int main() {
  ll MOD = 1e9+7;
  ll n;
  cin >> n;
  vl a(n);
  REP(i,n) cin >> a[i];
  vl ac(n);
  ac[n-1] = a[n-1];
  FOR(i,1,n) ac[n-1-i] = ac[n-i]+a[n-1-i];
  REP(i,n) ac[i] %= MOD;
  ll ans = 0;
  REP(i,n-1){
    ll tmp = a[i] * ac[i+1] % MOD;
    ans += tmp;
    ans %= MOD;
  }
  cout << ans << endl;
  return 0;
}
