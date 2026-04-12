//agrawal117
//chahatagrawal117
#include<bits/stdc++.h>
#define endl '\n'
#define mod 1000000007
typedef long long int ll;
using namespace std;
#define MAX 100005
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ll n; cin>>n;
    ll arr[n+3];
    for(int i=1;i<=n;i++) cin>>arr[i];
    ll dp[n+2][2];
    dp[n+1][0]=dp[n+1][1]=0;
    dp[n][0]=0;
    dp[n][1]=0;
    dp[n-1][1]=arr[n-1];
    dp[n-1][0]=arr[n];
    for(int i=n-2;i>=1;i--)
    {
        int idx=n-i+1;
        if(idx%2==1){
            dp[i][1]=arr[i]+max(dp[i+2][0],dp[i+2][1]);
            dp[i][1]=max(dp[i][1],arr[i]+max(dp[i+3][0],dp[i+3][1]));
            dp[i][0]=max(dp[i+1][0],dp[i+1][1]);
        }
        else{
            dp[i][1]=arr[i]+max(dp[i+1][0],max(dp[i+2][0],dp[i+2][1]));
            dp[i][0]=arr[i+1]+dp[i+2][0];
        }
        // cout<<i<<" --> ";
        // cout<<dp[i][1]<<" "<<dp[i][0]<<endl;
    }
    cout<<max(dp[1][0],dp[1][1])<<endl;
}
