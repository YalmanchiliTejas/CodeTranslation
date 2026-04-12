#include<bits/stdc++.h>
using namespace std;

#define int long long
#define sz(x) (int)(x.size())
#define fi first
#define se second
#define pii pair<int, int>

const int N = 3001;
int n, a[N];
int dp[N][N][2];

int solve(int l, int r, int turn){
    if(dp[l][r][turn] != -1){
        return dp[l][r][turn];
    }
    if(l == r){
        return dp[l][r][turn] = (turn ? -a[l] : a[l]);
    }
    if(turn == 0){
        dp[l][r][turn] = max(a[l] + solve(l + 1, r, 1 - turn), a[r] + solve(l, r - 1, 1 - turn));
    }else{
        dp[l][r][turn] = min(-a[l] + solve(l + 1, r, 1 - turn), -a[r] + solve(l, r - 1, 1 - turn));
    }
    return dp[l][r][turn];
}

signed main(){
    ios::sync_with_stdio(false);
    memset(dp, -1, sizeof dp);
    cin >> n;
    for(int i = 0;i < n;i++){
        cin >> a[i];
    }
    cout << solve(0, n - 1, 0) << "\n";
}