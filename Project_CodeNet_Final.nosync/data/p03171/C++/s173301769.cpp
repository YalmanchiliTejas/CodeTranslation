#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main()
{
    int n;
    cin >> n;
    vector<ll> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];
    vector<vector<ll>> dp(n+1, vector<ll>(n+1, 0));
    function<ll(int, int, int)> rec = [&](int l, int r, int first)
    {
        if(dp[l][r]) return dp[l][r];
        if(l == r) return first * a[l];
        if(first == 1)
        {
            ll tmp = -1e14;
            tmp = max(tmp, rec(l+1, r, -first) + first * a[l]);
            tmp = max(tmp, rec(l, r-1, -first) + first * a[r]);
            return dp[l][r] = tmp;
        }
        else
        {
            ll tmp = 1e14;
            tmp = min(tmp, rec(l+1, r, -first) + first * a[l]);
            tmp = min(tmp, rec(l, r-1, -first) + first * a[r]);
            return dp[l][r] = tmp;
        }
    };
    cout << rec(0, n-1, 1) << endl;
}
