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

const size_t N = 1e7 + 5;
const int MOD = 998244353;

int qpow(int base, int e) {
    int ret = 1;
    for (; e; e >>= 1) {
        if (e & 1) {
            ret = (LL) ret * base % MOD;
        }
        base = (LL) base * base % MOD;
    }
    return ret;
}

void iadd(int &dp, int val) {
    dp += val;
    if (dp >= MOD) {
        dp -= MOD;
    }
}

void ladd(int &dp, LL val) {
    dp = (dp + val) % MOD;
}

int n;
int fac[N], inv[N];

void prep() {
    fac[0] = 1;
    for (int i = 1; i <= n; ++i) {
        fac[i] = (LL) fac[i - 1] * i % MOD;
    }
    inv[n] = qpow(fac[n], MOD - 2);
    for (unsigned i = n; i; --i) {
        inv[i - 1] = (LL) inv[i] * i % MOD;
    }
}

int main() {
    n = read();
    prep();
    int ans = qpow(3, n);
    int pw2 = 2;
    for (int i = n; i > n / 2; --i) {
        ladd(ans, -1LL * pw2 * fac[n] % MOD * inv[i] % MOD * inv[n - i]);
        iadd(pw2, pw2);
    }
    if (ans < 0) ans += MOD;
    cout << ans;
    return 0;
}