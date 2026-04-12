#include <iostream>

using namespace std;
long long n,i,k,a[3005], dp[3005][3005];
int main()
{
    cin>>n;
    for(i=1;i<=n;i++)
        cin>>a[i];

    for(k=0;k<n;k++)
    {
        for(i=1;i+k<=n;i++)
        {
            if(k==0)
                dp[i][i]=a[i];

            else
                dp[i][i+k]=max(a[i]-dp[i+1][i+k], a[i+k]-dp[i][i+k-1]);
        }
    }
    cout<<dp[1][n];
    return 0;
}
