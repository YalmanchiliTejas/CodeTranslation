#include<bits/stdc++.h>
using namespace std;



const int N = 3005, MOD = 1e9 + 7;
const long long INF = 9e18;



int n, a[N];
long long dp[N][N][2];

long long rec(int l, int r, bool turn){
    if(l > r){
        return 0;
    }
    if(dp[l][r][turn] != -INF){
        return dp[l][r][turn];
    }
    dp[l][r][turn] = max(a[l] - rec(l + 1, r, turn ^ 1), a[r] - rec(l, r - 1, turn ^ 1));
    return dp[l][r][turn];
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
    }
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            dp[i][j][0] = dp[i][j][1] = -INF;
        }
    }
    cout << rec(1, n, 0);
}
