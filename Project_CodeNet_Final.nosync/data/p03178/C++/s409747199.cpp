#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
typedef long long int lli;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    string k;
    lli d,M=1e9+7;
    cin>>k>>d;
    lli i,j,where,l,dp[d][2],len=k.length(),cur=0;
    memset(dp, 0LL, sizeof(dp));
    
    dp[0][0]=1;
    
    for(where=0;where<len;where++)
    {
        lli new_dp[d][2];
        memset(new_dp, 0LL, sizeof(dp));
        
        for(i=0;i<d;i++)
        {
            cur=0;
            for(j=0;j<2;j++)
            {
                for(l=0;l<10;l++)
                {
                    if(l>k[where]-'0' && cur==0)
                        break;
                    
                    new_dp[(i+l)%d][cur || (l<k[where]-'0')]+=dp[i][cur];
                    new_dp[(i+l)%d][cur || (l<k[where]-'0')]%=M;
                }
                cur=1;
            }
        }
        
        for(i=0;i<d;i++) dp[i][0]=new_dp[i][0],dp[i][1]=new_dp[i][1];
    }
    
    cout<<((dp[0][0]+dp[0][1])%M -1+M)%M;
    return 0;
}