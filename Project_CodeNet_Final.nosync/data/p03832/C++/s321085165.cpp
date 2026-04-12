#include <iostream>
#include <vector>

using namespace std;
constexpr int64_t MOD = 1'000'000'007;
constexpr int     MAX =         1'005;

int64_t fac[MAX], finv[MAX], inv[MAX];

// テーブルを作る前処理
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

int main(void) {
    int N, A, B, C, D;
    cin >> N >> A >> B >> C >> D;
    COMinit();

    vector<int64_t> v(N+1);
    v[N] = fac[N];
    for(int i=B; i>=A; i--) {
        for(int j=0; j<=N; j++) {
            int64_t tmp = 1;
            for(int k=1; k<=D; k++) {
                int next = j - k*i;
                tmp *= finv[i];
                tmp %= MOD;
                if(next < 0) break;
                if(k < C) continue;
                v[next] += (v[j] * tmp) % MOD * finv[k] % MOD;
                v[next] %= MOD;
            }
        }
    }

    cout << v[0] << endl;
    return 0;
}
