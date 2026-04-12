#include<bits/stdc++.h>
using namespace std;
long long int Mod=1e9+7;
long long  dp[3005][3005];
long long rec(long long A[],long i,long j)
{
    if(i>j)
        return(0);
    else if(i==j)
    {
        dp[i][i]=A[i];
        return(dp[i][i]);
    }
    else if(i==j-1)
    {
        dp[i][i+1]=max(A[i],A[i+1]);
        return(dp[i][i+1]);
    }
    else if(i==j-2)
    {
        dp[i][i+2]=max(A[i]+min(A[i+1],A[i+2]),A[i+2]+min(A[i],A[i+1]));
        return(dp[i][i+2]);
    }
    if(dp[i][j]!=-1)
        return(dp[i][j]);
    else
    {
    dp[i][j]=max(min(rec(A,i+2,j),rec(A,i+1,j-1))+A[i],min(rec(A,i+1,j-1),rec(A,i,j-2))+A[j]);
        return(dp[i][j]);
        
    }
}
int main()
{
    long i,j,n,k,ans,sum=0;
    cin>>n;
    long long A[n+1];
    A[0]=-1;
    for(i=1;i<=n;i++)
    {
        cin>>A[i];
        sum+=A[i];
    }
    
    for(i=0;i<=n;i++)
        for(j=0;j<=n;j++)
            dp[i][j]=-1;
    
    ans = rec(A,1,n);
    cout<<2*ans-sum<<endl;
}