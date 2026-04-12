#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define SPEED ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define MOD 1000000007
signed main()
{
    SPEED;
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    int dp1[n][n],dp2[n][n];
    memset(dp1,0,sizeof(dp1));
    memset(dp2,0,sizeof(dp2));
    for(int i=0;i<n;i++)
    {
        dp1[i][i]=a[i];
    }
    for(int dif=1;dif<n;dif++)
    {
        for(int i=0;i<n-dif;i++)
        {
            dp1[i][dif+i]=max(dp2[i][dif+i-1]+a[dif+i],dp2[i+1][dif+i]+a[i]);
            dp2[i][dif+i]=min(dp1[i][dif+i-1],dp1[i+1][dif+i]);
        }
    }
    cout<<dp1[0][n-1]-dp2[0][n-1];
}