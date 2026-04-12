#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

const int N=3000+5;

int n;
ll v[N];
ll dp[N][N];

void calc(int l,int r)
{
    if(dp[l][r]!=-1) return;
    calc(l+1,r);
    calc(l,r-1);
    ll a=v[l]-dp[l+1][r];
    ll b=v[r]-dp[l][r-1];
    dp[l][r]=max(a,b);
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>v[i];
    }
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<N;j++)
        {
            dp[i][j]=-1;
        }
    }
    for(int i=1;i<=n;i++)
    {
        dp[i][i]=v[i];
    }
    calc(1,n);
    cout<<dp[1][n]<<"\n";
    return 0;
}
