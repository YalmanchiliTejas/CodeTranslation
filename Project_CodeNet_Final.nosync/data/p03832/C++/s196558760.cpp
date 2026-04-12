#include <bits/stdc++.h>
using namespace std;
constexpr long long mod = 1e9+7;

const int maxN = 1005;
vector<long long> fac(maxN + 1, 1);
vector<long long> invfac(maxN + 1, 1);

long long pow_mod(long long b, long long p, long long mod = 1'000'000'007){
    long long ret = 1;
    while (p){
        if (p & 1) ret = (ret * b) % mod;
        b = (b * b) % mod;
        p >>= 1;
    }
    return ret;
}

void init_facs(){
    for (long long i = 1; i <= maxN; ++i) fac[i] = (fac[i - 1] * i) % mod;
    invfac[maxN] = pow_mod(fac[maxN], mod - 2, mod);
    for (long long i = maxN; i != 1; --i) invfac[i - 1] = (invfac[i] * i) % mod;
}

long long solve(int N, int A, int B, int C, int D){
    vector<vector<long long>> dp(B + 1, vector<long long>(N + 1, 0));
    dp[A - 1][0] = 1;
    for (int k = A; k <= B; ++k){
        dp[k][0] = 1;
        for (int n = 1; n <= N; ++n){
            long long fkm = pow_mod(invfac[k], C);
            for (int m = C; m <= D and n - k * m >= 0; ++m){
                int r = n - k * m;
                dp[k][n] = (dp[k][n] + (dp[k - 1][r] * fac[N - r] % mod * fkm % mod * invfac[m] % mod)) % mod;
                fkm = fkm * invfac[k] % mod;
            }
            dp[k][n] = dp[k][n] * invfac[N - n] % mod;
            dp[k][n] = (dp[k][n] + dp[k - 1][n]) % mod;
        }
    }
    return dp[B][N];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    init_facs();
    int N, A, B, C, D;
    cin >> N >> A >> B >> C >> D;
    cout << solve(N, A, B, C, D) << endl;
    return 0;
}