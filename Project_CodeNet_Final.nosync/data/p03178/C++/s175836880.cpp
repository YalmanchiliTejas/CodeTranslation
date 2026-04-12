#include <bits/stdc++.h>

#define ll long long
#define MAX 300005
#define pp pair<int,pair<int,int>>
#define pb push_back
#define mod 1000000007

using namespace std;

/*
 * author: Kruti_20
 */

ll power(ll x, ll y);

ll gcd(ll a, ll b);

ll dp[100005][100][2];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string s;
    cin >> s;
    int d;
    cin >> d;
    for (int i = 0; i < (s[0] - '0'); i++) dp[0][i % d][0] += 1;
    dp[0][(s[0] - '0') % d][1] = 1;
    for (int i = 1; i < s.length(); i++) {
        for (int j = 0; j < d; j++) {
            for (int k = 0; k <= 9; k++) {
                dp[i][j][0] += dp[i - 1][(j - k + 10 * d) % d][0];
                if (k < (s[i] - '0')) dp[i][j][0] += dp[i - 1][(j - k + 10 * d) % d][1];
                if (k == (s[i] - '0')) dp[i][j][1] += dp[i - 1][(j - k + 10 * d) % d][1];
                dp[i][j][0] %= mod;
                dp[i][j][1] %= mod;
            }
        }
    }
    cout << (dp[s.length() - 1][0][0] + dp[s.length() - 1][0][1] - 1 + mod) % mod;
    return 0;
}

ll power(ll x, ll y) {
    ll res = 1;
    x = x % mod;
    while (y > 0) {
        if (y & 1) res = (res * x) % mod;
        y = y >> 1;
        x = (x * x) % mod;
    }
    return res;
}

ll gcd(ll a, ll b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}