#include<bits/stdc++.h>
using namespace std;
#define ff first
#define ss second
#define int ll
#define pb push_back
#define setbits(x)          __builtin_popcountll(x)
#define endl "\n"
typedef long long ll;
int32_t main()
{
ios_base::sync_with_stdio(false);
cin.tie(NULL);
int n;
cin>>n;
int arr[n];
for(int i=0;i<n;i++)
    cin>>arr[i];
int dp[n+1][2]={};
dp[0][0]=0;
dp[0][1]=0;
dp[1][0]=arr[0];
dp[1][1]=arr[1];
for(int i=2;i<n;i++)
{if(i%2==0)
{
    dp[i][0]=max(dp[i-1][1],dp[i-1][0]);
    dp[i][1]=max(dp[i-2][0],dp[i-2][1])+arr[i];
    }
    else
    {
        dp[i][1]=dp[i-1][0]+arr[i];
        dp[i][0]=arr[i-1]+dp[i-2][0];
    }
}
int ans=max(dp[n-1][1],dp[n-1][0]);
cout<<ans<<endl;
    return 0;
}
