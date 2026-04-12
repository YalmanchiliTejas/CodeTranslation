#include <cstdio>
typedef long long int64;
static const int MAXN = 1e3 + 3;
static const int MODULUS = 1e9 + 7;
#define _  %  MODULUS
#define __ %= MODULUS

int binom[MAXN][MAXN] = {{ 0 }};
int64 fact[MAXN], fact_inv[MAXN];

inline int64 fpow(int64 base, int exp)
{
    int64 ans = 1;
    for (; exp; exp >>= 1, (base *= base)__) if (exp & 1) (ans *= base)__;
    return ans;
}
inline void preprocess_binomials()
{
    binom[0][0] = 1;
    for (int i = 1; i < MAXN; ++i) {
        binom[i][0] = 1;
        for (int j = 1; j <= i; ++j)
            binom[i][j] = (binom[i - 1][j - 1] + binom[i - 1][j])_;
    }
    fact[0] = 1;
    for (int i = 1; i < MAXN; ++i) fact[i] = (fact[i - 1] * i)_;
    fact_inv[MAXN - 1] = fpow(fact[MAXN - 1], MODULUS - 2);
    for (int i = MAXN - 2; i >= 0; --i) fact_inv[i] = (fact_inv[i + 1] * (i + 1))_;
}
inline int64 group(int size, int groups)
{
    return fact[size * groups] * fpow(fact_inv[size], groups)_ * fact_inv[groups]_;
}

int n, a, b, c, d;
// f[size of group current considering][number of people assigned]
int64 f[MAXN][MAXN] = {{ 0 }};

int main()
{
    preprocess_binomials();
    scanf("%d%d%d%d%d", &n, &a, &b, &c, &d);

    f[a - 1][0] = 1;
    for (int s = a; s <= b; ++s) {
        for (int i = 0; i <= n; ++i) f[s][i] = f[s - 1][i];
        for (int i = 0; i <= n; ++i) {
            for (int j = i + c * s; j <= n && j <= i + d * s; j += s) {
                // binom[n - i][j - i]: ways to choose people to fit into group size s
                // group(s, (j - i) / s): ways to group (j - i) people into groups of size s
                (f[s][j] += f[s - 1][i] * binom[n - i][j - i]_ * group(s, (j - i) / s))__;
            }
        }
    }

    printf("%lld\n", f[b][n]);
    return 0;
}
