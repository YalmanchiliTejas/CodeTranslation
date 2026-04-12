#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
LL way[3003], way2[3003][3003];
LL C[3003][3003], f[3003][3003];

LL qpow(LL a, LL b, LL mod) {
    LL ret = 1LL;
    while (b) {
        if (b & 1) ret = ret * a % mod;
        a = a * a % mod;
        b >>= 1;
    }
    return ret;
}

LL pow_mod[3003], pow_mod_1[3003];
int main() {
    LL N, mod;
    scanf("%lld %lld", &N, &mod);
    pow_mod[0] = pow_mod_1[0] = 1;
    for(int i = 1; i < 3003; ++i) pow_mod[i] = pow_mod[i-1] * 2 % mod;
    for(int i = 1; i < 3003; ++i) pow_mod_1[i] = pow_mod_1[i-1] * 2 % (mod - 1);

    for (int i = 0; i < 3003; ++i) C[i][0] = C[i][i] = 1;
    for (int i = 2; i < 3003; ++i)
        for (int j = 1; j < i; ++j)
            C[i][j] = (C[i - 1][j - 1] + C[i - 1][j]) % mod;

    f[0][0] = f[1][0] = f[1][1] = 1;
    for (int i = 2; i <= N; ++i) {
        f[i][0] = 1;
        for (int j = 1; j <= N; ++j) {
            f[i][j] = (f[i - 1][j] + f[i - 1][j] * j + f[i - 1][j - 1]) % mod;
        }
    }

    for (int i = 0; i <= N; ++i) {
        for (int j = 0; j <= i; ++j) {
            way2[i][j] = f[i][j] * qpow(pow_mod[N - i], j, mod) % mod * qpow(2, pow_mod_1[N - i], mod) % mod;
            way[i] = (way[i] + way2[i][j]) % mod;
        }
    }

    LL ans = 0;
    for(int i = 0; i <= N; ++i){
        if(i % 2 == 0) ans = (ans + C[N][i] * way[i]) % mod;
        else ans = (ans - C[N][i] * way[i] % mod + mod) % mod;
    }
    printf("%lld\n", ans);
    return 0;
}