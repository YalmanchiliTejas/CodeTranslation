#include <bits/stdc++.h>
using namespace std;

const long long FACT_MAX = 1001;
const long long MOD = 1e9+7;
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

long long extgcd(long long a, long long b, long long& x, long long& y){
    long long d = a;
    if(b != 0){
        d = extgcd(b, a%b, y, x);
        y -= (a/b) % x;
    }else{
        x = 1; y = 0;
    }
    return d;
}

long long mod_inv(long long a){
    long long x, y;
    extgcd(a, MOD, x, y);
    return (MOD + x%MOD) % MOD;
}

const int MAX = 1001;
long long dp[MAX][MAX];

int main(){
    long long i, j, k;
    long long N, A, B, C, D;
    cin >> N >> A >> B >> C >> D;

    create_mod_tables(N);

    dp[A-1][0] = 1;
    for(i=A; i<=B; i++){
        for(j=0; j<=N; j++){
            dp[i][j] = (dp[i][j] + dp[i-1][j]) % MOD;
            for(k=C; (k<=D && j+i*k<=N); k++){
                long long add = perm_mod(N-j, i*k) * power_mod(fimod[i], k) % MOD * fimod[k] % MOD;
                dp[i][j+i*k] = (dp[i][j+i*k] + add * dp[i-1][j] % MOD) % MOD;
            }
        }
    }
    cout << dp[B][N] << endl;
    return 0;
}