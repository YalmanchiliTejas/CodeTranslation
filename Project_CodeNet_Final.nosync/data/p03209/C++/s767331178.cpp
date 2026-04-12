#include <bits/stdc++.h>
using namespace std;

long long dp[51], dp2[51];

long long solve(int N, long long X){
    if(X == 1){
        if(N == 0) return 1;
        else return 0;
    }
    if(1 < X && X <= 1+dp[N-1]) return solve(N-1, X-1);
    if(X == 2+dp[N-1]) return dp2[N-1] + 1;
    if(2+dp[N-1] < X && X <= 2+2*dp[N-1])
        return dp2[N-1]+1+solve(N-1, X-2-dp[N-1]);
    if(X == 3+2*dp[N-1]) return 2*dp2[N-1]+1;
    return 0;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n;
    long long x;
    cin >> n >> x;
    dp[0] = 1;
    dp2[0] = 1;
    for(int i = 1; i <= n; i++){
        dp[i] = 2 * dp[i-1] + 3;
        dp2[i] = 2 * dp2[i-1] + 1;
    }
    cout << solve(n, x) << endl;
    return 0;
}