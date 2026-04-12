#include <bits/stdc++.h>
using namespace std;
const int maxn=3005;
const int mod=998244353;
int n,s,a[maxn],dp[maxn][3];
inline void add(int &x,int y) {
    x+=y;
    if (x>=mod) x-=mod;
}
int main()
{
    scanf("%d%d",&n,&s);
    for (int i=1;i<=n;++i) scanf("%d",&a[i]);
    dp[0][0]=1;
    for (int i=1;i<=n;++i) for (int j=s;j>=0;--j) {
        if (j>=a[i]) {
            add(dp[j][1],dp[j-a[i]][1]);
            add(dp[j][1],dp[j-a[i]][0]);
        }
        add(dp[j][1],dp[j][0]);
        add(dp[j][2],dp[j][1]);
    }
    printf("%d\n",dp[s][2]);
    return 0;
}
