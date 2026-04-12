// 解答不能.
// https://atcoder.jp/contests/abc159/submissions/11096062
#include <bits/stdc++.h>
using namespace std;
using LL = long long;
#define repex(i, a, b, c) for(int i = a; i < b; i += c)
#define repx(i, a, b) repex(i, a, b, 1)
#define rep(i, n) repx(i, 0, n)
#define repr(i, a, b) for(int i = a; i >= b; i--)
const LL MOD = 998244353;

LL dp[3030][3030][3];
int a[3030];

int main(){
    int n, k;
    scanf("%d %d", &n, &k);
    rep(i, n) scanf("%d", &a[i]);
    dp[0][0][0] = 1;
    rep(i, n){
        rep(j, k + 1){
            (dp[i + 1][j][0] += dp[i][j][0]) %= MOD;
            (dp[i + 1][j][1] += dp[i][j][0] + dp[i][j][1]) %= MOD;
            (dp[i + 1][j][2] += dp[i][j][0] + dp[i][j][1] + dp[i][j][2]) %= MOD;
            if(j + a[i] <= k){
                (dp[i + 1][j + a[i]][1] += dp[i][j][0] + dp[i][j][1]) %= MOD;
                (dp[i + 1][j + a[i]][2] += dp[i][j][0] + dp[i][j][1]) %= MOD;
            }
        }
    }
    printf("%d\n", dp[n][k][2]);
    return 0;
}