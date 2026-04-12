#include <bits/stdc++.h>
using namespace std;
long long i, j, k;

const long long FACT_MAX = 3000;
long long MOD;
long long famod[FACT_MAX+1];
long long simod[FACT_MAX+1];
long long fimod[FACT_MAX+1];

void create_fact_mod(int num){
    famod[0] = 1;
    famod[1] = 1;
    long long i;
    for(i=2; i<=num; i++){
        famod[i] = famod[i-1] * i % MOD;
    }
}

void create_seq_inv_mod(int num){
    simod[0] = 1;
    simod[1] = 1;
    long long i;
    for(i=2; i<=num; i++){
        simod[i] = (MOD - MOD/i) * simod[MOD%i] % MOD;
    }
}

void create_fact_inv_mod(int num){
    fimod[0] = 1;
    fimod[1] = 1;
    long long i;
    for(i=2; i<=num; i++){
        fimod[i] = fimod[i-1] * simod[i] % MOD;
    }
}

void create_mod_tables(int num){
    create_fact_mod(num);
    create_seq_inv_mod(num);
    create_fact_inv_mod(num);
}

long long comb_mod(int n, int k){
    return famod[n] * fimod[n-k] % MOD * fimod[k] % MOD;
}

long long perm_mod(int n, int k){
    return famod[n] * fimod[n-k] % MOD;
}

long long power_mod(long long num, long long power){
    long long prod = 1;
    num %= MOD;
    while(power > 0){
        if((power&1) == 1){
            prod = prod * num % MOD;
        }
        num = num * num % MOD;
        power >>= 1;
    }
    return prod;
}

long long N;
long long dp[3001][3001];
long long pmod[3001];

int main(){
    cin >> N >> MOD;
    create_mod_tables(N);
    dp[0][0] = 1;
    for(i=1; i<=N; i++){
        dp[i][0] = 1;
        for(j=1; j<=i; j++){
            dp[i][j] = (dp[i-1][j-1] + (j+1) * dp[i-1][j]) % MOD; 
        }
    }

    pmod[0] = 2;
    for(i=1; i<=N; i++){
        pmod[i] = pmod[i-1] * pmod[i-1] % MOD;
    }

    long long ans = 0;
    for(i=0; i<=N; i++){
        long long result = 0;
        for(j=0; j<=i; j++){
            result = (result + dp[i][j] * power_mod(2, (N-i)*j)) % MOD;
        }
        if((i%2) == 0){
            ans = (ans + result * pmod[N-i] % MOD * comb_mod(N, i)) % MOD;
        }else{
            ans = (ans - result * pmod[N-i] % MOD * comb_mod(N, i) % MOD + MOD) % MOD;
        }
    }
    cout << ans << endl;
    return 0;
}