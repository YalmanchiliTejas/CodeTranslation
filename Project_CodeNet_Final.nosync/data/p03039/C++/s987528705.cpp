#include<bits/stdc++.h>
using namespace std;
#define rep(i,N) for(int (i)=0;(i) < (N); (i)++)
#define all(V) V.begin(), V.end()
using i64 = int_fast64_t;
using P = pair<int,int>;

const int MAX = 510000;
const i64 MOD = 1000000007;

i64 fac[MAX], finv[MAX], inv[MAX];
void comb_init() {
    fac[0] = fac[1] = 1;
    finv[0] = finv[1] = 1;
    inv[1] = 1;
    for (int i = 2; i < MAX; i++){
        fac[i] = fac[i - 1] * i % MOD;
        inv[i] = MOD - inv[MOD%i] * (MOD / i) % MOD;
        finv[i] = finv[i - 1] * inv[i] % MOD;
    }
}

i64 comb(int n, int k){
    if (n < k) return 0;
    if (n < 0 || k < 0) return 0;
    return fac[n] * (finv[k] * finv[n - k] % MOD) % MOD;
}

int main(){
    i64 N, M, K;
    cin >> N >> M >> K;

    i64 cost = 0;
    for(int d = 1; d < N; d++) cost = (cost + d*(N-d) % MOD * M % MOD * M)  % MOD;
    for(int d = 1; d < M; d++) cost = (cost + d*(M-d) % MOD * N % MOD * N) % MOD;

    comb_init();
    cout << (cost * comb(N*M-2, K-2)) % MOD << endl;
}
