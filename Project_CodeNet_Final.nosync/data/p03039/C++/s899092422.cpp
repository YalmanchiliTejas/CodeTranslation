#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <algorithm>
#include <string>
#include <cmath>
#include <cstdio>
#include <iomanip>
#include <fstream>
#include <cassert>
#include <cstring>
#include <numeric>
#include <ctime>
#include <complex>
#include <bitset>
#include <random>
#include <stack>

using namespace std;

typedef long long ll;
typedef long double ld;

#define int ll
#define double ld
#define loop(i, n) for(int i = 0; i < (int)n; ++i)
#define loop1(i, n) for(int i = 1; i <= (int)n; ++i)
#define F first
#define S second
#define pb push_back
#define pi pair <int, int>
#define all(x) begin(x), end(x)
#define ti tuple <int, int, int>
#define Point Vect
#define mkt make_tuple
#define no {cout << -1; return;}

const int MOD = 1e9 + 7, N = 2e5 + 7;

int binpow(int x, int d) {
    int ans = 1;
    while (d) {
        if (d & 1)
            ans = ans * x % MOD;
        x = x * x % MOD;
        d >>= 1;
    }
    return ans;
}

int f[N] = { 1 }, add[N];

void solve() {
    loop1(i, N - 1) {
        f[i] = f[i - 1] * i % MOD;
        add[i] = (add[i - 1] + i * (i + 1)) % MOD;
    }
    int n, m, k, ans = 0;
    cin >> n >> m >> k;
    loop(i, n)
        loop(j, m) {
            int d = abs(i - j), mn = min(i, j);
            int cur = (add[mn] + (d * (mn + 1) + d * (d - 1) / 2) * (mn + 1) + (mn == 0 ? 0 : mn * (mn + 1) / 2 % MOD * max(i, j) + mn * (mn + 1) / 2 % MOD * mn - add[mn - 1] + MOD)) * 2 % MOD;
            cur = (cur - (i * (i + 1) / 2 + j * (j + 1) / 2) % MOD + MOD) % MOD;
            ans = (ans + cur) % MOD;
        }
    cout << ans * f[n * m - 2] % MOD * binpow(f[k - 2], MOD - 2) % MOD * binpow(f[n * m - k], MOD - 2) % MOD;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    //int t; cin >> t; loop(i, t)
    solve();
    return 0;
}