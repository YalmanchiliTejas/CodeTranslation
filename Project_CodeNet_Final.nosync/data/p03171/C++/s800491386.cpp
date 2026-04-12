#include <bits/stdc++.h>
#define FOR(i,a,b) for(int i = (a); i < (b); i++)
#define ll long long
#define N 3010
using namespace std;

ll n,a[N],dp[N][N];

int main()
{
    cin>>n; FOR(i,0,n) cin>>a[i],dp[i][i]=a[i];
    FOR(i,1,n) FOR(j,0,n-i+1) dp[j][j+i]=max(a[j]-dp[j+1][j+i],a[j+i]-dp[j][j+i-1]);
    cout<<dp[0][n-1]<<'\n';

    return 0;
}