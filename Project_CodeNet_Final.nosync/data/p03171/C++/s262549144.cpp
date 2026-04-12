#include <bits/stdc++.h>
using namespace std;

#define MOD 1000000007
#define ll long long int 
#define off ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)

ll dp[3000][3000];

int main()
{
    off;

    int n;cin>>n;
    ll arr[n];
    for (int i = 0; i < n; ++i)
    {
        cin>>arr[i];
    }

    for (int i = 0; i < n; ++i)
    {
        dp[i][i] = arr[i];
    }

    for (int i = 1; i < n; ++i)
    {
        for (int j = 0; j < n && j+i<n; ++j)
        {
            dp[j][j+i] = max(arr[j]-dp[j+1][j+i], -dp[j][j+i-1]+arr[j+i]);
        }
    }

    cout<<dp[0][n-1];

    return 0;
}
