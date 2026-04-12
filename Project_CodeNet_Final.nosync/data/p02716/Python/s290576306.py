#!/usr/bin/env python3
import sys, math, itertools, collections, bisect
input = lambda: sys.stdin.buffer.readline().rstrip().decode('utf-8')
inf = float('inf') ;mod = 10**9+7
mans = inf ;ans = 0 ;count = 0 ;pro = 1

n = int(input())
A = list(map(int,input().split()))
dp0 = [0] * (n+11)
dp1 = [0] * (n+11)
dp2 = [0] * (n+11)
for i,ai in enumerate(A):
  dp2[i+11] = (max(dp0[i+7] + ai, dp1[i+8] + ai, dp2[i+9] + ai) if i >= 2 else 0)
  dp1[i+11] = (max(dp0[i+8] + ai, dp1[i+9] + ai) if i >= 1 else 0)
  dp0[i+11] = dp0[i+9] + ai 
if n % 2 == 0:
  print(max(dp0[n + 9], dp1[n + 10]))
else:
  print(max(dp0[n + 8], dp1[n + 9], dp2[n + 10]))

# debug
# print(dp0,dp1,dp2,sep="\n")


