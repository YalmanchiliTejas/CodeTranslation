#include<bits/stdc++.h>
using namespace std;
#define lli long long int
int main()
{
    int n;
    cin>>n;
    lli arr[n];
    lli sum=0;
    for(int i=0;i<n;i++) 
    { cin>>arr[i]; sum+=arr[i];}
    lli dp[n][n];
    for(int len=1;len<=n;len++)
    {
        int j;
        for(int i=0;i<=n-len;i++)
        {   j=i+len-1;
            if(len==1) dp[i][i]=arr[i];
            else if(len==2)
            {
                dp[i][i+1]=max(arr[i],arr[i+1]);
            }
            else 
            {
                dp[i][j]=max(arr[i]+min(dp[i+2][j],dp[i+1][j-1]),
                              arr[j]+min(dp[i][j-2],dp[i+1][j-1]));
            }
        }
    }
    cout<<2*dp[0][n-1]-sum<<endl;
    return 0;
}