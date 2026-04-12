#include<bits/stdc++.h>
using namespace std;
int dp[10009][109][2],a[10009],mod=1e9+7,sm,n;
int bt(int id,int x,int o)
{
    //cout<<id<<" "<<x<<" "<<o<<"\n";
    if(id==n)
    {
        if(x==0)return 1;
        else return 0;
    }
    int &ret=dp[id][x][o];
    if(ret!=-1)return ret;
    ret=0;
    int mx=10,oo=0;
    if(o)mx=a[id]+1;
    for(int i=0;i<mx;i++)
    {
        if(i==mx-1&&o)oo=1;
        ret+=bt(id+1,(x+i)%sm,oo);
        ret%=mod;
    }
    return ret;
}
string s;
int main()
{
    memset(dp,-1,sizeof(dp));
    cin>>s>>sm;
    n=s.size();
    for(int i=0;i<n;i++)
    {
        a[i]=s[i]-'0';
    }
    cout<<(bt(0,0,1)-1+mod)%mod<<"\n";
}
