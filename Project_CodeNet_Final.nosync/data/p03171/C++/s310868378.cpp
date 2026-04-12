//#pragma  GCC optimize("Ofast")

//#ifdef  DEBUG
//#define _GLIBCXX_DEBUG
//#endif

// -Ofast
// -O3
// -O2
// -fsanitize=address
// -fsanitize=undefined

// add_compile_options()

#include <iostream>
#include <map>
#include <vector>
#include <set>
#include <stack>
#include <bitset>
#include <queue>
#include <algorithm>
//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/tree_policy.hpp>
#include <iomanip>
#include <unordered_map>
#include <cmath>
#include <cassert>
#include <random>

using namespace std;
//using namesparsace __gnu_pbds;

void solve();

signed main() {
    srand(time(0));
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
#ifdef DEBUG
    freopen("input.txt", "r", stdin);
#endif
    //freopen("input.txt", "r", stdin);
    //freopen("trench.out", "w", stdout);
    solve();
    return 0;
}

#define ld double
#define int long long

const int maxN = 3010, maxK = 1e5 + 10, inf = 2e18 + 10, mod = 1e9 + 7;

int n, a[maxN], dp[maxN][maxN], pref[maxN];

void solve() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int i = 1; i <= n; i++) {
        pref[i] = pref[i - 1] + a[i - 1];
    }
    for (int i = 0; i < n; i++) {
        dp[i][i] = a[i];
    }
    for (int len = 1; len < n; len++) {
        for (int l = 0; l + len < n; l++) {
            int r = l + len;
            dp[l][r] = pref[r + 1] - pref[l] - min(dp[l + 1][r], dp[l][r - 1]);
        }
    }
    cout << 2 * dp[0][n - 1] - pref[n];
}