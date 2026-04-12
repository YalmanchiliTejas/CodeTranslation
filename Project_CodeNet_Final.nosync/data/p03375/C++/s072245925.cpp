#include <cstdio>

using namespace std;

long long c[3001][3001];
long long dp[3001][3001];

long long powmod(long long x, long long y, long long m) {
    long long ans = 1;
    
    while (y > 0) {
        if (y & 1) ans = ans * x % m;
        x = x * x % m;
        y >>= 1;
    }
    
    return ans;
}

int main() {
    int n, m, f = -1, i, j, k;
    long long ans;
    
    scanf("%d %d", &n, &m);
    
    for (i = 0; i <= n; i++) {
        c[i][0] = c[i][i] = 1;
        for (j = 1; j < i; j++) c[i][j] = (c[i - 1][j - 1] + c[i - 1][j]) % m;
    }
    
    ans = powmod(2, powmod(2, n, m - 1), m);
    
    for (i = 1; i <= n; i++) {
        for (j = 1; j <= i; j++) {
            if (j == 1) {
                dp[i][j] = powmod(2, i, m) - 1;
            } else {
                dp[i][j] = (j + 1) * dp[i - 1][j] + dp[i - 1][j - 1];
                dp[i][j] %= m;
            }
        }
    }
    
    for (i = 1; i <= n; i++, f *= -1) {
        long long x = 1, y = powmod(2, n - i, m);
        
        for (j = 1; j <= i; j++) {
            x += dp[i][j] * powmod(y, j, m) % m;
            if (x >= m) x -= m;
        }
        
        x = x * c[n][i] % m;
        x = x * powmod(2, powmod(2, n - i, m - 1), m) % m;
        
        ans += x * f;
        if (ans >= m) ans -= m;
        if (ans < 0) ans += m;
    }
    
    printf("%lld\n", ans);
    
    return 0;
}
