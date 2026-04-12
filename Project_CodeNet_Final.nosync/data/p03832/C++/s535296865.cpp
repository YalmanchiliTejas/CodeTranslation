#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>

using namespace std;

const int MAXN = 1e3 + 7, MOD = 1e9 + 7;

int fact[MAXN], invfact[MAXN], dp[MAXN], N, A, B, C, D;

int bpow(int a, int p)
{
    int ans = 1;
    for (; p > 0; p >>= 1) {
        if (p & 1) {
            ans = 1ll * ans * a % MOD;
        }
        a = 1ll * a * a % MOD;
    }
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    fact[0] = 1;
    for (int i = 1; i < MAXN; ++i) fact[i] = (1ll * fact[i - 1] * i) % MOD;
    invfact[MAXN - 1] = bpow(fact[MAXN - 1], MOD - 2);
    for (int i = MAXN - 1; i > 0; --i) invfact[i - 1] = 1ll * invfact[i] * i % MOD;

    dp[0] = 1;
    cin >> N >> A >> B >> C >> D;
    for (int x = A; x <= B; ++x) {
        for (int i = N; i >= x * C; --i) {
            for (int j = C; j <= D && j * x <= i; ++j) {
                long long add = dp[i - j * x];
                add = add * fact[N - (i - j * x)] % MOD;
                add = add * invfact[N - i] % MOD;
                add = add * bpow(invfact[x], j) % MOD;
                add = add * invfact[j] % MOD;
                dp[i] = ((dp[i] += add) >= MOD ? dp[i] - MOD : dp[i]);
            }
        }
    }

    cout << dp[N] << endl;
}
