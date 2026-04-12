#include <cstdio>

using namespace std;

const int m = 1000000007;
long long C[1001][1001];
long long dp[1001];
long long inv[1001];
long long fact[1001];
long long invfact[1001];

void calc_inv(int n, int mod) {
    inv[1] = 1;
    for (int i = 2; i <= n; i++) inv[i] = inv[mod % i] * (mod - mod / i) % mod;
    
    fact[0] = invfact[0] = 1;
    for (int i = 1; i <= n; i++) fact[i] = fact[i - 1] * i % mod;
    for (int i = 1; i <= n; i++) invfact[i] = invfact[i - 1] * inv[i] % mod;
}

int main() {
    int n, a, b, c, d, i, j, k;
    
    scanf("%d %d %d %d %d", &n, &a, &b, &c, &d);
    
    for (i = 0; i <= 1000; i++) {
        C[i][0] = C[i][i] = 1;
        
        for (j = 1; j < i; j++) C[i][j] = (C[i - 1][j - 1] + C[i - 1][j]) % m;
    }
    
    calc_inv(1000, m);
    
    dp[n] = 1;
    
    for (i = a; i <= b; i++) {
        for (j = 0; j <= n; j++) {
            int p = j;
            long long sum = 1;
            
            if (dp[j] == 0) continue;
            
            if (i * c > j) continue;
            
            for (k = 1; k < c; k++) {
                sum = sum * C[p][i] % m;
                p -= i;
            }
            
            for (k = c; k <= d; k++) {
                if (i * k > j) break;
                
                sum = sum * C[p][i] % m;
                p -= i;
                
                dp[j - i * k] += dp[j] * sum % m * invfact[k] % m;
                if (dp[j - i * k] >= m) dp[j - i * k] -= m;
            }
        }
    }
    
    printf("%lld\n", dp[0]);
    
    return 0;
}
