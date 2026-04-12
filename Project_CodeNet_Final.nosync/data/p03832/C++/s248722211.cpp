#include<bits/stdc++.h>
using namespace std;

const int mod = 1e9 + 7;
const int MN = 1010;

int exp(int x, int n) {
    int ret = 1;
    while(n) {
        if(n & 1) ret = 1LL * ret * x % mod;
        x = 1LL * x * x % mod;
        n >>= 1;
    }
    return ret;
}
int inv(int x) {
    return exp(x, mod - 2);
}
int comb[MN][MN], fact[MN], invf[MN];

int N, A, B, C, D;

int cc[MN][MN];
int dp(int m, int n) {
    if(m == B + 1) return n == 0;
    int &ret = cc[m][n];
    if(ret != -1) return ret;

    ret = dp(m + 1, n);
    int tmp = 1;
    for(int i = 1; i <= min(n / m, D); i++) {
        tmp = 1LL * tmp * comb[n - (i - 1) * m][m] % mod;
        if(i >= C) {
            ret += 1LL * tmp * invf[i] % mod * dp(m + 1, n - i * m) % mod;
            ret %= mod;
        }
    }
    return ret;
}

int main() {
    for(int i = 0; i < MN; i++) {
        comb[i][0] = 1;
        for(int j = 1; j <= i; j++) {
            comb[i][j] = (comb[i - 1][j - 1] + comb[i - 1][j]) % mod;
        }
    }
    fact[0] = 1;
    for(int i = 1; i < MN; i++) {
        fact[i] = 1LL * fact[i - 1] * i % mod;
    }
    for(int i = 0; i < MN; i++) {
        invf[i] = inv(fact[i]);
    }

    cin >> N >> A >> B >> C >> D;

    memset(cc, -1, sizeof(cc));
    cout << dp(A, N);
}
