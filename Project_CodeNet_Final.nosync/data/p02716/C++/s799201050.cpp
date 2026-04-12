#include<bits/stdc++.h>
//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/tree_policy.hpp>
//using namespace __gnu_pbds;
using namespace std;
typedef long long ll;
ll arr[200005];
ll dp[200005][3];
bool vis[200005][3];
int n;
int bad;
ll fun(int pos,int nisi)
{
    if(pos>=n)
    {
        return 0;
    }
    if(vis[pos][nisi])
    {
        return dp[pos][nisi];
    }
    ll res=-1e18;
    if(nisi==0)
    {
        res=max(res,arr[pos]+fun(pos+2,nisi));
        res=max(res,fun(pos+1,1));
        if(bad==2)
        {
            res=max(res,fun(pos+2,bad));
        }
    }
    else if(nisi==bad)
    {
        res=max(res,arr[pos]+fun(pos+2,bad));
    }
    else
    {
        res=max(res,arr[pos]+fun(pos+2,nisi));
        res=max(res,fun(pos+1,bad));
    }
    vis[pos][nisi]=1;
    return dp[pos][nisi]=res;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    //int n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    if(n%2==0)
    {
        bad=1;
    }
    else
    {
        bad=2;
    }
    cout<<fun(0,0)<<endl;
    return 0;
}
