#include <bits/stdc++.h>
using namespace std;
#define int long long int
#define bew ios_base::sync_with_stdio(false);cin.tie(NULL);

int dp[3001][3001];

int rec(int ar[],int i,int j)
{
    if(i>j)
    return 0;
    if(i==j)
    return ar[i];
    if(dp[i][j]!=-1)
    return dp[i][j];
    dp[i][j]=max(ar[i]+min(rec(ar,i+2,j),rec(ar,i+1,j-1)),ar[j]+min(rec(ar,i+1,j-1),rec(ar,i,j-2)));
    return dp[i][j];
}
signed main()
{
    bew;
    int n;
    cin>>n;
    memset(dp,-1,sizeof dp);
    int ar[n],sum=0;
    for(int i=0;i<n;++i)
    cin>>ar[i],sum+=ar[i];
    int sc=rec(ar,0,n-1);
    cout<<2*sc-sum;
    
    
    return 0;
}