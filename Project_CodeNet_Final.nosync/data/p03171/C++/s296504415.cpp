#include <bits/stdc++.h>
#define lli long long int

using namespace std;

int main()
{
    lli n,i,j,sum=0;
    cin>>n;
    lli a[n],dp[n][n],diag=n-1;
    for(i=0;i<n;i++)
    {
        cin>>a[i];
        sum=sum+a[i];
    }
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            if(i==j)
                dp[i][j]=a[i];
            else
                dp[i][j]=0;
        }
    }
    for(i=0;i<diag;i++)
    {
        for(j=n-diag;j<n;j++)
        {
            if(i+2<n && j>=2)
                dp[i][j]=max(min(a[i]+dp[i+1][j-1],a[i]+dp[i+2][j]),min(a[j]+dp[i+1][j-1],a[j]+dp[i][j-2]));
            else if(i+2<n)
                dp[i][j]=max(a[i]+dp[i+1][j-1],min(a[j]+dp[i+1][j-1],a[j]+dp[i][j-2]));
            else
                dp[i][j]=max(min(a[i]+dp[i+1][j-1],a[i]+dp[i+2][j]),a[j]+dp[i+1][j-1]);
            i++;
        }
        diag--;
        i=-1;
    }
    cout<<2*dp[0][n-1]-sum<<endl;
    return 0;
}
