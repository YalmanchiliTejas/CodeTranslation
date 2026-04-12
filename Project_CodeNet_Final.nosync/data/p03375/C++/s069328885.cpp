#include <bits/stdc++.h>

#define reg register
#define pr std::pair<int, int>
#define fi first
#define se second
#define FIN(s) freopen(s, "r", stdin)
#define FOUT(s) freopen(s, "w", stdout)
#define debug(...) fprintf(stderr, __VA_ARGS__)
#define rep(i, l, r) for (int i = l; i <= r; ++i)
#define lep(i, l, r) for (int i = l; i < r; ++i)
#define irep(i, r, l) for (int i = r; i >= l; --i)
#define ilep(i, r, l) for (int i = r; i > l; --i)
#define Rep(i, n) rep(i, 1, n)
#define Lep(i, n) lep(i, 1, n)
#define IRep(i, n) irep(i, n, 1)
#define ILep(i, n) ilep(i, n, 1)
typedef long long ll;
typedef long double ld;

namespace modular {
    int MOD;
    inline int add(int x, int y) { return (x += y) >= MOD ? x -= MOD : x; }
    inline void inc(int &x, int y) { (x += y) >= MOD ? x -= MOD : 0; }
    inline int mul(int x, int y) { return 1LL * x * y % MOD; }
    inline int qpow(int x, int y) {
        int ans = 1;
        for (; y; y >>= 1, x = mul(x, x))
            if (y & 1) ans = mul(ans, x);
        return ans;
    }
};  // namespace modular
using namespace modular;

namespace Base {
    template <typename Tp>
    inline Tp input() {
        Tp x = 0, y = 1;
        char c = getchar();
        while ((c < '0' || '9' < c) && c != EOF) {
            if (c == '-') y = -1;
            c = getchar();
        }
        if (c == EOF) return 0;
        while ('0' <= c && c <= '9') x = x * 10 + c - '0', c = getchar();
        return x *= y;
    }
    template <typename Tp>
    inline void read(Tp &x) {
        x = input<Tp>();
    }
    template <typename Tp>
    inline void chmax(Tp &x, Tp y) {
        x < y ? x = y : 0;
    }
    template <typename Tp>
    inline void chmin(Tp &x, Tp y) {
        x > y ? x = y : 0;
    }
};  // namespace Base
using namespace Base;
/*----------------------------------------------------------------------------*/

#define MAX_N 3007

int N;
int C[MAX_N][MAX_N], S[MAX_N][MAX_N];

void init() {
    C[0][0] = 1;
    Rep(i, N) {
        C[i][0] = 1;
        Rep(j, i) C[i][j] = add(C[i - 1][j - 1], C[i - 1][j]);
    }
    S[0][0] = 1;
    Rep(i, N + 1) {
        Rep(j, i) S[i][j] = add(S[i - 1][j - 1], mul(S[i - 1][j], j));
    }
}

void solve() {
    int res = 0;
    rep(i, 0, N) {
        int sum = 0, bs = qpow(2, N - i), now = 1;
        rep(j, 0, i) inc(sum, mul(S[i + 1][j + 1], now)), now = mul(now, bs);
        bs = 1;
        rep(j, 1, N - i) bs = 1LL * bs * 2 % (MOD - 1);
        if (i & 1)
            inc(res, MOD - mul(C[N][i], mul(qpow(2, bs), sum)));
        else
            inc(res, mul(C[N][i], mul(qpow(2, bs), sum)));
    }
    printf("%d\n", res);
}

int main() {
#ifdef LOCAL
    FIN("in");
#endif
    read(N), read(MOD);
    init();
    solve();
    return 0;
}
