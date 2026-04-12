#include <bits/stdc++.h>
 
using namespace std;
string s;
long long su,n,dp[4][100][2],mod=1e9+7,r;
int main()
{
    cin>>s>>n;
  	r=s.size();
    for (int i=0;i<s[0]-'0';i++) dp[0][i%n][0]++;
    dp[0][(s[0]-'0')%n][1]++;
    for (int i=1;i<s.size();i++)
    {
      	for (int j=0;j<100;j++) for (int k=0;k<2;k++) dp[i%2][j][k]=0;
        for (int j=0;j<=9;j++)
        {
            for (int k=0;k<n;k++)
            {
                dp[i%2][(k+j)%n][0]+=dp[(i-1)%2][k][0]%mod;
                dp[i%2][(k+j)%n][0]%=mod;
                if (j>s[i]-'0') continue;
                else if (j==s[i]-'0')
                {
                    dp[i%2][(k+j)%n][1]+=dp[(i-1)%2][k][1]%mod;
                    dp[i%2][(k+j)%n][1]%=mod;
                }
                else
                {
                    dp[i%2][(k+j)%n][0]+=dp[(i-1)%2][k][1];
                    dp[i%2][(k+j)%n][0]%=mod;
                }
            }
        }
    }
    cout<<(dp[(s.size()-1)%2][0][0]%mod+(dp[(s.size()-1)%2][0][1]%mod-1+mod)%mod)%mod;
    return 0;
}