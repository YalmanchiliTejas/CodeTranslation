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
#define no {cout << "No"; return;}
#define mkp make_pair
#define mkt make_tuple
#define cerr if (0) cerr

const int N = 2e5 + 7, INF = 1e18;

int a[N], dp2[3][N], dp3[2][N];

int solve0(int n) {
    int odd = 0, even = 0, ans = 0;
    for (int i = 1; i <= n; ++++i) {
        even += a[i]; odd += a[i + 1];
    }
    ans = max(odd, even);
    for (int i = 3; i <= n; ++i) {
        dp2[0][i] = dp2[0][i - 2] + a[i];
        dp2[1][i] = max(dp2[0][i - 3], dp2[1][i - 2]) + a[i];
    }
    ans = max(ans, dp2[1][n]);
    return ans;
}

int solve1(int n) {
    int ans = 0;
    for (int i = 2; i <= n; ++++i)
        ans += a[i];
    dp3[0][0] = 0;
    dp3[0][1] = a[1];
    dp3[0][2] = a[2];
    dp3[0][3] = a[3];
    for (int i = 3; i <= n; ++i) {
        dp2[0][i] = dp2[0][i - 2] + a[i];
        dp2[1][i] = max(dp2[0][i - 3], dp2[1][i - 2]) + a[i];
        dp2[2][i] = max(dp2[1][i - 3], dp2[2][i - 2]) + a[i];
        dp3[0][i] = dp3[0][i - 2] + a[i];
        if (i > 3)
            dp3[1][i] = max(dp3[1][i - 2], dp3[0][i - 4]) + a[i];
    }
    ans = max({ ans, dp2[1][n], dp2[1][n - 1], dp2[2][n], dp3[1][n] });
    return ans;
}

void solve() {
    loop(i, N)
        dp2[0][i] = dp2[1][i] = dp2[2][i] = dp3[0][i] = dp3[1][i] = -INF;
    int n; cin >> n;
    loop1(i, n)
        cin >> a[i];
    dp2[0][0] = 0;
    dp2[0][1] = a[1];
    dp2[0][2] = a[2];
    if (n % 2 == 0)
        cout << solve0(n);
    else
        cout << solve1(n);
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    //int t; cin >> t; loop(i, t)
    solve();
    return 0;
}
