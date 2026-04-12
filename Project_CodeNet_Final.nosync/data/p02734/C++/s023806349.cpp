#include <bits/stdc++.h>
#define maxn 3005
#define MOD 998244353
#define INF 10000000

using namespace std;

#define ll long long
#define pii pair<ll, ll>
#define piii pair<ll, pii>
#define ft first
#define sd second

void fast(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
}

ll dp[maxn][maxn];

void solve(){
    ll n, s, ans = 0;
    cin >> n >> s;
    ll a[n];
    for(ll i = 0; i < n; i++) cin >> a[i];

    for(ll i = 0; i < n; i++){
        memcpy(dp[i+1], dp[i], sizeof(dp[0]));

        dp[i+1][a[i]] = (dp[i+1][a[i]] + i+1)%MOD;
        for(ll j = 0 ; j+a[i]<= s; j++){
            dp[i+1][j+a[i]] = (dp[i+1][j+a[i]] + dp[i][j])%MOD;
        }
        ans  = (ans + dp[i+1][s])%MOD;
    }
    cout << ans ;
}

int main()
{
    fast();
    int t= 1; //cin >> t;
    while(t--){
        solve();
    }
}

/*
5
1 2
2 3
3 4
3 5
*/
