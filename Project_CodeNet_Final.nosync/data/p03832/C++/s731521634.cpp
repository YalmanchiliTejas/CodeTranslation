#include<bits/stdc++.h>
using namespace std;

const long long MOD = 1000000007LL;

int b, c, d;
long long memo[1001][1001];
vector<long long> fact, inv_fact;

long long power(long long _x, long long _n){
    long long res = 1;
    _x %= MOD;
    while(_n > 0LL){
        if(_n & 1LL){
            res *= _x;
            res %= MOD;
        }
        _x *= _x;
        _x %= MOD;
        _n >>= 1;
    }
    return res;
}

void initialize(int n){
    fill(memo[0], memo[n + 1], -1LL);

    fact.resize(n + 1);
    inv_fact.resize(n + 1);

    fact[0] = 1;
    inv_fact[0] = 1;
    for(long long i = 1 ; i <= n ; i++){
        fact[i] = (fact[i - 1] * i) % MOD;
        inv_fact[i] = power(fact[i], MOD - 2);
    }

    return;
}

inline long long perm(int n, int r){
    return fact[n] * inv_fact[n - r] % MOD;
}

// 残りn人で、今はa人組を作ろうとしている
long long rec(int n, int a){
    if(n == 0){
        return 1LL;
    }else if(n < 0 || a > b){
        return 0LL;
    }else if(memo[n][a] >= 0LL){
        return memo[n][a];
    }

    // a人組の数が0の場合
    long long res = rec(n, a + 1);

    // a人組をi組作る
    for(int i = c ; i <= d ; i++){
        if(a * i > n){
            break;
        }
        // このとき、遷移を nPa*i / (a!)^i / i! 倍する
        res += ((rec(n - a * i, a + 1) * perm(n, a * i) % MOD) * power(power(fact[a], i), MOD - 2) % MOD) * inv_fact[i] % MOD;
        res %= MOD;
    }

    return memo[n][a] = res;
}

int main(){
    int n, a;
    cin >> n >> a >> b >> c >> d;

    initialize(n);

    long long ans = rec(n, a);
    cout << ans << endl;

    return 0;
}