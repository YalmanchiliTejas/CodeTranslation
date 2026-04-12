#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define ll long long
int n;
ll dp[3010][3010],a[3010];
bool vis[3010][3010];
ll solve(int i,int j,bool ok)
{
    if(i==j)
    {
        if(!ok)
            return a[i];
        return -a[i];
    }
    ll &ret=dp[i][j];
    if(vis[i][j])
        return ret;
    vis[i][j]=1;
    if(!ok)
        ret=max(a[i]+solve(i+1,j,!ok),a[j]+solve(i,j-1,!ok));
    else
        ret=min(-a[i]+solve(i+1,j,!ok),-a[j]+solve(i,j-1,!ok));
    return ret;
}
int main()
{
    ios::sync_with_stdio(0);
    cin>>n;
    for(int i=0; i<n; i++)
        cin>>a[i];
    cout<<solve(0,n-1,0);
    return 0;
}
