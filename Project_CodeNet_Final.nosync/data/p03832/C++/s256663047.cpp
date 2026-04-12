#include <bits/stdc++.h>
using namespace std;

using P = pair<int,int>;
using P3 = pair<P, int>;
using ll = long long int;
constexpr int INF = 1<<30;
constexpr ll MOD = (1e9)+7;

vector<ll> factrial, inverse;  //階乗と逆元を保持

ll mod_power(ll x, ll n) {  //繰り返し二乗法
    x %= MOD;
    ll res = 1;
    while (n > 0) {
        if (n & 1) {
            res = res * x % MOD;
        }
        x = x * x % MOD;
        n >>= 1;
    }
    return res;
}

void init(ll n) {
    factrial.resize(n+1);
    inverse.resize(n+1);
    factrial[0] = 1;
    inverse[0] = 1;
    for (ll i = 1; i <= n; i++) {
        factrial[i] = (factrial[i - 1] * i) % MOD;
        inverse[i] = mod_power(factrial[i], MOD - 2);
    }
}

ll nCk(ll n, ll k) {
    if(n < 0 || k < 0 || n < k) return 0;
    return factrial[n] * inverse[k] % MOD * inverse[n - k] % MOD;
}

int main() {
    int n, a, b, c, d;
    cin >> n >> a >> b >> c >> d;
    init(n);
    vector<vector<ll> > dp(n+1, vector<ll>(b-a+2));
    dp[0][0] = 1;
    for(int i=0;i<=n;i++){
        for(int j=0;j<=b-a;j++){
            dp[i][j+1] += dp[i][j];
            dp[i][j+1] %= MOD;
            int x = j+a;
            for(int k=c;k<=d;k++){
                if(i+x*k <= n){
                    dp[i+x*k][j+1] += dp[i][j]*nCk(n-i,x*k)%MOD*factrial[x*k]%MOD*inverse[k]%MOD*mod_power(inverse[x],k)%MOD;
                    dp[i+x*k][j+1] %= MOD;
                }
            }
        }
    }
    cout << dp[n][b-a+1] << endl;
    return 0;
}
