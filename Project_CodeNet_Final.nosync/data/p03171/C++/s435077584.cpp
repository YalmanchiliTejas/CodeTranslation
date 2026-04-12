#include <bits/stdc++.h>
using namespace std;
const int maxn = 3005;
long long dp[maxn][maxn][2], vis[maxn][maxn][2], a[maxn];

long long dfs(int l, int r, int ty){
    if(l == r) return ty ? a[l] : -a[l];
    if(vis[l][r][ty]) return dp[l][r][ty];
    vis[l][r][ty] = 1;
    if(ty){
        return dp[l][r][ty] = max(dfs(l+1, r, ty^1) + a[l], dfs(l, r-1, ty^1) + a[r]);
    } else {
        return dp[l][r][ty] = min(dfs(l+1, r, ty^1) - a[l], dfs(l, r-1, ty^1) - a[r]);
    }
}
int n;
int main()
{
    cin>>n;
    for(int i = 1; i <= n; i++) cin>>a[i];
    cout<<dfs(1, n, 1)<<endl;
}
