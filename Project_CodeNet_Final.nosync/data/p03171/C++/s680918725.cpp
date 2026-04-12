#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define IOS; ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define MX  3001
#define FF freopen("input.in","r",stdin); freopen("output.txt","w",stdout);
ll dp[MX][MX][2];
int n;
int a[MX];
ll f(int i,int j,bool turn)
{
    if(i>j)return 0;
    if(dp[i][j][turn]!=-1)return dp[i][j][turn];
    ll x=0;
    if(turn)
    {
        return dp[i][j][turn]=x=max(f(i+1,j,!turn)+a[i],f(i,j-1,!turn)+a[j]);
    }
    else
        return dp[i][j][turn]=x=min(f(i+1,j,!turn)-a[i],f(i,j-1,!turn)-a[j]);
    return x;
}
int main()
{
    //FF;
    IOS;
    int k;
    cin>>n;
    for(int i=0;i<n;i++)
        cin>>a[i];
    memset(dp,-1,sizeof dp);
    cout<<f(0,n-1,1);
}

