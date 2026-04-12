#include <bits/stdc++.h>
#define mod 1000000007
#define int long long
#define pb push_back
using namespace std;
int dp[3001][3001];
int n;
int solve(int *a, int i, int j)
{
    if(i>j)
        return 0;
    if(i==j)
        return a[i];
    if(dp[i][j]!=-1)
        return dp[i][j];
    return dp[i][j]=max(a[i]+min(solve(a,i+2,j),solve(a,i+1,j-1)),a[j]+min(solve(a,i,j-2),solve(a,i+1,j-1)));
}
int32_t main()
{
    int t;
    //cin>>t;
    //while(t--)
    {   
        int k;
        cin>>n;
        memset(dp,-1,sizeof(dp));
        int a[100001];
        int sum=0;
        for(int i=0;i<n;i++)
            cin>>a[i], sum+=a[i];
        cout<<2*solve(a,0,n-1)-sum;
    }
}




