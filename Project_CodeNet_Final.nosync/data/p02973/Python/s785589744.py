#!/usr/bin/env python3
import sys, math, itertools, collections, bisect
input = lambda: sys.stdin.buffer.readline().rstrip().decode('utf-8')
inf = float('inf') ;mod = 10**9+7
mans = inf ;ans = 0 ;count = 0 ;pro = 1

n = int(input())
A = [int(input()) for i in range(n)]
dp = [-inf] * (10**5+10);dp[-1] = inf
for ai in A:
  dp[bisect.bisect_left(dp,ai)-1] = ai
for di in dp:
  if di != -inf:ans += 1
print(ans - 1)