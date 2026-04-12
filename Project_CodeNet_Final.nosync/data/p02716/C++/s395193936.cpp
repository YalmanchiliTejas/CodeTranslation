#include <bits/stdc++.h>
#define maxn 200001
#define maxa 201
#define MOD 1000000007
#define INF 1000000000000000000
#define lim 20

using namespace std;

#define ll long long
#define pii pair<ll, ll>
#define piii pair<pii, ll>
#define ft first
#define sd second

void fast(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
}

ll power(ll a, ll b){
    if(b == 0) return 1;
    ll r = power(a, b/2);
    r = (r*r)%MOD;
    if(b%2 == 1) r = (r*a)%MOD;
    return r;
}




void solve(){
    ll n;
    cin >> n;
    ll a[n];
    for(ll i = 0; i < n; i++)cin >> a[i];

    ll dp[3][n+1];
    memset(dp, 0, sizeof(dp));
  dp[0][0] = a[0];
  for (int i = 1; i < n/2; i++) {
    dp[0][i] = dp[0][i-1] + a[i*2];
  }
  dp[1][0] = a[1];
  for (int i = 1; i < n/2; i++) {
    dp[1][i] = max(dp[0][i-1], dp[1][i-1]) + a[i*2+1];
  }
  dp[2][0] = a[2];
  for (int i = 1; i < n/2; i++) {
    dp[2][i] = max(max(dp[0][i-1], dp[1][i-1]), dp[2][i-1]) + a[i*2+2];
  }

  ll ans = max(dp[0][n/2-1], dp[1][n/2-1]);
  if (n % 2 == 1) ans = max(ans, dp[2][n/2-1]);

  cout << ans << endl;

}

int main()
{
    fast();
    ll t = 1;
    //cin >> t;
    while(t--){
        solve();
    }
}
