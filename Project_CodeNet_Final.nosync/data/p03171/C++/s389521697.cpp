#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ll long long

int n;
ll arr[3005];
ll dp[3005][3005];

ll recur(int i, int j)
{
    if(i == j) return arr[i];
    if(i == j-1) return max(arr[i],arr[j]);
    if(dp[i][j] != -1) return dp[i][j];

    return dp[i][j] = max(arr[i]+min(recur(i+2,j),recur(i+1,j-1)),
               arr[j]+min(recur(i+1,j-1),recur(i,j-2)));
}

int main()
{
    FASTIO
    memset(dp,-1,sizeof(dp));
    cin >> n;
    ll sum = 0;
    for(int i=0; i<n; i++)
    {
        cin >> arr[i];
        sum += arr[i];
    }
    if(n == 1) cout << arr[0];
    else if(n == 2) cout << max(arr[0],arr[1]) - min(arr[0],arr[1]);
    else
    {
        recur(0,n-1);
        cout << 2*dp[0][n-1] - sum << "\n";
    }
    return 0;
}