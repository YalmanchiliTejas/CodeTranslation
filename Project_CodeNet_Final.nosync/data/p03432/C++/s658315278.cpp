#include <cstdio>
#include <cstring>
#include <iostream>

#define Dec(x) (x >= mod ? x -= mod : 0)
#define Inc(x) (x < 0 ? x += mod : 0)
#define log2(x) (31 - __builtin_clz(x))

using namespace std;

typedef long long LL;

const int maxN = 8e3 + 5;
const int maxM = 205;
const int mod = 998244353;

int n, m;
int fac[maxN], ifac[maxN];
int f[maxN], g[maxN * 2], h[maxN];

int FPM(int bas, int ind)
{
    int res = 1;
    while (ind)
    {
        if (ind & 1)
            res = (LL)res * bas % mod;
        bas = (LL)bas * bas % mod;
        ind >>= 1;
    }
    return res;
}

namespace NTT
{
    const int maxN = 1 << (log2(::maxN) + 2) | 1;

    int omg[maxN], rev[maxN];

    void NTT(int* arr, int lim, int fg)
    {
        for (int i = 1; i < lim; ++i)
            if (rev[i] < i)
                swap(arr[i], arr[rev[i]]);
        for (int t = 2; t <= lim; t <<= 1)
        {
            int m = t >> 1, coe = lim / t;
            for (int* p = arr; p != arr + lim; p += t)
                for (int k = 0; k < m; ++k)
                {
                    int tmp = LL(fg == 1 ? omg[coe * k] : omg[lim - coe * k]) * p[k + m] % mod;
                    p[k + m] = p[k] - tmp, Inc(p[k + m]);
                    p[k] += tmp, Dec(p[k]);
                }
        }
        if (fg == -1)
        {
            int invlim = FPM(lim, mod - 2);
            for (int i = 0; i < lim; ++i)
                arr[i] = (LL)arr[i] * invlim % mod;
        }
    }

    void Mul(const int* A, int n, const int* B, int m, int* C)
    {
        static int _A[maxN], _B[maxN];

        int lim = 1 << (log2(n + m) + 1);
        memcpy(_A, A, n * sizeof(int));
        memcpy(_B, B, m * sizeof(int));
        memset(_A + n, 0, (lim - n) * sizeof(int));
        memset(_B + m, 0, (lim - m) * sizeof(int));
        NTT(_A, lim, 1), NTT(_B, lim, 1);
        for (int i = 0; i < lim; ++i)
            _A[i] = (LL)_A[i] * _B[i] % mod;
        NTT(_A, lim, -1);
        memcpy(C, _A, (n + m - 1) * sizeof(int));
        // cout << "Mul two arrays:" << endl;
        // for (int i = 0; i < n; ++i)
        //     cout << A[i] << ' ';
        // cout << endl;
        // for (int i = 0; i < m; ++i)
        //     cout << B[i] << ' ';
        // cout << endl;
        // cout << "Get C:" << endl;
        // for (int i = 0; i < (n + m) - 1; ++i)
        //     cout << C[i] << ' ';
        // cout << endl;
    }

    void Init(int n, int m)
    {
        int lim = 1 << (log2(n + m) + 1);
        for (int i = 1, bit = log2(lim); i < lim; ++i)
            rev[i] = rev[i >> 1] >> 1 | (i & 1) << (bit - 1);
        omg[0] = omg[lim] = 1;
        omg[1] = FPM(3, (mod - 1) / lim);
        for (int i = 2; i < lim; ++i)
            omg[i] = (LL)omg[i - 1] * omg[1] % mod;
    }
}

inline int C(int _n, int _m)
{
    if (_n < 0 or _m < 0 or _n < _m)
        return 0;
    return (LL)fac[_n] * ifac[_m] % mod * ifac[_n - _m] % mod;
}

int main()
{
    ios::sync_with_stdio(false);
    cin >> n >> m;
    f[0] = 1;
    fac[0] = ifac[0] = 1;
    for (int i = 1; i <= n + 2; ++i)
        fac[i] = (LL)fac[i - 1] * i % mod;
    ifac[n + 2] = FPM(fac[n + 2], mod - 2);
    for (int i = n + 1; i; --i)
        ifac[i] = ifac[i + 1] * LL(i + 1) % mod;

    NTT::Init(n + 1, n + 1);
    for (int o = 1; o <= m; ++o)
    {
        for (int i = 0; i <= n; ++i)
            g[i] = (LL)f[i] * ifac[i] % mod;
        memcpy(h, ifac + 2, (n + 1) * sizeof(int));
        NTT::Mul(g, n + 1, h, n + 1, g);
        for (int i = 1; i <= n; ++i)
        {
            int tmp = f[i];
            f[i] = g[i] - (LL)f[i] * ifac[i] % mod * ((mod + 1) >> 1) % mod;
            f[i] = (LL)f[i] * fac[i + 2] % mod;
            f[i] += tmp * (i * LL(i + 1) * ((mod + 1) >> 1) % mod + 1) % mod;
            Inc(f[i]), Dec(f[i]);
        }
    }
    int ans = 0;
    for (int i = 0; i <= n; ++i)
        ans += (LL)f[i] * C(n, i) % mod, Dec(ans);
    cout << ans << endl;
    return 0;
}