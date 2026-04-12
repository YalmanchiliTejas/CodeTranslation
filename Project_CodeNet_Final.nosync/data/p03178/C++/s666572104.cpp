#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define mod 1000000007

ll n, dp[10001][101][2], d;
vector<ll> v;

ll solve(ll i, ll m, ll bo) {
    if (i == n && !m) {
        return 1;
    } else if (i == n) return 0;

    if (dp[i][m][bo] != -1) return dp[i][m][bo];
    ll ans = 0;
    for (int j = 0; j <= (bo ? v[i] : 9); j++) {
        ans = (ans + solve(i + 1, (j + m) % d, bo && j == v[i])) % mod;
    }
    dp[i][m][bo] = ans;
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    memset(dp, -1, sizeof(dp));

    string s;
    cin >> s;
    n = s.length();
    cin >> d;

    for (char c : s) {
        v.push_back(c - 48);
    }

    ll ans = solve(0, 0, 1) - 1;
    if (ans < 0) {
        ans += mod;
    }
    cout << ans;
}
