#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int MOD=1e9+7;
string s1;
ll dp[10005][105][3];
int fun(ll i,ll sum,ll K,ll right)
{
    if(i>=s1.size())
    {  if(sum%K==0) return 1; else return 0;}
    if(dp[i][sum][right]!=-1) return dp[i][sum][right];
    if(right==1)
    {
        ll sum1=0,j;
        for(j=0;j<=s1[i]-'0';j++)
        {
            if(s1[i]-'0'==j)
            sum1+=fun(i+1,(sum+j)%K,K,1);
            else sum1+=fun(i+1,(sum+j)%K,K,0);
            if(sum1>=MOD) sum1-=MOD;
        }
        return dp[i][sum][right]=sum1;
    }
    if(right==0)
    {
        ll sum1=0,j;
        for(j=0;j<=9;j++)
        {
            sum1+=fun(i+1,(sum+j)%K,K,0); if(sum1>=MOD) sum1-=MOD;
        }
        return dp[i][sum][right]=sum1;
    }
}
int main()
{
    cin>>s1;
    ll i,K,ans=0; memset(dp,-1,sizeof dp);
    cin>>K;
    for(i=0;i<=s1[0]-'0';i++)
    {
        if(i==s1[0]-'0')
        ans+=fun(1,i,K,1);
        else ans+=fun(1,i,K,0);
        if(ans>=MOD) ans-=MOD;
    }
    ans=(ans-1+MOD)%MOD;
    cout<<ans<<'\n';

}
