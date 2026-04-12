#include<bits/stdc++.h>
#define int long long
#define fi first
#define se second
#define pii pair<int,int>
#define mp make_pair
using namespace std;

const int inf=1e16;
const int N=2e5+5;
const int mod=1e9+7;
int n,a[N],dp[N][3][2];

/// 0:none
/// 1:left
/// 2:right

main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=0;i<=n;i++)
    {
        for(int j=0;j<=2;j++)
        {
            for(int k=0;k<=1;k++) dp[i][j][k]=-inf;
        }
    }
    dp[0][0][0]=0;
    for(int i=1;i<=n;i+=2)
    {
        int id=(i+1)/2;
        dp[id][0][1]=max({dp[id-1][1][0],dp[id-1][2][0],dp[id-1][0][0]});
        dp[id][1][0]=max(dp[id-1][0][0],dp[id-1][1][0])+a[i];
        dp[id][2][0]=max({dp[id-1][0][0],dp[id-1][1][0],dp[id-1][2][0]})+a[i+1];
        dp[id][1][1]=max(dp[id-1][0][1],dp[id-1][1][1])+a[i];
        dp[id][2][1]=max({dp[id-1][0][1],dp[id-1][1][1],dp[id-1][2][1]})+a[i+1];
    }
    int res=max(dp[n/2][1][0],dp[n/2][2][0]);
    if(n%2==0) cout<<res;
    else
    {
        int val=max(dp[n/2][0][1],dp[n/2][1][1])+a[n];
        cout<<max(res,val);
    }
}
