#include <bits/stdc++.h>
using namespace std;
using Int = long long;
constexpr Int MOD = 1000000007;
Int modpow(Int x, Int y)
{
    if (y == 0) return 1;
    if (y % 2) return modpow(x, y-1) * x % MOD;
    return modpow(x*x % MOD, y/2);
}
Int modinv(Int x)
{
    return modpow(x, MOD-2);
}
Int modfact(Int x)
{
    Int ans = 1;
    for (int i = 1; i <= x; i++) (ans *= i) %= MOD;
    return ans;
}
Int fact[1001], dp[1001][1001];
int main()
{
    Int N, A, B, C, D; cin >> N >> A >> B >> C >> D;
    fact[0] = 1;
    for (int i = 1; i <= N; i++) fact[i] = fact[i-1] * i % MOD;
    for (int i = 0; i <= N; i++) dp[0][i] = 1;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            dp[i][j] = dp[i][j-1];
            if (A <= j && j <= B) {
                for (int k = C; k <= D && j*k <= i; k++) {
                    dp[i][j] += modinv(modpow(fact[j], k) * fact[k] % MOD) * dp[i-j*k][j-1];
                    dp[i][j] %= MOD;
                }
            }
        }
    }
    cout << fact[N] * dp[N][N] % MOD << '\n';
    return 0;
}