#include <iostream>
using namespace std;
typedef long long ll;

const ll MOD = 1000000007;

ll cmemo[1002][1002];
ll dp[1002][1002];

ll modpow(ll x, ll n){
    ll res = 1;
    ll mul = x;
    while(n){
        if(n % 2) res = res * mul % MOD;
        mul = mul * mul % MOD;
        n /= 2;
    }
    return res;
}

ll com(int n, int k){
    if(cmemo[n][k]) return cmemo[n][k];
    if(k == 0 || k == n) return 1;
    return cmemo[n][k] = (com(n - 1, k) + com(n - 1, k - 1)) % MOD;
}

int main()
{
    ll n, a, b, c, d;
    cin >> n >> a >> b >> c >> d;
    ll r[1002];
    for(int i = 1; i <= n; i++) r[i] = modpow(i, MOD - 2);
    dp[0][0] = 1;
    for(int i = 1; i <= n; i++){
        for(int k = 0; k <= n; k++) dp[i][k] = dp[i - 1][k];
        if(i < a || i > b) continue;
        for(int k = 0; k <= n; k++){
            ll s = 1;
            for(int j = 1; j * i <= k; j++){
                s = s * com((n - k) + i * j, i) % MOD * r[j] % MOD;
                if(j >= c && j <= d) dp[i][k] = (dp[i][k] + dp[i - 1][k - j * i] * s % MOD) % MOD;
            }
        }
    }
    cout << dp[n][n] << endl;
}