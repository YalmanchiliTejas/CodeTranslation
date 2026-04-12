#include <bits/stdc++.h>

using namespace std;

int n, s;
int dp[3010];
int ans = 0;
const int MOD = 998244353;

int add(long long a, long long b){
    return (a + b) % MOD;
}

int mul(long long a, long long b){
    return (a * b) % MOD;
}

int main(){
    scanf("%d%d", &n, &s);

    for(int i = 1; i <= n; i++){
        int x;
        scanf("%d", &x);
    
        for(int tmp = s; tmp > x; tmp--){
            dp[tmp] = add(dp[tmp], dp[tmp - x]);
        }

        dp[x] = add(dp[x], i);

        ans = add(ans, mul(dp[s], n - i + 1)); dp[s] = 0;
    }

    printf("%d\n", ans);
    
    return 0;
}