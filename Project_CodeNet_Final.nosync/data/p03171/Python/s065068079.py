#!/usr/bin/env python3
import sys, math, itertools, collections, bisect
input = lambda: sys.stdin.buffer.readline().rstrip().decode('utf-8')
inf = float('inf') ;mod = 10**9+7
mans = inf ;ans = 0 ;count = 0 ;pro = 1

n=int(input())
A=list(map(int,input().split()))
dp=[[0]*(n+1) for i in range(n+1)]
for i in range(1,n+1):
  for k in range(0,n-i+1):
    if (n-i) % 2 == 0:
      dp[k][k+i] = max(A[k] + dp[k+1][k+i], dp[k][k+i-1] + A[k+i-1])
    else:
      dp[k][k+i] = min(-A[k] + dp[k+1][k+i], dp[k][k+i-1] - A[k+i-1])
print(dp[0][n])
# print(dp)