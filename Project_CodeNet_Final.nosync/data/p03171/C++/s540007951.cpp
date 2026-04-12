#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <cmath>
#include <numeric>

using namespace std;

#define int long long
typedef long double ld;
#define pii pair<int, int>
#define vi vector<int>
#define vii vector<vi>
#define viii vector<vii>
#define vpii vector<pii>
#define vb vector<bool>
#define vbb vector<vb>
#define vs vector<string>
#define pb push_back
#define ff first
#define ss second
#define all(a) a.begin(), a.end()
#define in(a, x) for (int i = x; i < (a).size(); ++i) cin >> (a)[i]
#define out(a) for (auto qwe : a) cout << qwe << " "

const int INF = 1e9;
const int INF64 = 1e18;
const int MOD = 1e9 + 7;
const int MOD9 = 1e9 + 9;
const int MOD3 = 998244353;
const int P = 37;

const int mxn = 300;

vii dp;
vi a;

void f(int l, int r) {
    if (dp[l][r] != -INF || l > r) return;

    f(l + 1, r);
    f(l, r - 1);

    dp[l][r] = max(a[l] - dp[l + 1][r], a[r] - dp[l][r - 1]);
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    a.resize(n + 1);
    in(a, 1);

    dp.assign(n + 1, vi(n + 1, -INF));

    for (int j = 1; j <= n; ++j) {
        dp[j][j] = a[j];
    }

    f(1, n);

    cout << dp[1][n];
}