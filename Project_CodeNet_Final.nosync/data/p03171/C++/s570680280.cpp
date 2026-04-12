#include<bits/stdc++.h>
#include<iterator>
using namespace std;
typedef long long int lli;
lli n;
int main()
{
    vector<lli>v;
    cin >> n;
    for(lli i=0;i<n;i++)
    {
        lli k ;cin >>k;v.push_back(k);
    }
    vector<lli>sum1;
    sum1.push_back(0);
    for(lli i=1;i<=n;i++)
    {
        sum1.push_back(v[i-1] + sum1[i-1]);
    }
    lli dp[n+2][n+2];
    for(int i=0;i<=n+1;i++)
    {
        for(int j=0;j<=n+1;j++)
        {
            dp[i][j]=0;
        }
    }
    // fill(&dp[0][0] ,&dp[0][0] + sizeof(dp),0);
    for(int i=0;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            if(j+i <= n)
            {

                dp[j][j+i] = sum1[j+i] -sum1[j-1] - min(dp[j][j+i-1],dp[j+1][j+i]);  
                // cout << j <<" "<< i << " "<<sum1[j+i] <<" "<< sum1[j-1] <<" "<<dp[j][j+i-1] <<" "<<dp[j+1][j+i] <<"\n";
            }
        }
    }
    // for(int i=0;i<=n;i++)
    // {
    //     for(int j=0;j<=n;j++)
    //     {
    //         cout << dp[i][j]<<" ";
    //     }
    //     cout <<"\n";
    // }
    // cout << sum1[n] << dp[1][n] << endl;
    lli p =(sum1[n] - 2*dp[1][n]);p*=-1;
    cout << p <<"\n";
}