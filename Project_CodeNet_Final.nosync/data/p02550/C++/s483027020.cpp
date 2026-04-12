#include <bits/stdc++.h>
using namespace std;

const int maxn=1e5+5;
const int maxm=40;
#define ll long long

int f[maxn][maxm];
ll sum[maxn][maxm];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    ll n,x,m;
    cin>>n>>x>>m;
    for(ll i=0;i<m;i++)
    {
        f[i][0]=(i*i)%m;
        sum[i][0]=f[i][0];
    }

    for(int j=1;j<maxm;j++) for(int i=0;i<m;i++)
    {
        f[i][j]=f[f[i][j-1]][j-1];
        sum[i][j]=sum[i][j-1]+sum[f[i][j-1]][j-1];
    }

    ll ans=x;n--;
    for(int i=39;i>=0;i--) if((n>>i)&1)
    {

        ans+=sum[x][i];
        x=f[x][i];
    }
    cout<<ans;
    return 0;
}