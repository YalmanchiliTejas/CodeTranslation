// Words are flowing out like endless rain into a paper cup
// They slither while they pass they slip away across the universe
// Pools of sorrow, waves of joy are drifting through my open mind
// Possessing and caressing me

#include <bits/stdc++.h>
using namespace std;

using LL = long long;

namespace _buff {

const size_t BUFF = 1 << 19;
char ibuf[BUFF], *ib = ibuf, *ie = ibuf;
char getc() {
    if (ib == ie) {
        ib = ibuf;
        ie = ibuf + fread(ibuf, 1, BUFF, stdin);
    }
    return ib == ie ? -1 : *ib++;
}

}

LL read() {
    using namespace _buff;
    LL ret = 0;
    bool pos = true;
    char c = getc();
    for (; (c < '0' || c > '9') && c != '-'; c = getc()) {
        assert(~c);
    }
    if (c == '-') {
        pos = false;
        c = getc();
    }
    for (; c >= '0' && c <= '9'; c = getc()) {
        ret = (ret << 3) + (ret << 1) + (c ^ 48);
    }
    return pos ? ret : -ret;
}

int mod;
using uint = unsigned;
struct Z {
    uint v;

    Z(uint v = 0) : v(v) {}

    Z& operator += (const Z &z) {
        v += z.v;
        if (v >= mod) v -= mod;
        return *this;
    }

    Z& operator -= (const Z &z) {
        if (v < z.v) v += mod;
        v -= z.v;
        return *this;
    }

    Z& operator *= (const Z &z) {
        v = static_cast<uint64_t>(v) * z.v % mod;
        return *this;
    }
};

ostream& operator << (ostream &os, const Z &z) {
    return os << z.v;
}

Z operator + (const Z &x, const Z &y) {
    return Z(x.v + y.v >= mod ? x.v + y.v - mod : x.v + y.v);
}

Z operator - (const Z &x, const Z &y) {
    return Z(x.v < y.v ? x.v + mod - y.v : x.v - y.v);
}

Z operator * (const Z &x, const Z &y) {
    return Z(static_cast<uint64_t>(x.v) * y.v % mod);
}

Z qpow(Z base, uint e) {
    Z ret(1);
    for (; e; e >>= 1) {
        if (e & 1) {
            ret *= base;
        }
        base *= base;
    }
    return ret;
}

int qpow(int base, int e, int mod) {
    int ret = 1;
    for (; e; e >>= 1) {
        if (e & 1) {
            ret = (LL) ret * base % mod;
        }
        base = (LL) base * base % mod;
    }
    return ret;
}

const size_t N = 3e3 + 5;

Z pw1[N], pw2[N], comb[N][N];
Z stir[N][N];

int main() {
    int n = read();
    mod = read();
    for (int i = 0; i <= n; ++i) {
        pw1[i] = qpow(2, i);
        pw2[i] = qpow(2, qpow(2, i, mod - 1));
    }
    comb[0][0] = 1;
    stir[0][0] = 1;
    for (int i = 1; i <= n; ++i) {
        comb[i][0] = 1;
        for (int j = 1; j <= i; ++j) {
            stir[i][j] = stir[i - 1][j - 1] + stir[i - 1][j] * j;
            comb[i][j] = comb[i - 1][j - 1] + comb[i - 1][j];
        }
    }
    Z ans = 0;
    for (int i = 0; i <= n; ++i) {
        Z cur = i == 0;
        for (int j = 1; j <= i; ++j) {
            cur += stir[i][j] * j * qpow(pw1[n - i], j - 1);
            cur += stir[i][j] * qpow(pw1[n - i], j);
        }
        cur *= comb[n][i] * pw2[n - i];
        if (i & 1) {
            ans -= cur;
        } else {
            ans += cur;
        }
    }
    cout << ans;
    return 0;
}
