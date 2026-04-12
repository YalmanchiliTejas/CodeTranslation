#include <bits/stdc++.h>
using namespace std;
using LL = long long;
//#define zerol
#define FOR(i, x, y) for (decay<decltype(y)>::type i = (x), _##i = (y); i < _##i; ++i)
#define FORD(i, x, y) for (decay<decltype(x)>::type i = (x), _##i = (y); i > _##i; --i)
#ifdef zerol
#define dbg(x...) do { cout  << #x << " -> "; err(x); } while (0)
void err() { cout <<  endl; }
template<template<typename...> class T, typename t, typename... A>
void err(T<t> a, A... x) { for (auto v: a) cout << v << ' '; err(x...); }
template<typename T, typename... A>
void err(T a, A... x) { cout << a << ' '; err(x...); }
#else
#define dbg(...)
#endif

const int MAXN = 1e3+5;
const LL MOD = 1e9+7;

vector<int> p;
bool nop[MAXN];

int n, a, b, c, d;

LL dp[MAXN];

int aa[MAXN*20], bb[MAXN*20];

LL C[MAXN][MAXN];

LL frac[MAXN];

LL bin(LL a, LL b, LL MOD) {
    LL res;
    for (res=1;b;a=a*a%MOD, b>>=1)
        if (b&1)
            res = res*a%MOD;
    return res;
}

LL get_inv(LL a, LL MOD) { return bin(a, MOD-2, MOD);}


LL calc(int m, int k, int i) {
    LL ans = 0;
    int ki = k * i;
    LL coff = frac[ki] * get_inv(bin(frac[i], k, MOD), MOD) %MOD * get_inv(frac[k], MOD) %MOD;
    if (min(m, ki) == 0) return coff;
    for (int i=0; i<=min(m, ki); ++i) {
        ans = (ans + C[m][i] * C[ki][i] % MOD) %MOD;
    }
    dbg(ans);
    ans = ans * coff %MOD;
    dbg(m, k, i, ki, ans);
    return ans;
}

LL test(int m, int ki) {
    LL ans = 0;
    for (int i=0; i<min(m, ki); ++i) {
        ans = (ans + C[m][i] * C[ki][i] % MOD) %MOD;

    }
    return ans;
}

LL finv[MAXN];

LL inv(int i) {
    return finv[i];
}

int main() {
    C[1][1] = 1;
    C[1][0] = 1;
    FOR (i, 2, MAXN) {
        C[i][0] = 1;
        FOR (j, 1, i+1) {
            C[i][j] = (C[i-1][j] + C[i-1][j-1]) % MOD;
        }
    }

    frac[0] = 1;
    FOR (i, 1, MAXN) frac[i] = frac[i-1] * i %MOD;
    finv[MAXN-1] = get_inv(frac[MAXN-1], MOD);
    FORD(i, MAXN-2, -1)
        finv[i] = finv[i+1] * (i+1)%MOD;

//    for (int i=1; i<=10; ++i) {
//    for (int j=1; j<=10; ++j) {
//        printf("%lld ", test(i, j));
//    }
//    putchar('\n');
//    }

    scanf("%d%d%d%d%d", &n, &a, &b, &c, &d);
    int cnt = 0;
    dp[0] = 1;
    FOR (i, a, b+1) {
        FORD (j, min(i*d, n), i*c-1) {
            FOR (k, c, d+1) {
                if (j-k*i >=0 && dp[j-k*i]) {
                    LL now = bin(inv(i), k, MOD);
                    LL M = j-k*i;
                    dp[j] = (dp[j] + frac[j]*now%MOD*inv(M)%MOD*dp[M]%MOD*inv(k)%MOD)%MOD;
//                    dp[j] = (dp[j] + dp[j-k*i]*frac[j]%MOD*bin(get_inv(frac[i], MOD), c, MOD)%MOD*get_inv(frac[j-k*i], MOD)%MOD*get_inv(frac[k], MOD)%MOD) % MOD;
                } else if (j-k*i<0) break;
            }
        }
    }

    cout << dp[n] << endl;


    return 0;
}
