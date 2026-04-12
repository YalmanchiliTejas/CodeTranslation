#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const ll mod = 1e9 + 7;
ll n, a, b, c, d;
ll dp[1010][1010];
ll fact[1010], fact_inv[1010], inv[1010];

long long mod_pow(long long x, long long n){
    if(n == 0) return 1;
    long long res = mod_pow(x * x % mod, n / 2);
    if(n & 1) res = res * x % mod;
    return res;
}

long long combination(long long n, long long k){
    return fact[n] * fact_inv[k] % mod * fact_inv[n - k] % mod;
}

int main(){
    cin >> n >> a >> b >> c >> d;
    
    memset(dp, 0, sizeof(dp));
    for(int i = 0; i < 1010; i++) dp[i][0] = 1;

    fact[0] = fact_inv[0] = 1;
    for(int i = 1; i < 1010; i++){
        inv[i] = mod_pow(i, mod - 2);
        fact[i] = fact[i - 1] * i % mod;
        fact_inv[i] = fact_inv[i - 1] * inv[i] % mod;
    }

    for(int i = a; i <= b; i++){
        for(int j = 0; j <= n; j++){
            if(dp[i][j] == 0) continue;
            if(j != 0) (dp[i + 1][j] += dp[i][j]) %= mod;
            ll p = 1;            
            for(int k = 1; k <= d; k++){
                if(j + i * k > n) break;
                p = p * combination(n - j - i * (k - 1), i) % mod * inv[k] % mod;
                if(c <= k && k <= d){
                    (dp[i + 1][j + i * k] += dp[i][j] * p % mod) %= mod;
                }
            }
        }
    }
    cout << dp[b + 1][n] << endl;
}