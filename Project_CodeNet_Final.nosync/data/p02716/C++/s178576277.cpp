// Sky's the limit :)
#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    
    int T = 1; 
    // cin >> T; 
    while (T--) {
        int n;
        cin >> n;
        vector<int> a(n + 1);
        for(int i = 1; i <= n; i++)
            cin >> a[i];

        int ps[n + 1];
        ps[1] = a[1];
        for(int i = 3; i <= n; i += 2)
            ps[i] = a[i] + ps[i - 2];   

        int dp[n + 1] = {};
        // dp[1] = a[1];
        for(int i = 2; i <= n; i++) {
            if(i % 2 == 0)
                dp[i] = max(dp[i - 2] + a[i], ps[i - 1]);
            else
                dp[i] = max(dp[i - 1], dp[i - 2] + a[i]);
        }
        // for(int i = 1; i < n; i++)
        //     cout << dp[i] << ' ';
        cout << dp[n] << '\n';
    }
    
    return 0;
}

