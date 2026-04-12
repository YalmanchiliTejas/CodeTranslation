#include <bits/stdc++.h>

using namespace std;
#define ll long long
const int N=2e5+5,mod=1e9+7;
const ll INF=1e15;
bool vis[N][5];
ll dp[N][5];
int a[N];
int n;
ll solve(int idx,int f)
{
    if(idx>=n)
    {
        if(f==2) return -INF;
        return 0;
    }
    ll &ret=dp[idx][f];
    if(vis[idx][f]==1) return ret;
    vis[idx][f]=1;
    ret=solve(idx+2,f)+a[idx];
    if(f) ret=max(ret,solve(idx+1,f-1));
    return ret;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin>>n;
    for(int i=0;i<n;i++) cin>>a[i];
    cout<<solve(0,n%2+1)<<endl;
    return 0;
}
