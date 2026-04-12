#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int mod = 7 + 1e9;
string s; int d , dp[10000][100][2];
int f( int i = 0 , int sum = 0 , bool pp=0 )
{
    if( i == s.size() )
        if( sum == 0 )
            return 1;
        else
            return 0;
    int &dp = :: dp[i][sum][pp];
    if( dp != -1 )
        return dp;
    dp = 0;
    if( pp )
    {
        for(char c = '0';c<s[i];++c)
        {
            dp+= f(i+1,(sum+c-'0')%d)%mod;
            dp%=mod;
        }
        dp+= f(i+1,(sum+s[i]-'0')%d,1)%mod;
        dp%=mod;
    }
    else
        for(int c=0;c<=9;++c)
        {
            dp+= f(i+1,(sum+c)%d)%mod;
            dp%=mod;
        }
    return dp%=mod;
}
int main()
{
    memset(dp,-1,sizeof dp);
    cin >> s >> d;
    int ans = f(0,0,1)-1;
    cout << ( ans == -1 ? 1000000006 : ans );
}