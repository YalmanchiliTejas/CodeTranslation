#include <bits/stdc++.h>
using namespace std;
#define ll long long int 
#define ar array
const ll mod = 1e9 + 7;
int main() {
	// your code goes here
	int n;
    cin >> n;
    vector<ll> a(n);
    for (ll &x : a) cin >> x;
    vector<vector<ar<ll, 2>>> dp(n, vector<ar<ll, 2>>(n));
    for (int i = 0; i < n; ++i) {
        dp[i][i][0] = a[i];
        dp[i][i][1] = 0;
    }
    for (int Rminus = 1; Rminus < n; ++Rminus) {
        for (int L = 0; L + Rminus < n; ++L) {
            int R = L + Rminus;
            dp[L][R][0] = max(dp[L + 1][R][1] + a[L], dp[L][R - 1][1] + a[R]);
            dp[L][R][1] = min(dp[L + 1][R][0], dp[L][R - 1][0]);
            
        }


    }
    ll ans = 2 *  dp[0][n - 1][0] - accumulate(a.begin(), a.end(), 0LL);
    cout << ans;



	return 0;
}
