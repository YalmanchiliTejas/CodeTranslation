#include<bits/stdc++.h>
using namespace std;

const int mod = 998244353;

int po(int x, int n) {
    int ret = 1;
    while(n) {
        if(n & 1) ret = 1LL * ret * x % mod;
        x = 1LL * x * x % mod;
        n >>= 1;
    }
    return ret;
}
int inv(int x) { return po(x, mod - 2); }
int fact[10002], invf[10002];

int comb(int n, int k) {
    return 1LL * fact[n] * invf[k] % mod * invf[n - k] % mod;
}

string A, B;
int m, e;
int dp[10002][10002];

int main() {
    fact[0] = 1;
    for(int i = 1; i < 10002; i++) {
        fact[i] = 1LL * fact[i - 1] * i % mod;
    }
    for(int i = 0; i < 10002; i++) {
        invf[i] = inv(fact[i]);
    }

    cin >> A >> B;

    m = 0, e = 0;
    for(int i = 0; i < A.size(); i++) {
        if(A[i] == '1' && B[i] == '1') m++;
        else if(A[i] == '1') e++;
    }

    for(int i = 0; i <= m; i++) {
        for(int j = 0; j <= e; j++) {
            if(i == 0 && j == 0) {
                dp[i][j] = 1;
                continue;
            }
            if(i && j) {
                dp[i][j] += 1LL * i * j % mod * dp[i - 1][j] % mod;
                dp[i][j] %= mod;
            }
            if(j) {
                dp[i][j] += 1LL * j * j % mod * dp[i][j - 1] % mod;
                dp[i][j] %= mod;
            }
        }
    }
    int ans = 0;
    for(int i = 0; i <= m; i++) {
        ans += 1LL * comb(m, i) * comb(m + e, i) % mod * fact[i] % mod * fact[i] % mod * dp[m - i][e] % mod;
        ans %= mod;
    }
    cout << ans;
}
