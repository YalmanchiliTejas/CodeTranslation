// Author: raghav_0901
#include<bits/stdc++.h>
#define int long long int
#define f(i,s,e) for(i=s;i<e;++i)
#define fr(i,s,e) for(i=s;i>=e;i--)
#define ff(i,s,e,f) for(i=s;i<e && f;++i)
#define mem(arr,val) memset(arr, val, sizeof(arr))
#define mems(arr, val, n) memset(arr, val, n)
#define vec vector<int>
#define pr pair<int,int>
#define lim 1000000
#define mod 998244353
#define Arena ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;

vec v;
int dp[3000][3001];
int solve(int idx,int s,int n)
{
    if(s==0)
        return n-idx+1;
    if(s<0)
        return 0;
    if(idx>=n)
        return 0;
    if(dp[idx][s]!=-1)
        return dp[idx][s];
    return dp[idx][s] = (solve(idx+1,s,n)+solve(idx+1,s-v[idx],n))%mod;
}

signed main()
{
    Arena
    register int i,j,num,ans=0,t=1;
    //cin>>t;
    while(t--)
    {
        register int n,s;cin>>n>>s;
        v.resize(n);
        mem(dp,-1);
        for(register int &x:v)
            cin>>x;
        f(i,0,n)
            ans=(ans+solve(i,s,n))%mod;
        cout<<ans<<endl;
    }
    return 0;
}