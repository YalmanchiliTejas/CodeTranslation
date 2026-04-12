#include <iostream>

using namespace std;
long long dp[3000][3001];
int main()
{
    long long n;
    cin>>n;
    long long moves[n];
    for(int i=0;i<n;i++)
    {
        cin>>moves[i];
    }
    for(int i=0;i<n;i++)
    {
        dp[i][1]=moves[i];
    }
    for(int i=2;i<=n;i++)
    {
        for(int j=0;j<=n-i;j++)
        {
            dp[j][i]=max(-dp[j][i-1]+moves[i+j-1],-dp[j+1][i-1]+moves[j]);
        }
    }
    cout<<dp[0][n]<<endl;
}
