#include<bits/stdc++.h>
using namespace std;
#define mod 1000000007
long long int arr[3005],n,dp[3005][3005][3],m;
long long int solve(long long int low,long long int high,long long int player)
{
    long long int pl=(player==1?2:1);
    if(low==high)
    {
        if(player==1)
          dp[low][high][player]=arr[low];
        else
          dp[low][high][player]=(-1)*arr[low];
      return dp[low][high][player];
    }
    if(dp[low][high][player]!=-1)
        return dp[low][high][player];
    long long int ans1,ans2;
    if(player==1)
    {
        ans1=arr[low]+solve(low+1,high,pl);
        ans2=arr[high]+solve(low,high-1,pl);
        dp[low][high][player]=max(ans1,ans2);
    }
    if(player==2)
    {
        ans1=solve(low+1,high,pl)-arr[low];
        ans2=solve(low,high-1,pl)-arr[high];
        dp[low][high][player]=min(ans1,ans2);
    }
    return dp[low][high][player];
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    long long int i,j,k,a,b,ans=0,sum=0,cnt=0;
    cin >> n;
    //long long int arr[n];
    memset(dp,-1,sizeof(dp));
    /*for(i=0;i<n;i++)
        for(j=0;j<k;j++)
            cout << dp[i][j];*/
    //cout << k << endl;
    for(i=1;i<=n;i++)
    {
        cin >> arr[i];
    }
    /*for(i=1;i<=n;i++)
        cout << arr[i] << endl;*/
    cout << solve(1,n,1) << endl;
    return 0;
}