import sys
from collections import *
import heapq
import math
import bisect
from itertools import permutations,accumulate,combinations,product
from fractions import gcd
def input():
    return sys.stdin.readline()[:-1]
mod=10**9+7

n=int(input())
k=int(input())
keta=len(str(n))
sn=str(n)
dp=[[[0]*(k+1) for j in range(keta)] for i in range(2)]

for i in range(keta):
    if i==0:
        dp[0][0][0]=1
        dp[0][0][1]=int(sn[i])-1
        dp[1][0][1]=1
    else:
        for j in range(k+1):
            if j!=k:
                dp[0][i][j]+=dp[0][i-1][j]
                dp[0][i][j+1]+=dp[0][i-1][j]*9
                if int(sn[i])==0:
                    dp[1][i][j]+=dp[1][i-1][j]
                else:
                    dp[1][i][j+1]+=dp[1][i-1][j]
                    dp[0][i][j]+=dp[1][i-1][j]
                    dp[0][i][j+1]+=dp[1][i-1][j]*(int(sn[i])-1)
            else:
                dp[0][i][j]+=dp[0][i-1][j]
                if int(sn[i])==0:
                    dp[1][i][j]+=dp[1][i-1][j]
                else:
                    dp[0][i][j]+=dp[1][i-1][j]

print(dp[0][-1][-1]+dp[1][-1][-1])