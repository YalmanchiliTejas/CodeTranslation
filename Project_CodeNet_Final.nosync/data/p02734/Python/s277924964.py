from heapq import *
import sys
from collections import *
from itertools import *
from decimal import *
import copy
from bisect import *
import math
sys.setrecursionlimit(4100000)
def gcd(a,b):
    if(a%b==0):return(b)
    return (gcd(b,a%b))
input=lambda :sys.stdin.readline().rstrip()
N,S=map(int,input().split())
A=list(map(int,input().split()))
mod=998244353

dp=[0 for n in range(3001)]
c=0
for n in range(N):
    a=A[n]
    for s in range(0,S+1)[::-1]:
        if s+a<=S:
            dp[s+a]+=dp[s]
            dp[s+a]%=mod

    dp[a]+=n+1
    dp[a]%=mod
    c+=dp[S]
    c%=mod
#print(dp[S])
print(c)
