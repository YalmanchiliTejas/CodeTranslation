#include <bits/stdc++.h>
using namespace std;

const int MAX = 210000;
const int MOD = 1000000007;

long long fac[MAX], finv[MAX], inv[MAX];

void COMinit() {
    fac[0] = fac[1] = 1;
    finv[0] = finv[1] = 1;
    inv[1] = 1;
    for (int i = 2; i < MAX; i++){
        fac[i] = fac[i - 1] * i % MOD;
        inv[i] = MOD - inv[MOD%i] * (MOD / i) % MOD;
        finv[i] = finv[i - 1] * inv[i] % MOD;
    }
}

long long COM(int n, int k){
    if (n < k) return 0;
    if (n < 0 || k < 0) return 0;
    return fac[n] * (finv[k] * finv[n - k] % MOD) % MOD;
}

int main() {
    int N, M, K;
    cin >> N >> M >> K;

    COMinit();
    long long res = 0;
    long long com = COM(N * M - 2, K - 2);
    for(int d=1; d<N; ++d) {
        res += com * d * (N - d) * M * M % MOD;
        res %= MOD;
    }
    for(int d=1; d<M; ++d) {
        res += com * d * (M - d) * N * N % MOD;
        res %= MOD;
    }
    cout << res << endl;
}