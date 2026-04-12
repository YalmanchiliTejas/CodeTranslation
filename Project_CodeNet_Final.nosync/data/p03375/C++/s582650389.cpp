#include <cstring>
#include <iostream>
using namespace std;

long long modexp(int x, long long e, int m) {
    long long ans = 1, p = x % m;
    while (e > 0) {
        if (e % 2 != 0) ans = (ans * p) % m;
        p = (p * p) % m;
        e >>= 1;
    }
    return ans;
}

long long comb[3001][3001], h[3001][3001];

int main() {
    int N, M; cin >> N >> M;
    for (int i = 0; i <= N; i++) {
        comb[i][0] = 1;
        for (int j = 1; j <= i; j++) {
            comb[i][j] = (comb[i-1][j-1] + comb[i-1][j]) % M;
        }
    }
    h[0][0] = 1;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j <= i; j++) {
            (h[i+1][j+1] += h[i][j]) %= M;
            (h[i+1][j] += (j + 1) * h[i][j] % M) %= M;
        }
    }

    long long f[N+1];
    for (int k = 1; k <= N; k++) {
        long long val = 0;
        for (int j = 0; j <= k; j++) {
            val += h[k][j] * modexp(2, (N-k) * j, M) % M;
        }
        f[k] = val % M * modexp(2, modexp(2, N-k, M-1), M);
    }
    long long g[N+1];
    for (int k = 1; k <= N; k++) {
        long long val = 0;
        for (int j = k; j <= N; j++) {
            const int sign = (j - k) % 2 == 0 ? 1 : -1;
            val += sign * f[j] % M * comb[N-k][j-k] % M;
        }
        g[k] = val % M;
    }
    long long ans = modexp(2, modexp(2, N, M-1), M);
    for (int k = 1; k <= N; k++) ans -= g[k] * comb[N][k] % M;
    cout << (ans % M + M) % M << endl;
}
