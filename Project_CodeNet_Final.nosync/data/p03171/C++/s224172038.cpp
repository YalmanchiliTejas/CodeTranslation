#include <bits/stdc++.h>

using namespace std;
int n,i,j,d;
long long a[3005];
long long dp[3005][3005];
int main()
{
    cin>>n;
    for(i=1;i<=n;i++)
    {
        cin>>a[i];
    }

    for(d=0;d<=n;d++)
    {
        for(i=1;i+d<=n;i++)
        {
            if(d==0)
                dp[i][i]=a[i];
            else
            {
                dp[i][i+d]=max(a[i]-dp[i+1][i+d], a[i+d]-dp[i][i+d-1]);
            }
        }
    }

    cout<<dp[1][n];
    return 0;
}
