n,s = map(int,input().split())
a = tuple(map(int,input().split()))

mod = 998244353

dp = [[0]* (s+1) for _ in range(n+1)]

for i in range(1,n+1):
    a_t = a[i-1]
    for j in range(s+1):
        dp[i][j] = dp[i-1][j]
        if(j == 0)|(j == a_t):
            dp[i][j] += 1
        if(j >= a_t):
            dp[i][j] += dp[i-1][j-a_t]
        dp[i][j] %= mod

ans = 0
for i in range(n+1):
    ans = (ans + dp[i][-1]) % mod
print(ans)