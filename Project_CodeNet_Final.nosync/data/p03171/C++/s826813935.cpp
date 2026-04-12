#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const ll MIN = -1e12 - 5;

int main()
{
    int n;
    cin >> n;
    vector<ll> a(n);
    for(ll& x : a) {
        cin >> x;
    }

    vector<vector<ll>> dp(n, vector<ll>(n, MIN));
    for(int i = n-1; i >= 0; i--) {
        for(int j = i; j < n; j++) {
            if(i == j) {
                dp[i][j] = a[i];
                continue;
            }
            dp[i][j] = max(a[i]-(i < n-1 ? dp[i+1][j] : 0), a[j]-(j > 0 ? dp[i][j-1] : 0));
        }
    }
    cout << dp[0][n-1] << endl;
}
