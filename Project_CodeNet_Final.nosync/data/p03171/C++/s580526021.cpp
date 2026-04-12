#include <bits/stdc++.h>
using namespace std;

#define int long long
#define mk make_pair
#define pb push_back
#define fr first
#define sc second
#define vi vector < int >
#define pii pair < int, int >

const int N = 3007;
const int INF = 1e18 + 7;

int dp[N][N][2];
int a[N];
int n;

int rec (int l, int r, int t){
    if (l > r)
        return 0;
    if (dp[l][r][t] != 0)
        return dp[l][r][t];
    if (t == 0){
        dp[l][r][t] = -INF;
        dp[l][r][t] = max(dp[l][r][t], rec(l, r - 1, t ^ 1) + a[r]);
        dp[l][r][t] = max(dp[l][r][t], rec(l + 1, r, t ^ 1) + a[l]);
    }
    else {
        dp[l][r][t] = INF;
        dp[l][r][t] = min(dp[l][r][t], rec(l, r - 1, t ^ 1) - a[r]);
        dp[l][r][t] = min(dp[l][r][t], rec(l + 1, r, t ^ 1) - a[l]);
    }
    return dp[l][r][t];
}

main(){
    cin >> n;
    for (int i = 1; i <= n; i++){
        cin >> a[i];
    }
    cout << rec(1, n, 0);
}
