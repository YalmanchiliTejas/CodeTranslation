#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(ll i=0; i<n; i++)
typedef long long ll;
typedef long long unsigned int llu;
ll MOD = 1000000007;
ll INF = 1000000009;

int a[110][110];

void solve(){

    ll a,b,c;
    ll x,y;
    cin >> a >> b >> c >> x >> y;
    ll ans = INF;
    for(ll i=0; i<=max(x,y); i++){
        ans = min(ans, max((x-i),ll(0))*a+max((y-i),ll(0))*b+2*i*c);
    }
    cout << ans << endl;

}

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  solve();
  return 0;
}
