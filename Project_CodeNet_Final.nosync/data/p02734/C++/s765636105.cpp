#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef vector<ll> v1;
typedef vector<v1> v2;
typedef vector<v2> v3;

typedef unordered_map<ll, unordered_map<ll, ll>> graph;

const ll INF = 1ll << 50;
const ll mod = 998244353;

ll n,s;
v1 a;
v2 dp; // dp[s][n]
ll ans = 0;

int main(){
    cin >> n >> s;
    a = v1(n+1);
    for(ll i = 1;i <= n;i++){
        cin >> a[i];
    }
    dp = v2(s+1, v1(n+1, 0));
    for(ll i = 1;i <= n;i++){
        if(a[i] <= s){
            dp[a[i]][i] += i;
            dp[a[i]][i] %= mod;
        }
        for(ll j = 0;j < a[i] && j <= s;j++){
            dp[j][i] += dp[j][i-1];
            dp[j][i] %= mod;
        }
        for(ll j = a[i];j <= s;j++){
            dp[j][i] += dp[j-a[i]][i-1] + dp[j][i-1];
            dp[j][i] %= mod;
        }
    }
    for(ll i = 1;i <= n;i++){
        ans += dp[s][i];
        // cerr << dp[s][i] << endl;
        ans %= mod;
    }
    cout << ans << endl;
}
