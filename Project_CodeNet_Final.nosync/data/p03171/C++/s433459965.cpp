#include<bits/stdc++.h>
using namespace std;
/*
#ifndef ONLINE_JUDGE
    #define cin f
    #define cout g
    ifstream cin("a.in");
    ofstream cout("a.out");
#endif
*/
int n;
long long v[1<<13],dp[2][3002][3002];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin>>n;
    for(int i=1;i<=n;++i) cin>>v[i];
    for(int i=n;i>0;--i)
        for(int j=i;j<=n;++j)
        {
            dp[0][i][j]=max(dp[1][i+1][j]+v[i],dp[1][i][j-1]+v[j]);
            dp[1][i][j]=min(dp[0][i+1][j]-v[i],dp[0][i][j-1]-v[j]);
        }
    cout<<dp[0][1][n];
    return 0;
}
