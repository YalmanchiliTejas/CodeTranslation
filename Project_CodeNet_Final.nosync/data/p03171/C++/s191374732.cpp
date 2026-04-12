#include<bits/stdc++.h>
using namespace std;

#define int long long
const int MOD = 1000000000000007LL;

int dp[3010][3010];
int a[3010];
int n;

int dfs(int l, int r, int turn){

    if(dp[l][r] != MOD) return dp[l][r];

    if(turn == 0){
        //最小化したい気持ち

        if(r - l == 1){
            dp[l][r] = -a[l];
            return dp[l][r];
        }

        int rec = min(dfs(l + 1, r, 1) - a[l], dfs(l, r - 1, 1) - a[r - 1]);
        dp[l][r] = rec;
        return dp[l][r];
    }else{
        //最大化したい気持ち

        if(r - l == 1){
            dp[l][r] = a[l];
            return dp[l][r];
        }

        int rec = max(dfs(l + 1, r, 0) + a[l], dfs(l, r - 1, 0) + a[r - 1]); 
        dp[l][r] = rec;
        return dp[l][r];
    }

}

signed main(){

    cin >> n;
    for(int i = 0; i < n; i++) cin >> a[i];
    for(int i = 0; i <= n; i++){
        for(int j = 0; j <= n; j++){
            dp[i][j] = MOD;
        }
    }
    cout << -dfs(0, n, 0) << endl;
    return 0;
}