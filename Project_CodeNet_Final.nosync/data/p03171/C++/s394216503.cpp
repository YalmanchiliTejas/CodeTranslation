#include <bits/stdc++.h>

using namespace std;
using ll= long long;

ll dp[2][3005][3005];
int n;
ll a[3005];

ll dfs(int t, int x, int y){
    if(dp[t][x][y] != -1) return dp[t][x][y];
    if(x==y){
        return dp[t][x][y] = (1-2*t) * a[x];
    }
    if(t==0){
        return dp[t][x][y] = max(dfs(1-t, x+1, y) + a[x], dfs(1-t, x, y-1) + a[y]);
    }
    return dp[t][x][y] = min(dfs(1-t, x+1, y)-a[x], dfs(1-t,x,y-1) -a[y]);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin>>n;
    memset(dp, -1, sizeof(dp));
    for(int i=0;i<n;i++){
        cin>>a[i];
    }

    ll res = dfs(0, 0, n-1);
    cout<<res;

    return 0;
}