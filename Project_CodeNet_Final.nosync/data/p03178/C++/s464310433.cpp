#include<bits/stdc++.h>
using namespace std;
#define int long
#define mod (long)(1e9+7)
string str;
int d;

void manupulate(string &str)
{
    for(auto &x:str)
    x-=48;
}

int dp[10001][2][101];

int rec(int idx,int tight,int sum)
{
    if(idx>=str.size())
    {
        if(sum%d==0)
            return 1;
        else
            return 0;
    }
    
    if(dp[idx][tight][sum]!=-1)
        return dp[idx][tight][sum];
    
    int n;
    if(tight)
        n=str[idx];
    else
        n=9;
    
    int ans=0;
    for(int i=0;i<=n;++i)
        ans=(rec(idx+1,tight&&i==n?true:false,(i+sum)%d)+ans)%mod;
    
    dp[idx][tight][sum]=ans;
    return ans;
}

signed main()
{
    cin>>str>>d;
    manupulate(str);
    memset(dp,-1,sizeof dp);
    cout<<(rec(0,true,0)-1+mod)%mod;
}