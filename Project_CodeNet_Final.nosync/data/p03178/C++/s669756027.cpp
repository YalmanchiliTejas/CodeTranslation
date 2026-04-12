#include <bits/stdc++.h>
using namespace std;
#define int long long
const int mod=1e9+7;
int dp[10002][102][2];
string s;
int d;
int fun(int idx,int cur,bool gr)
{
    if(idx==s.size()) return !cur;
    int &ret=dp[idx][cur][gr];
    if(~ret)
        return ret;
        ret=0;
    if(!gr)
    {
        for(int i=0;i<s[idx]-'0';i++)
            ret+=fun(idx+1,(cur+i)%d,1)%mod;
        ret+=fun(idx+1,(cur+s[idx]-'0')%d,0)%mod;
    }
    else
    {
        for(int i=0;i<=9;i++)
            ret+=fun(idx+1,(cur+i)%d,1)%mod;
    }
    ret%=mod;
    return ret;
}
signed main()
{
    memset(dp,-1,sizeof dp);
    cin>>s>>d;
    cout<<(fun(0,0,0)+mod-1)%mod<<endl;
}
