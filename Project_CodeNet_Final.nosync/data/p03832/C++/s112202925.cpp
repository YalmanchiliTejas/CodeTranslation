#include <bits/stdc++.h>
using namespace std;
#define ll long long

ll mod = 1e9+7;
ll modpower(ll a, ll r){ //a^r
    ll x = 1;
    while (r > 0) {
        if (r & 1) x = x * a % mod;
        r >>= 1;
        a = a * a % mod;
    }
    return x;
}

ll modinv(ll a){
    return modpower(a, mod-2);
}

int main(){
    ll N, A, B, C, D;
    cin >> N >> A >> B >> C >> D;
    vector<ll> fact(1001, 1), invfact(1001, 1);
    for (int i = 2; i <= 1000; i++) fact[i] = fact[i-1]*i%mod;
    invfact[1000] = modinv(fact[1000]);
    for (int i = 999; i >= 2; i--) invfact[i] = invfact[i+1]*(i+1)%mod;
    
    vector<vector<ll>> dp(B+1, vector<ll>(N+1, 0));
    dp[A-1][0] = 1;
    for (int i = A; i <= B; i++) {
        vector<ll> ik(D+1, 1);
        for (int k = 1; k <= D; k++) ik[k] = ik[k-1]*invfact[i]%mod;
        for (int j = 0; j <= N; j++) {
            dp[i][j] = dp[i-1][j];
            for (int k = C; k <= D; k++) {
                if (i*k > j) break;
                dp[i][j] += dp[i-1][j-i*k]*invfact[k]%mod*ik[k]%mod;
            }
            dp[i][j] %= mod;
        }
    }
    cout << dp[B][N]*fact[N]%mod << endl;
    return 0;
}
