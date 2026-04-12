#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int max_n = 200005;
const ll inf = 1e18;
int n, a[max_n];
ll dp[max_n][3];
ll solve(int n, int k) {
    if(k > (n + 1) / 2) return -inf;
    if(k <= 0) return 0;
    int x = k - n/2 - 1;
    if(~ dp[n][x]) return dp[n][x];
    return dp[n][x] = max(solve(n - 1, k), solve(n - 2, k - 1) + a[n]);
}
int main(){
    scanf("%d", &n);
    for(int i = 1; i <= n; i++) scanf("%d", a+i);
    for(int i = 0; i <= n; i++) {
        for(int j = 0; j < 3; j++) dp[i][j] = -1;
    }
    printf("%lld\n", solve(n, n/2));
    return 0;
}