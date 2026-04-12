#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <set>
#include <map>
#include <cmath>
#include <cassert>
#include <unordered_map>
#define int long long

using namespace std;

typedef pair<int, int> pa;
typedef long long ll;
typedef long double ld;

const int mod = 1e9 + 7;

int pw(int a, int st) {
    if (st == 0) return 1;
    int b = pw(a, st / 2);
    b = (b * b) % mod;
    if (st % 2)
        return (a * b) % mod;
    return b;
}

const int N = 2e5, inf = 4e18;
int dp[N + 1][3];


signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;
    vector<int> a(n);
    for (int& i : a) cin >> i;

    for (int i = 0; i <= N; ++i) for (int j = 0; j <= 2; ++j) dp[i][j] = -inf;
    for (int i = 0; i < n; ++i) {
        int NWDP = i, PRDP = i - 2;
        for (int prsk = 0; prsk <= 2; ++prsk) {
            for (int sk = 0; prsk + sk <= 2; ++sk) {
                int val = 0;
                if (PRDP - sk >= 0) {
                    val = dp[PRDP - sk][prsk];
                }
                if (PRDP - sk >= -1 || (PRDP - sk == -2 && i == 0 && prsk == 0)) {
                    dp[i][prsk + sk] = max(val + a[i], dp[i][prsk + sk]);
                }
            }
        }
    }
    
    int ans;
    if (n % 2 == 0) {
        ans = dp[n - 1][0];
        ans = max(ans, dp[n - 1][1]);
        ans = max(ans, dp[n - 2][0]);
    } else {
        ans = dp[n - 1][1];
        ans = max(ans, dp[n - 1][2]);
        ans = max(ans, dp[n - 2][0]);
        ans = max(ans, dp[n - 2][1]);
        ans = max(ans, dp[n - 3][0]);
    }

    cout << ans;
}