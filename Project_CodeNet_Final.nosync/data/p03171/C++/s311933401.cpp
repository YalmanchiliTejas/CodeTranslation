#include <bits/stdc++.h>
using namespace std;
#define int long long int
// #include "../../Template.cpp"

int n;
vector<int> arr;
vector<vector<int>> dp;


int solve(int l = 0, int r = n-1, int chance = 0) {
    // t(l, r, chance);
    if(dp[l][r] != -1e18) {
        return dp[l][r];
    }
    if(l == r) {
        if(!chance) {
            dp[l][r] = arr[l];
        }
        else {
            dp[l][r] = -arr[l];
        }
        return dp[l][r];
    }
    if(!chance) {
        dp[l][r] = max(arr[l]+solve(l+1, r, !chance), arr[r] + solve(l, r-1, !chance));
    }
    else {
        dp[l][r] = min(-arr[l] + solve(l+1, r, !chance), -arr[r] + solve(l, r-1, !chance));
    }
    return dp[l][r];
}

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    arr.assign(n, 0);
    for(int i = 0; i < n; i ++) {
        cin >> arr[i];
    }
    dp.assign(n+1, vector<int>(n+1, -1e18));
    int ans = solve();
    cout << ans << endl;
    return 0;
}