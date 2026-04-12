#include <bits/stdc++.h>

using namespace std;
const int MOD=1000000007;
int k,n,num[10000009];
long long b,dp[200000][109][2];
string s;
int get_digit()
{
    fill(num,num+1000009,-1);
    int n=s.size();
    s=" "+s;
    for (int i=1; i<=n; i++)
        num[i]=(int)(s[i]-48);
    return n;
}
long long digit_dp(int idx, int sum, int tight)
{
    if (idx==n+1)
        if (sum%k==0)
            return 1;
        else
            return 0;
    if (dp[idx][sum][tight]!=-1)
        return dp[idx][sum][tight];
    int res=0,limit;
    if (tight==0)
        limit=num[idx];
    else
        limit=9;
    for (int i=0; i<=limit; i++)
    {
        int new_tight=1;
        if (i==limit&&tight==0)
            new_tight=0;
        res=(res+digit_dp(idx+1,(sum+i)%k,new_tight))%MOD;
    }
    dp[idx][sum][tight]=res%MOD;
    return res%MOD;
}
int main()
{
    cin>>s>>k;
    n=get_digit();
    memset(dp,-1,sizeof(dp));
    b=digit_dp(1,0,0);
    cout << ((b-1)+MOD)%MOD;
    return 0;
}
