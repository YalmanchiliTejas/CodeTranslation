#include <bits/stdc++.h>

// edit by  (xcode)

using namespace std;

#define int         long long
#define ll          long long
#define double      long double
#define pb          push_back
#define in          insert
#define mp          make_pair
#define f           first
#define s           second
//#define x           first
//#define y           second
#define all(el)     el.begin(), el.end()
#define allr(el)    el.rbegin(), el.rend()
#define sz(el)      (int)el.size()
#define endl        "\n"

inline int chkmax(int &x, int y) {
    if (y > x) {
        x = y;
        return true;
    }
    return false;
}

inline int chkmin(int &x, int y) {
    if (y < x) {
        x = y;
        return true;
    }
    return false;
}

signed main() {
    
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    int n, s;
    cin >> n >> s;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    int res = 0;
    vector<vector<int>> dp(n + 1, vector<int> (s + 1));
    for (int i = 1; i <= n; i++) {
        if (a[i - 1] <= s) {
            dp[i][a[i - 1]] += i;
            dp[i][a[i - 1]] %= 998244353;
        }
        for (int j = 0; j <= s; j++) {
            dp[i][j] += dp[i - 1][j];
            dp[i][j] %= 998244353;
        }
        for (int j = 0; j <= (s - a[i - 1]); j++) {
            dp[i][j + a[i - 1]] += dp[i - 1][j];
            dp[i][j + a[i - 1]] %= 998244353;
        }
        res += dp[i][s];
        res %= 998244353;
    }
    cout << res;
    return 0;
}

