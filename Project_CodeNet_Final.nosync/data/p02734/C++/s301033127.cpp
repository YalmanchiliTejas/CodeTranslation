#include <bits/stdc++.h>
using namespace std;
const int maxn=3005;
const int mod=998244353;
int n,s,a[maxn],dp[maxn][maxn][3];
inline void add(int &x,int y) {
    x+=y;
    if (x>=mod) x-=mod;
}
int main()
{
    scanf("%d%d",&n,&s);
    for (int i=1;i<=n;++i) scanf("%d",&a[i]);
    dp[0][0][0]=1;
    for (int i=1;i<=n;++i) for (int j=0;j<=s;++j) {
        add(dp[i][j][0],dp[i-1][j][0]);
        if (j+a[i]<=s) {
            add(dp[i][j+a[i]][1],dp[i-1][j][0]);
            add(dp[i][j+a[i]][1],dp[i-1][j][1]);
        }
        add(dp[i][j][1],dp[i-1][j][0]);
        add(dp[i][j][1],dp[i-1][j][1]);
        add(dp[i][j][2],dp[i][j][1]);
    }
    int res=0;
    for (int i=1;i<=n;++i) add(res,dp[i][s][2]);
    printf("%d\n",res);
    return 0;
}
