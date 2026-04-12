#include <bits/stdc++.h>
using namespace std;

const int N = 3e3 + 10, mod = 998244353;

int n, sum;
int dp[N][N];
int arr[N];

int solve(int i, int s) {
    if(s > sum) return 0;
    if(sum == s) return n - i + 1;
    if(i == n) return 0;
    if(dp[i][s] != -1) return dp[i][s];
    int ret = 0;
    ret = solve(i + 1, s + arr[i]);
    ret = (1ll * ret + solve(i + 1, s)) % mod;
    return dp[i][s] = ret;
}

int main() {
    // ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int tc = 1; 
    // scanf("%d", &tc);
    while(tc--) {
        scanf("%d%d", &n, &sum);
        for(int i = 0; i < n; i++) scanf("%d", &arr[i]);
        int ans = 0;
        memset(dp, -1, sizeof(dp));
        for(int i = 0; i < n; i++) {
            ans = (ans + 1ll * (i + 1) * solve(i + 1, arr[i]) % mod) % mod;
        }
        printf("%d\n", ans);
    }    
    return 0;
}