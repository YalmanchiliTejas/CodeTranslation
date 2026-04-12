#include <iostream>

#define long long long

using namespace std;

// element of ring of integers modulo mod
template<int mod>
struct RingMod {
    int val;
    RingMod(): val(0) {}
    RingMod(long x)
    {
        if (x < 0) x += mod;
        if (x >= mod) x -= mod;
        if (x >= mod) x %= mod;
        val = x;
    }
    explicit operator int() { return val; }
    RingMod operator + (const RingMod& b) const { return RingMod(val + b.val); }
    RingMod operator - (const RingMod& b) const { return RingMod(val - b.val); }
    RingMod operator * (const RingMod& b) const { return RingMod((long) val * b.val); }
};

template<int mod>
RingMod<mod> pow(RingMod<mod> a, long n)
{
    RingMod<mod> t = 1;
    for (; n > 0; n >>= 1) {
        if (n & 1) t = t * a;
        a = a * a;
    }
    return t;
}

typedef RingMod<1'000'000'007> int_mod;

const int N = 2e5 + 2;

int_mod ft[N], invft[N];

int_mod C(int k, int n) { return ft[n] * invft[k] * invft[n - k]; }

int main()
{
    int n, m, k;
    cin >> n >> m >> k;

    ft[0] = 1;
    for (int i = 1; i <= m * n; ++i)
        ft[i] = ft[i - 1] * i;
    invft[m * n] = pow(ft[m * n], 1'000'000'007 - 2);
    for (int i = m * n - 1; i >= 0; --i)
        invft[i] = invft[i + 1] * (i + 1);

    int_mod ans = 0;
    for (int i = 0; i < m; ++i) {
        ans = ans + int_mod(i) * (int_mod(i) * 2 - m + 1) * n * n * C(k - 2, m * n - 2);
    }

    for (int i = 0; i < n; ++i) {
        ans = ans + int_mod(i) * (int_mod(i) * 2 - n + 1) * m * m * C(k - 2, m * n - 2);
    }

    cout << (int) ans;
    return 0;
}
