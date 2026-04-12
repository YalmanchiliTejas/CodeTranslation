#include<bits/stdc++.h>
typedef long long int ll;
using namespace std;
ll pref_sum[3000][3000] , dp[3000][3000];
int a[3000];
int main()
{
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
    cin>>a[i];
    if(n==1)
    {
        cout<<a[0]<<endl;
        return 0;
    }
    memset(pref_sum,0,sizeof(pref_sum));
    memset(dp,0,sizeof(dp));
    for(int i=0;i<n;i++)
    {
        pref_sum[i][i]=a[i];
        dp[i][i]=a[i];
        for(int j=i+1;j<n;j++)
            pref_sum[i][j] = pref_sum[i][j-1] + a[j];
    }
    int i=0,j=1;
    int jstart=1;
    while( !(i==0 && j==n-1))
    {
        dp[i][j] = pref_sum[i][j] - min(dp[i][j-1] , dp[i+1][j]);
        i++;
        j++;
        if(j==n)
        {
            i=0;
            jstart++;
            j=jstart;
        }

    }
    ll scoreB=min(dp[0][n-2] , dp[1][n-1]);
    ll scoreA=pref_sum[0][n-1] - scoreB;
    cout<<scoreA-scoreB<<endl;
}
