#!/usr/bin/env python3
import sys, math, itertools, collections, bisect
input = lambda: sys.stdin.buffer.readline().rstrip().decode('utf-8')
inf = float('inf') ;mod = 10**9+7
mans = inf ;ans = 0 ;count = 0 ;pro = 1

s=int(input()); n=len(str(s))
k=int(input())
S=[int(i) for i in str(s)]
dpl=[[0]*(k+1) for i in range(n+1)]
dpj=[[0]*(k+1) for i in range(n+1)]
dpj[0][0]=1
for i in range(n):
    for j in range(k+1):
        dpj[i+1][j] += dpj[i][j]*(S[i]==0)
        dpl[i+1][j] += dpl[i][j] + dpj[i][j]*(S[i] >= 1)
        if j+1 < k+1:
            dpj[i+1][j+1] += dpj[i][j]*(S[i] > 0)
            dpl[i+1][j+1] += dpl[i][j]*9 + dpj[i][j]*max(0,S[i]-1) 

print(dpl[n][k]+dpj[n][k])
# print(dpl)
# print(dpj)