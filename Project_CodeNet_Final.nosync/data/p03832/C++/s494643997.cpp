#include<bits/stdc++.h>
using namespace std;
using ll = int64_t;

#define S (ll)1e6 + 10

const ll MOD = 1e9 + 7;

ll fact[S] = {1};
ll pow(ll a, ll b){return b ? (b & 1 ? a : 1) * pow(a * a % MOD, b / 2) % MOD : 1;}
ll dp[1001][1001];

int main(){
    for(ll i = 1; i < S; i++) fact[i] = i * fact[i - 1] % MOD;
    ll N, A, B, C, D;
    cin >> N >> A >> B >> C >> D;
    dp[0][0] = 1;
    for(ll i = 1;; i++){
        ll k = A + i - 1;
        if(B < k) break;
        for(ll j = 0; j <= N; j++){
            dp[i][j] = dp[i - 1][j];
            for(ll l = C; l <= D; l++){
                if(j < k * l) break;
                dp[i][j] += (dp[i - 1][j - k * l] * fact[N - j + l * k] % MOD * pow(fact[N - j] * fact[l] % MOD * pow(fact[k], l) % MOD, MOD - 2)) % MOD;
                dp[i][j] %= MOD;
            }
        }
    }
    cout << dp[B - A + 1][N] << endl;
    return 0;
}
