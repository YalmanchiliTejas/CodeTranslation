#include <bits/stdc++.h>
using namespace std;
#define li long long int
#define prDouble(x) cout<<fixed<<setprecision(10)<<x;
li dp[3001][3001];
li solve(li i,li j, li *a)
{
    if(i>j)
    {
        return 0;
    }
    if(dp[i][j]!=-1)
    {
        return dp[i][j];
    }
    li ans;
    li op1=a[i]+min(solve(i+2,j,a),solve(i+1,j-1,a));
    li op2=a[j]+min(solve(i,j-2,a),solve(i+1,j-1,a));
    ans=max(op1,op2);
    dp[i][j]=ans;
    return ans;
}

int main()
{
    li j,i,n;
    cin>>n;
    memset(dp,-1,sizeof(dp));
    li a[n],s=0;
    for(i=0;i<n;i++)
    {
        cin>>a[i];
        s+=a[i];
    }
    cout<<2*solve(0,n-1,a)-s;
    return 0;
}
