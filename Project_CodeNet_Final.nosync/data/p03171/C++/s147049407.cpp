/*author:anshumanc007
   created on:09/01/2019
            */
//EMBRACE THE STRUGGLE!!!
#include <bits/stdc++.h>
#include <queue>
#include <stack>
using namespace std;
#define MAX 100005
long long int MOD=1e9+7;
long long int INF=1e18;

long long int dp[3005][3005];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    long long int i,j,k,l,m,n,o,p,q,r,x,y,a,b,mini=INF,maxi=0,cnt=0,W,ans,iter=0,len;
    cin>>n;
    long long int A[n+1];
    for(i=1;i<=n;i++)
    {
        cin>>A[i];
    }
    for(i=0;i<=n;i++)
    {
        for(j=0;j<=n;j++)
        {
            dp[i][j]=0;
        }
    }
    for(i=0;i<=n;i++)
    {
        dp[i][i]=A[i];
    }
    for(len=2;len<=n;len++)
    {
        for(i=1;i<=n-len+1;i++)
        {
            j=i+len-1;
            if(len%2==0)
            dp[i][j]=min(dp[i+1][j]-A[i],dp[i][j-1]-(A[j]));
            else
                dp[i][j]=max(dp[i+1][j]+A[i],dp[i][j-1]+A[j]);
            
        }
    }
    if(n%2==0)
    cout<<-1*dp[1][n]<<endl;
    else
    {
        cout<<dp[1][n]<<endl;
    }
   

    
}