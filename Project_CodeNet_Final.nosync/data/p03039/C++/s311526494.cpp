#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
#include <chrono>
#include <random>
#include <unordered_map>

using namespace std;

#define int long long
#define ll long long
//#define double long double
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()

const int INF = 2e9;
const int MB = 20;
const int MOD = 1e9 + 7;

int mod_pow(int a, int b) {
    if (!b) return 1;
    if (b % 2) return a * mod_pow(a, b - 1) % MOD;
    int q = mod_pow(a, b / 2);
    return q * q % MOD;
}

int fact(int n) {
    int res = 1;
    for (int i = 2; i <= n; i++) {
        res = res * i % MOD;
    }
    return res;
}

void solve() {
    int n, m, k;
    cin >> n >> m >> k;
    int d = 0;
    for (int i = 1, ost = 0; i <= n; i++) {
        for (int j = 1; j <= m; j++, ost++) {
            d = (d + ost * i) % MOD;
            d = (d - (n * m - ost - 1) * i + MOD) % MOD;
        }
    }
    for (int j = 1, ost = 0; j <= m; j++) {
        for (int i = 1; i <= n; i++, ost++) {
            d = (d + ost * j) % MOD;
            d = (d - (n * m - ost - 1) * j + MOD) % MOD;
        }
    }

    int c = (fact(n * m - 2) * mod_pow(fact(k - 2), MOD - 2) % MOD) * mod_pow(fact(n * m - k), MOD - 2) % MOD;
    cout << c * d % MOD;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    //int t;
    //cin >> t;
    int t = 1;
    while (t--) solve();
}