/*#include <bits/stdc++.h>
using namespace std;
string ans,s[3055][3055],s1,s2;
int dp[3055][3055],n,m,ma;
int main()
{

    cin>>s1>>s2;
    if (s1.size()>s2.size()) swap(s1,s2);
    n=s1.size();
    m=s2.size();
    for (int i=0;i<n;i++)
    {
        for (int j=0;j<m;j++)
        {
            dp[i+1][j+1]=dp[i][j+1];
            s[i+1][j+1]=s[i][j+1];
            if (s1[i]==s2[j])
            {
                    dp[i+1][j+1]++;
                    s[i+1][j+1]=s[i+1][j+1]+s1[i];
            }
            if (dp[i+1][j+1]<=dp[i+1][j])
            {
                s[i+1][j+1]=s[i+1][j];
                dp[i+1][j+1]=dp[i+1][j];
            }
            //cout<<s[i+1][j+1]<<dp[i+1][j+1]<<" ";
        }

    }
    for (int i=0;i<=m;i++)
    {
        if (dp[n][i]>ma)
        {
            ma=dp[n][i];
            ans=s[n][i];
        }
    }
    cout<<ans;
}*/
#include<bits/stdc++.h>
using namespace std;
int n,tu;
long long dp[3009][3009],a[3009],ans;
int main()
{

    cin>>n;
    tu=n%2;
    for (int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    for (int i=n;i>=0;i--)
    {
        for (int j=0;j<n;j++)
        {
            if (tu==(j+1)%2) dp[i][i+j]=max(dp[i][i+j-1]+a[i+j],dp[i+1][i+j]+a[i]);
            else dp[i][i+j]=min(dp[i+1][i+j]-a[i],dp[i][i+j-1]-a[i+j]);
           // cout<<i<<" "<<i+j<<"  "<<dp[i][i+j]<<endl;
        }
    }
    cout<<dp[0][n-1];
}
