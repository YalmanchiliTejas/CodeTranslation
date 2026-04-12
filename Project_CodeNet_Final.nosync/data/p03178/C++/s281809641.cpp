#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
string k;
int d;
int dp[10001][102][2];
int fun(int pos,int rem,int flag)
{
    if(pos==k.length())
    return (rem==0);
    if(dp[pos][rem][flag]!=-1)
    return dp[pos][rem][flag];
    int ans=0;
    if(flag==0)
    {
        int x=k[pos]-'0';
        for(int i=0;i<=x;i++)
        ans=(0LL+ans+fun(pos+1,(rem+i)%d,i!=x))%mod;
    }
    else
    {
        for(int i=0;i<10;i++)
        ans=(0LL+ans+fun(pos+1,(rem+i)%d,1))%mod;
    }
    return (dp[pos][rem][flag]=ans);
}
int main()
{
    cin>>k>>d;
    for(int i=0;i<10001;i++)
    {
        for(int j=0;j<102;j++)
        {
            dp[i][j][0]=-1;
            dp[i][j][1]=-1;
        }
    }
    cout<<(0LL+fun(0,0,0)-1+mod)%mod<<"\n";
    return 0;
}