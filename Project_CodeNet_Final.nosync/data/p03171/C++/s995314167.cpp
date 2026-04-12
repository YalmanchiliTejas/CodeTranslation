#include <bits/stdc++.h>
using namespace std;
#define int long long

double dp[301][301][301];

int32_t main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cout << fixed << setprecision(10);
    int n;
    cin>>n;
    int arr[n];
    for(int i=0; i<n; i++)
    {
        cin>>arr[i];
    }
    int dp[n][n][2];
    memset(dp,0,sizeof(dp));
    for(int diff=0; diff<n; diff++)
    {
        for(int i=0; i<n; i++)
        {
            int j = i+diff;
            if(j >= n)
                continue;
            if(i==j)
            {
                dp[i][j][0] = arr[i];
                dp[i][j][1] = arr[i]*-1;
            }
            else
            {
                dp[i][j][0] = max(arr[i] + dp[i+1][j][1] ,arr[j] + dp[i][j-1][1]);
                dp[i][j][1] = min(dp[i+1][j][0] - arr[i], dp[i][j-1][0] - arr[j]);            
            }
        }
    }
    cout<<dp[0][n-1][0];
    return 0;
}