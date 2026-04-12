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

ll dp[3005][3005];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    ll a[n];
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = n; i > 0; i--) {
        for (int j = i; j <= n; j++) {
            if (i == j) dp[i][j] = a[i];
            else dp[i][j] = max(a[i] - dp[i + 1][j], a[j] - dp[i][j - 1]);
        }
    }
    cout << dp[1][n] << " ";
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
