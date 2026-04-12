#include <stdio.h>
#include <string.h>

#define MOD 1000000007

struct mint {
    int n;
    mint(int n_ = 0) : n(n_) {}
};

mint operator+(mint a, mint b) { a.n += b.n; if (a.n >= MOD) a.n -= MOD; return a; }
mint operator-(mint a, mint b) { a.n -= b.n; if (a.n < 0) a.n += MOD; return a; }
mint operator*(mint a, mint b) { return (long long)a.n * b.n % MOD; }
mint &operator+=(mint &a, mint b) { return a = a + b; }
mint &operator-=(mint &a, mint b) { return a = a - b; }
mint &operator*=(mint &a, mint b) { return a = a * b; }

int N;
char K[10002];
int D;
mint dp[10001][2][100];

int main() {
    scanf("%s %d", K, &D);
    N = strlen(K);
    dp[0][0][0] = 1;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < 2; j++) {
            for (int k = 0; k < D; k++) {
                int x = j ? 9 : K[i] - '0';
                for (int d = 0; d <= x; d++) {
                    dp[i + 1][j || d < x][(k + d) % D] += dp[i][j][k];
                }
            }
        }
    }
    mint ans = dp[N][0][0] + dp[N][1][0] - 1;
    printf("%d\n", ans.n);
    return 0;
}
