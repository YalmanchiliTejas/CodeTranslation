#include <vector>
#include <array>
#include <map>
#include <string>
#include <algorithm>
#include <iostream>
#include <set>
#include <random>
#include <cassert>
#include <fstream>

const int MOD = 1e9 + 7;
using namespace std;

int64_t dp[1001][1001];
int64_t fac[1001];
int64_t inv[1001];
int64_t rev[1001];
int64_t add(int64_t a, int64_t b) {
    a += b;
    if (a >= MOD) {
        a -= MOD;
    }
    return a;
}

int64_t mul(int64_t a, int64_t b) {
    return a * b % MOD;
}

void prep() {
    fac[0] = 1;
    fac[1] = 1;
    rev[1] = 1;
    inv[0] = 1;
    inv[1] = 1;
    for (int i = 2; i <= 1000; ++i) {
        fac[i] = mul(fac[i - 1], i);
        rev[i] = mul(MOD - MOD / i, rev[MOD % i]);
        inv[i] = mul(inv[i - 1], rev[i]);
        assert(mul(inv[i], fac[i]) == 1);
    }
}

int64_t C(int64_t n, int64_t k) {
    return mul(mul(fac[n], inv[k]), inv[n - k]);
}
int64_t pw(int64_t a, int64_t b) {
    int64_t res = 1;
    while (b) {
        if (b & 1) {
            res = mul(res, a);
        }
        a = mul(a, a);
        b >>= 1;
    }
    return res;
}
int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    prep();
    int n;
    cin >> n;
    int a, b;
    cin >> a >> b;
    int c, d;
    cin >> c >> d;
    dp[a - 1][0] = 1;

    for (int i = a; i <= b; ++i) {
        for (int j = 0; j <= n; ++j) {
            int up = j / i;
            int64_t cur_pw = pw(inv[i], c);
//            cout << "calc " << i << " " << j << endl;
            for (int e = c; e <= up && e <= d; ++e) {
//                cout << i - 1 << " " << j - e * i << endl;
                int64_t coef = mul(mul(dp[i - 1][j - e * i], C(j, j - e * i)), cur_pw);
                coef = mul(coef, inv[e]);
                coef = mul(coef, fac[e * i]);
                dp[i][j] = add(dp[i][j], coef);
                cur_pw = mul(cur_pw, inv[i]);
            }
            dp[i][j] = add(dp[i][j], dp[i - 1][j]);
//            cout << i - 1 << " " << j << endl;
//            cout << i << " " << j << " " << dp[i][j] << endl;
        }
    }
    cout << dp[b][n];
}

