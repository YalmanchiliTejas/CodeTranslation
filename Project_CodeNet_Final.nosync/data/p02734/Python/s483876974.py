#!/usr/bin/env python3
n,s = map(int,input().split())
a = list(map(int,input().split()))
dp = [[0]*(3001) for _ in range(3001)]
# dp[i][j] は i 番目までを使った時に、どれだけの組み合わせがあり、かける必要があるか？
ans = 0
mod = 998244353
for i in range(n):
    dp[i][a[i]] = i+1
    if a[i] == s:
        ans += (i+1)*(n-i) %mod
for i in range(0,n):
    for j in range(s+1):
        if j > a[i]:
            dp[i][j] += dp[i-1][j] + dp[i-1][j-a[i]]
            dp[i][j] %= mod
            if j == s:
                ans += dp[i-1][j-a[i]] * (n-i)
                ans %= mod
                #print(ans,i,j)
        else:
            dp[i][j] += dp[i-1][j]
            dp[i][j] %= mod
print(ans%mod)


