#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

//-----------------------
const int MOD = (int)1e9 + 7;
struct mint { int n; mint(int n_ = 0) : n(n_ % MOD) { if (n < 0) n += MOD; } };
mint operator+(mint a, mint b) { return (a.n += b.n) >= MOD ? a.n - MOD : a.n; }
mint operator-(mint a, mint b) { return (a.n -= b.n) < 0 ? a.n + MOD : a.n; }
mint operator*(mint a, mint b) { return 1LL * a.n * b.n % MOD; }
mint &operator+=(mint &a, mint b) { return a = a + b; }
mint &operator-=(mint &a, mint b) { return a = a - b; }
mint &operator*=(mint &a, mint b) { return a = a * b; }
ostream &operator<<(ostream &os, mint a) { return os << a.n; }
istream &operator>>(istream &is, mint& a) { return is >> a.n; }
mint inv(mint x) { long long a = x.n, b = MOD, u = 1, v = 0;
    while (b) { long long t = a/b; swap((a -= t*b), b); swap((u -= t*v), v); }
    return mint(u); }
mint operator^(mint a, long long n) { mint r = 1;
    while (n) { if (n & 1) r *= a; a *= a; n >>= 1; } return r; }
bool operator<(const mint &a, const mint &b) { return a.n < b.n; }
//-----------------------

mint dp[10101][101][2];
int main() {
    string s; cin >> s;
    int M; cin >> M;
    int n = s.size();
    dp[0][0][0] = 1;
    for (int i = 0; i < n; i++) for (bool lt: {true, false}) {
        for (int r = 0; r < M; r++) {
            int cur = s[i] - '0';
            for (int d = 0; d < 10; d++) if (lt || d <= cur) {
                dp[i + 1][(r + d) % M][lt | (d < cur)] += dp[i][r][lt];
            }
        }
    }
    cout << dp[n][0][0] + dp[n][0][1] - 1 << endl;  // 0 を除く
    return 0;
}