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
        for(int j = 1; j <= n; j++){
            ll p = 1;
            dp[i][j] += dp[i - 1][j];
            for(int k = 1; k <= d; k++){
                if(j - i * k < 0) break;
                p = p * combination(n - j + i * k, i) % mod * inv[k] % mod;
                if(c <= k && k <= d){
                    (dp[i][j] += (dp[i - 1][j - i * k]) * p % mod) %= mod;
                }
            }
        }
    }
    cout << dp[b][n] << endl;
    
}