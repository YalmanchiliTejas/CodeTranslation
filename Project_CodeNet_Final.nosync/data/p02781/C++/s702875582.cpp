#include <iostream>
#include <string>
using namespace std;

main()
{
    string s; cin>>s;
    int k; cin>>k;
    long long dp[111][2][5]={};
    int len=s.size();
    dp[0][0][0]=1;
    for(int i=0; i<len; ++i)
    {
        for(int x=0; x<=k; ++x)
        {
            dp[i+1][1][x+1]+=9*dp[i][1][x];
            dp[i+1][1][x]+=dp[i][1][x];
            dp[i+1][s[i]>'0'][x]+=dp[i][0][x];
            if(s[i]>'0')
            {
                dp[i+1][1][x+1]+=(s[i]-'1')*dp[i][0][x];
                dp[i+1][0][x+1]+=dp[i][0][x];
            }
        }
    }
    cout << dp[len][0][k]+dp[len][1][k] << "\n";
}