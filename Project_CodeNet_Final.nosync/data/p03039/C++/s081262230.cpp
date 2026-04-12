#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

static const int MAX = 510000;
static const int NIL = -1;
static const ll INF = 1<<21;
static const ll MOD = 1e9 + 7;

ll fac[MAX], finv[MAX], inv[MAX];

bool compPair(const pair<int, int>& arg1, const pair<int, int>& arg2) {
    return arg1.first > arg2.first;
}

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

ll COM(int n, int k){
    if (n < k) return 0;
    if (n < 0 || k < 0) return 0;
    return fac[n] * (finv[k] * finv[n - k] % MOD) % MOD;
}

int main(void) {
    ll N, M, K;
    cin >> N >> M >> K;

    COMinit();

    ll X=0, Y=0, addx, addy, ans;
    for(int d=1;d<N;d++) {
        addx = ((N-d)*M*M)%MOD;
        addx *= d%MOD;
        addx %= MOD;
        X += addx;
        X %= MOD;
    }

    for(int d=1;d<M;d++) {
        addy = ((M-d)*N*N)%MOD;
        addy *= d%MOD;
        addy %= MOD;
        Y += addy;
        Y %= MOD;
    }

    X *= COM(N*M-2, K-2);
    X %= MOD;
    Y *= COM(N*M-2, K-2);
    Y %= MOD;

    ans = X + Y;
    ans %= MOD;

    cout << ans << endl;
    
    return (0);
}
