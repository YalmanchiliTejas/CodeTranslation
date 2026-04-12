#include<bits/stdc++.h>
#define REP(x,y,z) for(int x=y;x<=z;x++)
#define MSET(x,y) memset(x,y,sizeof(x))
#define M 3005
using namespace std;
using LL = long long;
int n,a[M];
LL dp[M][M];
bool vis[M][M];
LL dfs(int l,int r) {
    if (l>r) return 0;
    if (vis[l][r]) return dp[l][r];
    vis[l][r] = true;
    LL &res = dp[l][r];

    res = -(1LL << 60);
    res = max(res, a[l] - dfs(l+1, r));
    res = max(res, a[r] - dfs(l, r-1));
    return res;
}
int main()
{
    scanf("%d", &n);
    REP(i,1,n) scanf("%d", &a[i]);
    printf("%lld\n", dfs(1,n));
    return 0;
}
