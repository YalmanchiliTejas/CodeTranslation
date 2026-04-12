#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define rep(i,n) for(int i = 0; i < int(n); i++)

#define MAX(a,b) (a > b ? a : b)
#define MIN(a,b) (a < b ? a : b)
const int MOD = 1000000007;

int n;
ll a[3001];
ll prefix[3001];
ll dp[3001][3001];

ll sum(int i, int j) {
    return (prefix[j] - prefix[i - 1]);
}

int main() {
    IOS;
    cin >> n;
    rep(i, n) cin >> a[i + 1];
    for(int i = 1; i <= n; i++) prefix[i] = prefix[i - 1] + a[i];
    rep(i, n + 1) dp[i][i] = a[i];
    for(int len = 1; len <= n - 1; len++) {
        for(int i = 1; i <= n - len; i++) {
            int j = i + len;
            dp[i][j] = max(a[i] + sum(i + 1, j) - dp[i + 1][j],
                           a[j] + sum(i, j - 1) - dp[i][j - 1]);
        }
    }

    cout << dp[1][n] - (prefix[n] - dp[1][n]);
    return 0;
}