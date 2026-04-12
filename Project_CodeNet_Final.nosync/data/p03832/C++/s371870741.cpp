#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <functional>
#define fs first
#define se second

using namespace std;
typedef long long llong;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<llong, llong> pll;
typedef pair<ld, ld> pdd;

const int mod = 1e9 + 7;

void add(int &x, int y) {
    x += y;
    x %= mod;
}

int mul(int x, int y) {
    return (llong)x * y % mod;
}

int pw(int x, int p) {
    int r = 1;
    while (p) {
        if (p & 1) r = mul(r, x);
        x = mul(x, x);
        p >>= 1;
    }
    return r;
}

int fac[1001];
int rev[1001];

int nCr(int n, int r) {
    return mul(fac[n], mul(rev[r], rev[n - r]));
}

void init(int N) {
    fac[0] = 1;
    for (int i = 1; i <= N; ++i) fac[i] = mul(fac[i - 1], i);
    rev[N] = pw(fac[N], mod - 2);
    for (int i = N; i--; ) rev[i] = mul(rev[i + 1], i + 1);
}

int dp[1001][1001];
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n, a, b, c, d;
    cin >> n >> a >> b >> c >> d;
    init(n);
    dp[a - 1][0] = 1;
    for (int i = a; i <= b; ++i) {
        for (int j = 0; j <= n; ++j) {
            add(dp[i][j], dp[i - 1][j]);
            int it = fac[n - j];
            for (int k = 1; k <= d && k * i + j <= n; ++k) {
                it = mul(it, rev[i]);
                if (k < c) continue;
                int val = mul(it, mul(rev[k], rev[n - j - k * i]));
                add(dp[i][k * i + j], mul(dp[i - 1][j], val));
            }
        }
    }
    printf("%d\n", dp[b][n]);
    return 0;
}