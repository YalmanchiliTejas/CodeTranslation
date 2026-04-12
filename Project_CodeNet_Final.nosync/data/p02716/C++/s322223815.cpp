#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
#define int ll
typedef long double ld;

typedef pair<int,int> pii;
#define x first
#define y second

const int N=2e5+100;

int a[N];
map<int,int> dp[N][2];

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    dp[0][0][0]=0;
    for(int i=1;i<=n;i++)
    {
        for(int j=max(0ll,i/2-5);j<=min(i,i/2+5);j++)
        {
            int cur=-1e18;
            if(dp[i-1][0].count(j))
                cur=max(cur,dp[i-1][0][j]);
            if(dp[i-1][1].count(j))
                cur=max(cur,dp[i-1][1][j]);
            dp[i][0][j]=cur;
        }
        for(int j=max(0ll,i/2-5);j<=min(i,i/2+5);j++)
        {
            int cur=-1e18;
            if(dp[i-1][0].count(j-1))
                cur=max(cur,dp[i-1][0][j-1]+a[i]);
            dp[i][1][j]=cur;
        }
    }
    cout<<max(dp[n][0][n/2],dp[n][1][n/2]);
}
