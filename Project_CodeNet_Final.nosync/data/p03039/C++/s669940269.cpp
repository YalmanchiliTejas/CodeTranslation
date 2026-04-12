#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<cmath>
#include<cstdio>
#include<set>

using namespace std;

#define rep(i, n) for(int i = 0; i < n; i++)
#define repn(i, n) for(int i = 1; i <= n; i++) 
#define lint long long

const int MAX = 200000;
const long long MOD = 1000000007;
long long fac[MAX], facinv[MAX], inv[MAX];

// MOD の階乗、Permutation、Combinationなどを求めるための初期化
void facinit(){
    fac[0] = fac[1] = 1;
    facinv[0] = facinv[1] = 1;
    inv[1] = 1;
    for (int i = 2; i < MAX; i++){
        fac[i] = fac[i - 1] * i % MOD;
        inv[i] = MOD - inv[MOD % i] * (MOD / i) % MOD;
        facinv[i] = facinv[i - 1] * inv[i] % MOD;
    }   
}

// MOD のPermutation
long long Perm(long long a, long long b){
    if (a < b) return 0;
    if (a < 0 || b < 0) return 0;
    return fac[a] * facinv[a - b] % MOD;
}

// MOD のCombination
long long Combi(long long a, long long b){
    if (a < b) return 0;
    if (a < 0 || b < 0) return 0;
    return fac[a] * (facinv[b] * facinv[a - b] % MOD) % MOD;
}

int main(){
    facinit();
    lint N, M, K; cin>>N>>M>>K;
    lint ans = (((N-1)*N*(N+1) / 6) % MOD) * M*M % MOD;
    ans += (((M-1)*M*(M+1) / 6)%MOD) * N*N % MOD;
    ans = (ans * Combi(N*M-2, K-2)) % MOD;
    cout << ans << endl;
}