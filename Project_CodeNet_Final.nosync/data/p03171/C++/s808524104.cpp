#include<bits/stdc++.h>
#define l long 
#define ll long long 
#define ld long double 
#define INF 1000000000000
#define MOD 1000000007
#define MAX_N 1000006
#define IOS ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;
int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    int n;
    cin>>n;
    vector<ll> a;
    ll x;
    for(int i=0;i<n;i++)
    {
        cin>>x;
        a.push_back(x);
    }
    ll dp[n][n][2];
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            dp[i][j][0]=0;
            dp[i][j][1]=INF;
        }
    }
    for(int len=1;len<=n;len++)
    {
        for(int i=0;i<n;i++)
        {
            if(i+len-1>=n)
            continue;
            if(len==1)
            {
                dp[i][i][0]=a[i];
                dp[i][i][1]=-a[i];
            }
            else 
            {
                dp[i][i+len-1][0]=max(dp[i][i+len-2][1]+a[i+len-1],dp[i+1][i+len-1][1]+a[i]);
                dp[i][i+len-1][1]=min(dp[i][i+len-2][0]-a[i+len-1],dp[i+1][i+len-1][0]-a[i]);
            }
        }
    }
    cout<<dp[0][n-1][0]<<endl;
}