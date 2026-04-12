#include <bits/stdc++.h>

using namespace std;

template <int MD>
struct ModInt {
    typedef ModInt M;
    int v;
    ModInt(int _v = 0) : v(_v) {}
    M& operator += (const M &r) {
        if ((v += r.v) >= MD) v -= MD;
        return *this;
    }
    M& operator -= (const M &r) {
        if ((v -= r.v) < 0) v += MD;
        return *this;
    }
    M operator + (const M &r) const { return M(*this) += r; }
    M operator - (const M &r) const { return M(*this) -= r; }
};
typedef ModInt<1000000007> Mint;

const int MN = 10010;
const int MR = 110;
string s;
int m;
Mint dp[MN][MR][10];

Mint f(int p, int acc) {
    if (p == 0) return (acc == 0);
    int cur = s[p - 1] - '0';
    Mint res = 0;
    for (int d = 0; d < cur; d++) {
        int r = (m - acc) % m;
        res += dp[p][r][d];
    }
    return res + f(p - 1, (acc + cur) % m);
}

int main() {
    cin >> s >> m;
    reverse(s.begin(), s.end());
    dp[0][0][0] = 1;
    for (int i = 0; i < MN - 1; i++) {
        for (int r = 0; r < m; r++) {
            Mint sm = 0;
            for (int d = 0; d < 10; d++) sm += dp[i][r][d];
            if (i == 0) assert(sm.v == (r == 0));
            for (int d = 0; d < 10; d++) {
                dp[i + 1][(r + d) % m][d] += sm;
            }
        }
    }
    Mint ans = f(int(s.size()), 0) - Mint(1);
    cout << ans.v << endl;
    return 0;
}