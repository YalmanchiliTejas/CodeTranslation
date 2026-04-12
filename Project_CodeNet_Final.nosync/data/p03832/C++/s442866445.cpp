#include<bits/stdc++.h>
using namespace std;
typedef long long lint;

const lint MOD = 1e9 + 7;
int N, A, B, C, D;
lint dp[1005][1005], fact[1005], fact_inv[1005];

lint mod_pow(lint x, lint y){
    lint res = 1;
    while(y){
        if(y & 1) res = res * x % MOD;
        x = x * x % MOD; y >>= 1;
    }
    return res;
}

lint comb(int n, int r){
    if(n < r) return 0;
    return fact[n] * fact_inv[n-r] % MOD * fact_inv[r] % MOD;
}

int main(){
    cin >> N >> A >> B >> C >> D;

    fact[0] = 1;
    for(int i=1;i<=N;i++) fact[i] = fact[i-1] * i % MOD;

    fact_inv[N] = mod_pow(fact[N], MOD-2);
    for(int i=N-1;0<=i;i--) fact_inv[i] = (i+1) * fact_inv[i+1] % MOD;

    for(int i=0;i<=N;i++) dp[i][0] = 1;
    for(int i=1;i<=N;i++){
        for(int j=1;j<=N;j++){
            dp[i][j] = dp[i-1][j];
            if(i < A || B < i) continue;

            lint c = comb(j, i);
            for(int k=1;i*k<=j;k++){
                if(C <= k && k <= D) {
                    dp[i][j] += c * dp[i-1][j-k*i] % MOD * fact_inv[k] % MOD;
                    dp[i][j] %= MOD;
                }
                c = c * comb(j-k*i, i) % MOD;
            }
        }
    }

    cout << dp[N][N] << endl;
    return 0;
}