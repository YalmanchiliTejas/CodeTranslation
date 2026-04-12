#include <bits/stdc++.h>
using namespace std;

#define mod 1000000007
#define MAX_N 200010
long long inv[MAX_N];
long long factorial[MAX_N];
long long inv_factorial[MAX_N];

void GetInv(){
    for (int i = 1; i < MAX_N; i++) {
        if (i == 1) inv[i] = 1;
        else {
            inv[i] = (mod - (mod / i) * inv[mod % i]) % mod;
            if (inv[i] < 0) inv[i] += mod;
        }
    }
}
void GetFactorial(){
    factorial[0] = 1; inv_factorial[0] = 1;
    for (int i = 1; i < MAX_N; i++) {
        factorial[i] = factorial[i-1] * i;
        factorial[i] %= mod;
        inv_factorial[i] = inv_factorial[i-1] * inv[i];
        inv_factorial[i] %= mod;
    }
}

long long combination(int n, int r) {
    long long ret = factorial[n] * inv_factorial[r];
    ret %= mod;
    ret *= inv_factorial[n-r];
    return ret % mod;
}

long long dp[1010][1010];

int main() {
    GetInv(); GetFactorial();
    int n, a, b, c, d;
    cin >> n >> a >> b >> c >> d;
    memset(dp, 0, sizeof(dp));
    dp[0][a-1] = 1;
    for (int j = a; j <= b; j++) {
        for (int i = 0; i <= n; i++) {
            // dp[i][j]
            long long mul = 1;
            for (int k = 0; k <= n; k++) {
                if (k == 0) {
                    dp[i][j] = (dp[i][j] + dp[i][j-1]) % mod;
                }
                if (k >= c && k <= d) {
                    long long tmp = mul * inv_factorial[k] % mod;
                    dp[i+j*k][j] += tmp * dp[i][j-1] % mod;
                    dp[i+j*k][j] %= mod;
                }
                if (k == d) break;
                if (n-i-j*k < j) break;
                mul = mul * combination(n-i-j*k, j) % mod;
            }
        }
    }
    cout << dp[n][b] << endl;
    return 0;
}