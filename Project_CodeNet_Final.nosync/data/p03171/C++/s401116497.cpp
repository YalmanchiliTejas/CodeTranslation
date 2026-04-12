#include<bits/stdc++.h>
#define int1 long long int
using namespace std;
int main()
{
    int1 n;
    cin>>n;
    int1 a[n];
    int1 sum=0;
    for(int1 i=0;i<n;i++)
        {cin>>a[i];
        sum+=a[i];
        }
    int1 dp[n][n];
    for(int1 i=0;i<n;i++)
        for(int1 j=0;j<n;j++)
        dp[i][j]=0;
    for(int1 i=0;i<n;i++)
    {
        dp[i][i]=a[i];
    }
    for(int1 i=0;i<n-1;i++)
    {
        dp[i][i+1]=max(a[i],a[i+1]);
    }
    for(int1 siz=3;siz<=n;siz++)
    {
        int1 i=0;
        int1 j;
        while(i+siz-1<n)
        {
            j=i+siz-1;
            dp[i][j]=max(a[i]+min(dp[i+2][j],dp[i+1][j-1]),a[j]+min(dp[i][j-2],dp[i+1][j-1]));
            i++;
        }
    }

    int1 X=dp[0][n-1];
    int1 Y=sum-X;
    cout<<X-Y;
    return 0;
}
