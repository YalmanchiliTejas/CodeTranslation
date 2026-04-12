#include<bits/stdc++.h>
using namespace std;
long long int dp[3003][3003],ar[3003];
long long int rec(long long int l,long long int r)
{
    if(l>r)
    return 0;
    if(dp[l][r]!=-1)
    return dp[l][r];
    long long int a=ar[l]-rec(l+1,r);
    long long int b=ar[r]-rec(l,r-1);
    return dp[l][r]=max(a,b);
}
int main()
{
    long long int n,i,j;
    cin>>n;
    for(i=1;i<=n;i++)
    {
        cin>>ar[i];
    }
    for(i=0;i<=3001;i++)
    {
        for(j=0;j<=3001;j++)
        {
            dp[i][j]=-1;
        }
    }
    cout<<rec(1,n);
}