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
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
 
//#define int ll
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

const int N = 3007, MOD = 998244353;

int dp[N][N];
int a[N];

int inc(int a) {
    return (a >= MOD ? a - MOD : a);
}

void calc_dp(int n, int s) {
    loop1(len, n) {
        loop(i, s + 1)
            dp[len][i] = inc(dp[len - 1][i] + (a[len] <= i ? dp[len - 1][i - a[len]] : 0));
        if (a[len] <= s)
            dp[len][a[len]] = inc(dp[len][a[len]] + len);
    }
}

void solve() {
    int n, s;
    cin >> n >> s;
    loop1(i, n)
        cin >> a[i];
    calc_dp(n, s);
    // loop(i, n + 1) {
    //     loop(j, s + 1)
    //         cout << dp[i][j] << " ";
    //     cout << "\n";
    // }
    int ans = 0;
    loop1(i, n)
        ans = inc(ans + dp[i][s]);
    cout << ans;
}
 
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    //int t; cin >> t; loop(i, t)
    solve();
    return 0;
}