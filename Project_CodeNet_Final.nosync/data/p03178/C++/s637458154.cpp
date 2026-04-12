#include <bits/stdc++.h>
using namespace std;
#define int long long

int x[100005];
int mo=1000000007;
int n;
int cache[100005][105][2];
int d;
string b;
int dp(int idx,int rem,int less)
{
    if(idx==n+1)
        return (rem==0);
    int ans=cache[idx][rem][less];
    if(ans!=-1)
        return  ans;
    ans=0;
    if(!less)
    {
        for(int i=0;i<=x[idx];i++)
        {
            ans+=dp(idx+1,(rem+i)%d,less|i<x[idx]);
        }
    }
    else
    {
        for(int i=0;i<=9;i++)
        {
            ans+=dp(idx+1,(rem+i)%d,1);
        }
    }
    ans%=mo;
    cache[idx][rem][less]=ans;
    return ans;
}
int f(string a)
{
    n=a.size();
    for(int i=1;i<=n;i++)
    {
        x[i]=(a[i-1]-'0');
    }
    memset(cache,-1,sizeof(cache));
    return dp(1,0,0);

}
int32_t main()
{
    cin>>b>>d;
    int ans=f(b);
    //cout<<ans<<" ";
    ans-=1;
    ans+=mo;
    ans%=mo;
    cout<<ans;
    return 0;

}