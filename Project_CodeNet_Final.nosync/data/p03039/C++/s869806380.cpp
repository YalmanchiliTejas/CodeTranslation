#include <bits/stdc++.h>
using namespace std;

const int64_t MOD = 1e9+7;
void add(int64_t& a, int64_t b){
    a = (a+b) % MOD;
}
void mul(int64_t& a, int64_t b){
    a = a*b % MOD;
}

vector<int64_t> fact, seq_inv, fact_inv;

void create_fact_mod(int num){
    fact[0] = 1;
    fact[1] = 1;
    for(int i=2; i<=num; i++){
        fact[i] = fact[i-1] * i % MOD;
    }
}

void create_seq_inv_mod(int num){
    seq_inv[0] = 1;
    seq_inv[1] = 1;
    for(int i=2; i<=num; i++){
        seq_inv[i] = (MOD - MOD/i) * seq_inv[MOD%i] % MOD;
    }
}

void create_fact_inv_mod(int num){
    fact_inv[0] = 1;
    fact_inv[1] = 1;
    for(int i=2; i<=num; i++){
        fact_inv[i] = fact_inv[i-1] * seq_inv[i] % MOD;
    }
}

void create_mod_tables(int num){
    fact.resize(num+1);
    seq_inv.resize(num+1);
    fact_inv.resize(num+1);
    create_fact_mod(num);
    create_seq_inv_mod(num);
    create_fact_inv_mod(num);
}

int64_t comb_mod(int n, int k){
    return fact[n] * fact_inv[n-k] % MOD * fact_inv[k] % MOD;
}

int64_t perm_mod(int n, int k){
    return fact[n] * fact_inv[n-k] % MOD;
}

int main(){
    int64_t N, M, K;
    cin >> N >> M >> K;
    int64_t A = N*M;

    int64_t ans = 0;
    for(int t=0; t<2; t++){
        int64_t res = 0;
        for(int d=1; d<N; d++) add(res, d*(N-d));
        mul(res, M*M % MOD);
        add(ans, res);
        swap(N, M);
    }
    
    create_mod_tables(A);
    mul(ans, comb_mod(A-2, K-2));
    cout << ans << endl;
    return 0;
}
