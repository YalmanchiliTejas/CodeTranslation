import bisect
import copy
import heapq
import math
import sys
from collections import *
from itertools import accumulate, combinations, permutations, product
# from math import gcd
from functools import lru_cache
def input():
    return sys.stdin.readline()[:-1]
def ruiseki(lst):
    return [0]+list(accumulate(lst))
sys.setrecursionlimit(5000000)
mod=pow(10,9)+7
al=[chr(ord('a') + i) for i in range(26)]
direction=[[1,0],[0,1],[-1,0],[0,-1]]

n=int(input())
a=list(map(int,input().split()))

dp=[[0]*(n+1) for i in range(n+1)]

for i in range(1,n+1):
    for j in range(n):
        if j+i>n:
            continue
        if (n-i)%2==0:
            dp[j][i+j]=max(dp[j+1][i+j]+a[j],dp[j][i+j-1]+a[i+j-1])
        else:
            dp[j][i+j]=min(dp[j+1][i+j]-a[j],dp[j][i+j-1]-a[i+j-1])
# print(dp)
print(dp[0][n])