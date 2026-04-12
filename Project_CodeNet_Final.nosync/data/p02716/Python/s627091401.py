#!/usr/bin/env python3
import sys
input = sys.stdin.readline
INF = 10**18
 
n = int(input())
a = [int(item) for item in input().split()]
 
 
# dp[i-th][wait num][used / not used]
dp = [[[-INF] * 2 for _ in range(3)] for _ in range(n+1)]
dp[0][0][0] = 0
 
for i in range(n):
    # use in i
    for j in range(3):
        dp[i+1][j][1] = max(dp[i+1][j][1] ,dp[i][j][0] + a[i])
    # rest in i
    for j in range(2):
        dp[i+1][j+1][0] = max(dp[i+1][j+1][0] ,dp[i][j][0])
    # not use in i
    for j in range(3):
        dp[i+1][j][0] = max(dp[i][j][1], dp[i+1][j][0])
 
ans = -INF
if n % 2 == 0:
    ans = max(dp[-1][1][1], ans)
    ans = max(dp[-1][0][0], ans)
else:
    ans = max(dp[-1][2][1], ans)
    ans = max(dp[-1][1][0], ans)
print(ans)