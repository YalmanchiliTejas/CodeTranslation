#ifdef DEBUG
#define _GLIBCXX_DEBUG
#endif
//#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef long long ll;
const int mod = (int)1e9 + 7;

int mult(int a, int b) {
    return (1LL * a * b) % mod;
}

int pw(int a, int b) {
    if (b == 0) return 1;
    if (b & 1) return mult(a, pw(a, b - 1));
    int res = pw(a, b / 2);
    return mult(res, res);
}

int sub(int a, int b) {
    int s = a - b;
    if (s < 0) s += mod;
    return s;
}

int sum(int a, int b) {
    int s = a + b;
    if (s >= mod) s -= mod;
    return s;
}

const int maxN = (int)1e3 + 100;

int fact[maxN], invfact[maxN], inv[maxN];

void init() {
    inv[1] = invfact[1] = invfact[0] = fact[0] = fact[1] = 1;
    for (int i = 2; i < maxN; i++) {
        fact[i] = mult(fact[i - 1], i);
        inv[i] = mult(inv[mod % i], mod - mod / i);
        invfact[i] = mult(invfact[i - 1], inv[i]);
    }
}

int cnk(int n, int k) {
    if (n < k) return 0;
    if (n < 0 || k < 0) return 0;
    return mult(fact[n], mult(invfact[k], invfact[n - k]));
}

int invNumber(int a) {
    return pw(a, mod - 2);
}
int n;
int dp[maxN][maxN];
int a, b, c, d;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
//    freopen("input.txt", "r", stdin);
    init();
    cin >> n >> a >> b >> c >> d;
    dp[0][0] = 1;
    for (int i = 0; i < n; i++) {
        for (int sz = 0; sz <= n; sz++) {
            if (!dp[i][sz]) continue;
            int coef = 1;
            for (int j = 0; j * (i + 1) <= (n - sz); j++) {
                if (!(a <= i + 1 && (i + 1) <= b) && j > 0) break;
                if (j == 0 || (c <= j && j <= d)) {
                    dp[i + 1][sz + j * (i + 1)] = sum(dp[i + 1][sz + (j * (i + 1))], mult(dp[i][sz], coef));
                }
                coef = mult(coef, invfact[i + 1]);
                coef = mult(coef, inv[j + 1]);
            }
        }
    }
    cout << mult(fact[n], dp[n][n]);
    return 0;
}