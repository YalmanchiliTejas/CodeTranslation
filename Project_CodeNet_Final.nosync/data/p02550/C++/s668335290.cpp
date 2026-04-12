#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int M=1e5+10;
int vis[10*M];
int main()
{
    ll n,x,m;
    cin>>n>>x>>m;
    vis[x]=1;
    ll res=x;
    for(int i=2;i<=n;i++)
    {
        x=x*x%m;
        if(vis[x])
        {
            int len=i-vis[x];
            n=n-i+1;
            ll sum=0;
            for(int j=vis[x];j<i;j++)
            {
                sum+=x;
                x=x*x%m;
            }
            ll tt=n/len;
            while(tt--) res+=sum;
            tt=n%len;
            while(tt--)
            {
                res+=x;
                x=x*x%m;
            }
            break;
        }
        vis[x]=i;
        res+=x;
    }
    cout<<res;
    return 0;
}
