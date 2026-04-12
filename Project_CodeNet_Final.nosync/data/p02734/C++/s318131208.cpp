#include<bits/stdc++.h>
using namespace std;
#define int long long int
vector<int> v;
int n, s;
int dp[3010][3010];
int mod = 998244353;

int solve(int ind, int sum)
{
    // cout << ind << " " << sum << endl;
    if(sum < 0)
    {
        // cout << 0 << endl;
        return 0;
    }
    if(sum == 0)
    {
        // cout << (n-ind) << endl;
        return (n-ind + 1);
    }
    if(ind >= n)
    {
        // cout << 0 << endl;
        return 0;
    }
    if(dp[ind][sum] != -1)
        return dp[ind][sum];

    // cout << ind << " " << sum << endl;
    int ans = 0;
    if(sum == s)
    {
        ans = ans + (ind+1) * solve(ind+1, sum-v[ind]) + solve(ind+1, sum);
        ans = ans % mod;
    }
    else
    {
        ans = ans + solve(ind+1, sum) + solve(ind+1, sum-v[ind]);
        ans = ans % mod;
    }

    return dp[ind][sum] = ans;
}

int32_t main()
{
    cin >> n >> s;
    v.resize(n);
    for(int i=0; i<n; i++)
        cin >> v[i];
    memset(dp, -1, sizeof dp);
    cout << solve(0, s) << endl;
    return 0;
}
