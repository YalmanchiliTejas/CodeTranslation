#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int MAX_N = 2e5 + 10;
const ll MOD = 1e9 + 7;

int N, M, K;
bool S[MAX_N];

void init() {
    scanf("%d%d", &N, &M);
    static char _S[MAX_N];
    scanf("%s", _S + 1);
    for (int i = 1; i <= M; i++) S[i] = _S[i] == 'R';
    for (int i = M; i; i--) S[i] ^= S[1];
    K = N | 1;
    int curr = 0;
    bool first = true;
    for (int i = 1; i <= M; i++) {
        if (S[i]) {
            if (curr & 1) {
                K = min(K, curr);
            } else {
                if (first) K = min(K, curr + 1);
            }
            first = false;
            curr = 0;
        } else curr++;
    }
    if (first) {
        static ll fib[MAX_N];
        fib[1] = fib[2] = 1;
        for (int i = 3; i <= N + 1; i++) (fib[i] = fib[i - 1] + fib[i - 2]) %= MOD;
        ll ans = (2 * fib[N + 1] - fib[N] + MOD) % MOD;
        printf("%lld\n", ans);
        exit(0);
    }
}

ll f[MAX_N], pre[MAX_N];
void solve() {
    f[0] = pre[0] = 1;
    for (int i = 1; i <= N; i++) {
        f[i] = ((i - 2 >= 0 ? pre[i - 2] : 0) - (i - K - 3 >= 0 ? pre[i - K - 3] : 0) + MOD) % MOD;
        pre[i] = (i >= 2 ? pre[i - 2] + f[i] : f[i]) % MOD;
    }
    ll ans = 0;
    for (int i = 1; i <= min(K + 1, N); i++) {
        int l = N - (K + 1), r = N - (i + (i & 1));
        (ans += pre[r] - (l - 2 >= 0 ? pre[l - 2] : 0) + MOD) %= MOD;
    }
    printf("%lld\n", ans);
}

int main() {
    init();
    solve();
}
