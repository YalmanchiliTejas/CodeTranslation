#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long
#define mod 1000000007

const int sz=3e3+5;
ll inf=1e15;

ll dp[sz][sz][2],ar[sz];


ll f(int st,int en,int t)
{
    if(st==en)
    {
        if(t)
            return 0;
        else
            return ar[st];
    }
    ll &res=dp[st][en][t];
    if(res!=-1)
        return res;
    if(t)
    {
        res=min(f(st+1,en,t^1),f(st,en-1,t^1));
    }
    else
    {
        res=max(ar[st]+f(st+1,en,t^1),ar[en]+f(st,en-1,t^1));
    }

    return res;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t=1;
    // cin>>t;
    while(t--)
    {
        ll n,k;
        cin>>n;

        ll sum=0;
        for(int i=0;i<n;i++)
        {
            cin>>ar[i];
            sum+=ar[i];
        }
        memset(dp,-1,sizeof(dp));

        ll y=sum-f(0,n-1,0);
        cout<<f(0,n-1,0)-y<<endl;

        
    }

    return 0;
}