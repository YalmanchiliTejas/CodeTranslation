//https://atcoder.jp/contests/dp/tasks/dp_l
//shauryakr
#include<bits/stdc++.h>
using namespace std;
long long int arr[3005], n;
long long int dp[3005][3005][2];
long long int solve(int start, int ends, int player)
{
    if(start > ends)
    {
        return 0;
    }

    if(dp[start][ends][player] != -1)
        return dp[start][ends][player];

    long long int ans = player?1000000000000000:-1000000000000000;
    if(!player)
    {
        ans = max(solve(start + 1, ends, 1 - player) + arr[start], solve(start, ends-1, 1 - player) + arr[ends]);
    }
    else
    {
        ans = min(solve(start + 1, ends, 1 - player) - arr[start], solve(start, ends-1, 1 - player) - arr[ends]);
    }

    dp[start][ends][player] = ans;
    return ans;
}

int main()
{
    cin >> n;
    for(int i=0; i<n; i++)
    {
        cin >> arr[i];
    }

    memset(dp,-1, sizeof dp);
    cout << solve(0, n-1, 0) << endl;
    return 0;
}