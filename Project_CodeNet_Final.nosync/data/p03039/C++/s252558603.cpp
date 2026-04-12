#include <bits/stdc++.h>

using namespace std;

const int MAX_N = 2e5 + 5;
const long long MOD = 1e9 + 7;

typedef long long ll;

int N, M, K;
ll fact[MAX_N], invf[MAX_N];
ll ans = 0;

ll qexp(ll A, ll B) {
    if (B == 0) return 1;
    ll half = qexp(A, B / 2);
    (half *= half) %= MOD;
    if (B % 2) (half *= A) %= MOD;
    return half;
}

void precompute() {
    fact[0] = invf[0] = 1;
    for (int i = 1; i < MAX_N; i++) {
		fact[i] = fact[i - 1] * i % MOD;
		invf[i] = qexp(fact[i], MOD - 2);
	}
}

ll nCk(int n, int k) {
    if (k < 0 || k > n) return 0;
	return fact[n] * invf[k] % MOD * invf[n - k] % MOD;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    precompute();
    cin >> N >> M >> K;
    for (int i = 1; i <= N; i++) {
        int cur = (i - 1) - (N - i);
        (ans += 1LL * M * M % MOD * i % MOD * cur % MOD) %= MOD;
    }
    for (int i = 1; i <= M; i++) {
        int cur = (i - 1) - (M - i);
        (ans += 1LL * N * N % MOD * i % MOD * cur % MOD) %= MOD;
    }
    cout << (ans * nCk(N * M - 2, K - 2) % MOD);
}

