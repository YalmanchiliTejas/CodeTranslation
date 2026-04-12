#include <bits/stdc++.h>
using namespace std;

const int64_t MOD = 1e9+7;
void add(int64_t& a, int64_t b){
    a = (a+b) % MOD;
}
void mul(int64_t& a, int64_t b){
    a = a*b % MOD;
}

int64_t power_mod(int64_t num, int64_t power){
    int64_t prod = 1;
    num %= MOD;
    while(power > 0){
        if(power&1) prod = prod * num % MOD;
        num = num * num % MOD;
        power >>= 1;
    }
    return prod;
}

int64_t extgcd(int64_t a, int64_t b, int64_t& x, int64_t& y){
    int64_t d = a;
    if(b != 0){
        d = extgcd(b, a%b, y, x);
        y -= (a/b) * x;
    }else{
        x = 1; y = 0;
    }
    return d;
}

int64_t inv_mod(int64_t a){
    int64_t x, y;
    extgcd(a, MOD, x, y);
    return (MOD + x%MOD) % MOD;
}

vector<int64_t> fact, fact_inv;

void create_mod_tables(int num){
    fact.assign(num+1, 1);
    fact_inv.assign(num+1, 1);
    for(int i=1; i<=num; i++) fact[i] = fact[i-1] * i % MOD;
    fact_inv[num] = inv_mod(fact[num]);
    for(int i=num; i>0; i--) fact_inv[i-1] = fact_inv[i] * i % MOD;
}

int64_t comb_mod(int n, int k){
    return fact[n] * fact_inv[n-k] % MOD * fact_inv[k] % MOD;
}

int64_t perm_mod(int n, int k){
    return fact[n] * fact_inv[n-k] % MOD;
}

int64_t gcd(int64_t a, int64_t b){
    return b==0 ? a : gcd(b, a%b);
}

int main(){
    int H, W;
    cin >> H >> W;
    int N = (H+1)*(W+1);
    create_mod_tables(N);

    // 1直線に並ぶ3点を数える
    int64_t L = 0;
    
    // 両端のxとyの距離を全探索
    for(int i=0; i<=H; i++) for(int j=0; j<=W; j++){
        if(i == 0 && j == 0) continue;
        
        // 両端の取り方、i > 0 かつ j > 0 のときは反転も考慮
        int64_t res = (H+1-i) * (W+1-j);
        if(i > 0 && j > 0) mul(res, 2);
        // 間に取れる格子点の個数
        mul(res, gcd(i, j)-1);

        add(L, res);
    }

    // 1直線に並ばない3点
    int64_t ans = comb_mod(N, 3) - L + MOD;
    // 集合の選び方
    mul(ans, power_mod(2, N-3));

    cout << ans << endl;
    return 0;
}

