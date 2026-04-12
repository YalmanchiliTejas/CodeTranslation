#ifndef ONLINE_JUDGE
    #include "debug.cpp"
#endif

#include <bits/stdc++.h>

using namespace std;

#define int long long
#define ar array
const int MOD = (int)1e9 + 7;

void solve() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < (int) n; i++) {
        cin >> arr[i];
    }
    vector<int> dp(n,0);
    for (int i = (int) n - 1; i >= 0; --i) {
        if(i==(n-1)) dp[i]=arr[i];
        else dp[i] = dp[i+1]+arr[i];
    }
    int ans = 0;
    for (int i = (int) n - 2; i >= 0; --i) {
        ans += (dp[i+1]%MOD*arr[i]%MOD)%MOD;
    }
    cout << ((ans%MOD)+MOD)%MOD << "\n";
}

int32_t main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    int TC = 1;
    while (TC--)
        solve();

    return 0;
}

