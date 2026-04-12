#include <cstdio>
#include <algorithm>
#include <vector>
#include <set>
#include <cstdlib>
#include <utility>
#include <cmath>
#include <queue>
#include <stack>
#include <cstring>

using namespace std;

#define ll long long

#ifndef ONLINE_JUDGE
#define debug(format, ...) fprintf(stderr, \
    "%s:%d: " format "\n", __func__, __LINE__,##__VA_ARGS__)
#else
#define debug(format, ...)
#define NDEBUG
#endif

#define DEFMOD(mod, type) typedef ModInt<mod, int> type;     \
                          type operator "" _m(unsigned long long x) {   \
                              type res = x; return res; \
                          }

const int siz = 32768;
int rev[40000];

template<int mod, class itype> struct ModInt {
    int val;
    ModInt() {
        val = 0;
    }
    ModInt(int a) {
        val = a % mod;
    }
};

/* MODIFY AS NEEDED */

DEFMOD(998244353, mi)

template<int mod, class itype> ModInt<mod, itype> fpow(ModInt<mod, itype> base, int exponent)
{
    ModInt<mod, itype> ans = 1_m;
    ModInt<mod, itype> cur = base;
    while (exponent) {
        if (exponent & 1) ans = ans * cur;
        cur = cur * cur; exponent >>= 1;
    }
    return ans;
}

template<int mod, class itype> ModInt<mod, itype> operator+(ModInt<mod, itype> a, ModInt<mod, itype> b)
{
    ModInt<mod, itype> ans;
    ll val = (ll)(a.val) + (ll)(b.val);
    if (val >= mod) val -= mod;
    ans.val = val; return ans;
}

template<int mod, class itype> ModInt<mod, itype> operator-(ModInt<mod, itype> a, ModInt<mod, itype> b)
{
    ModInt<mod, itype> ans;
    ans.val = a.val - b.val;
    if (ans.val < 0) ans.val += mod;
    return ans;
}

template<int mod, class itype> ModInt<mod, itype> operator*(ModInt<mod, itype> a, ModInt<mod, itype> b)
{
    ModInt<mod, itype> ans;
    ans.val = ((ll)(a.val) * (ll)(b.val)) % (ll)mod;
    return ans;
}

// PRIME MOD ONLY!
template<int mod, class itype> ModInt<mod, itype> operator/(ModInt<mod, itype> a, ModInt<mod, itype> b)
{
#ifndef ONLINE_JUDGE
    if (b.val == 0) {
        fprintf(stderr, "Division by zero :(\n"); abort();
    }
#endif
    return a * fpow(b, mod - 2);
}

void NTT(mi* poly, int op)
{
    for (int i = 0; i < siz; i++) {
        if (i < rev[i]) {
            mi tmp = poly[i]; poly[i] = poly[rev[i]]; poly[rev[i]] = tmp;
        }
    }
    for (int interval = 2; interval <= siz; interval <<= 1) {
        int half = interval >> 1;
        mi change = fpow(3_m, (998244353 - 1) / interval);
        if (op == -1) change = 1_m / change;
        for (int start = 0; start < siz; start += interval) {
            mi cur = 1;
            for (int i = start; i < start + half; i++) {
                mi tmp = cur * poly[i + half];
                poly[i + half] = poly[i] - tmp;
                poly[i] = poly[i] + tmp;
                cur = cur * change;
            }
        }
    }
    if (op == -1) {
        mi inv = 1_m / (mi)siz;
        for (int i = 0; i < siz; i++) poly[i] = poly[i] * inv;
    }
}

mi f[20][40005];
mi ans[40005];
char a[10005];
char b[10005];

mi fact[10005];
mi ifact[10005];

int n;

int main()
{
    for (int i = 1; i < siz; i++) {
        rev[i] = (i & 1) ? (siz>>1) | rev[i^1] : rev[i>>1]>>1;
    }
    fact[0] = 1_m;
    for (int i = 1; i <= 10002; i++) {
        fact[i] = (mi)i * fact[i-1];
    }

    ifact[10002] = 1_m / fact[10002];
    for (int i = 10001; i >= 0; i--) {
        ifact[i] = ifact[i+1] * (mi)(i+1);
    }

    scanf("%s", a + 1);
    scanf("%s", b + 1);
    n = strlen(a + 1);
    int one_zero_cnt = 0, one_one_cnt = 0;

    for (int i = 1; i <= n; i++) {
        if (a[i] == '1' && b[i] == '1') {
            one_one_cnt++;
        } else if (a[i] == '1' && b[i] == '0') {
            one_zero_cnt++;
        }
    }

    /*for (int i = 0; i <= one_one_cnt; i++) {
        f[0][i] = 1;
    }

    for (int i = 1; i <= one_zero_cnt; i++) {
        for (int j = 0; j <= one_one_cnt; j++) {
            for (int k = 0; k <= j; k++) {
                f[i][j] = f[i][j] + f[i-1][j-k] * ifact[k+1];
            }
        }
    }*/

    for (int i = 0; i <= one_one_cnt; i++) {
        f[0][i] = ifact[i+1];
    }

    for (int i = 1; i <= 15; i++) {
        NTT(f[i-1], 1);
        for (int j = 0; j < siz; j++) {
            f[i][j] = f[i-1][j] * f[i-1][j];
        }
        NTT(f[i], -1);
        for (int j = one_one_cnt + 1; j < siz; j++) {
            f[i][j] = 0;
        }
    }

    for (int i = 0; i <= one_one_cnt; i++) {
        ans[i] = 1_m;
    }

    for (int i = 0; i <= 15; i++) {
        if (one_zero_cnt & (1 << i)) {
            NTT(ans, 1);
            for (int j = 0; j < siz; j++) {
                ans[j] = ans[j] * f[i][j];
            }
            NTT(ans, -1);
            for (int j = one_one_cnt + 1; j < siz; j++) {
                ans[j] = 0_m;
            }
        }
    }

    mi final_ans = ans[one_one_cnt] * fact[one_one_cnt + one_zero_cnt] * fact[one_one_cnt] * fact[one_zero_cnt];
    printf("%d", final_ans.val);
    return 0;
}
