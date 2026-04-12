#!/usr/bin/env python3
import sys, math, itertools, collections, bisect
input = lambda: sys.stdin.buffer.readline().rstrip().decode('utf-8')
inf = float('inf') ;mod = 10**9+7
mans = inf ;ans = 0 ;count = 0 ;pro = 1

K = list(map(int,input())); n = len(K)
D = int(input())
dp = [[[0]*D for i in range(2)] for j in range(n+1)]
dp[0][0][0] = 1
for i in range(n):
  for p in range(D):
    dp[i+1][0][p] = dp[i][0][(p-K[i])%D] % mod
    tmp = 0
    for l in range(K[i]):
      tmp += dp[i][0][(p-l)%D]
    for l in range(10):
      tmp += dp[i][1][(p-l)%D]
    dp[i+1][1][p] = tmp % mod
print((dp[n][0][0] + dp[n][1][0] -1) % mod)
# for di in dp:
#   print(*di)