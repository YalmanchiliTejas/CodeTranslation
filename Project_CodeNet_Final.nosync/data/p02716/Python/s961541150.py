import bisect
import copy
import heapq
import math
import sys
from collections import *
from itertools import accumulate, combinations, permutations, product
from math import gcd
def input():
    return sys.stdin.readline()[:-1]
def ruiseki(lst):
    return [0]+list(accumulate(lst))
mod=pow(10,9)+7
al=[chr(ord('a') + i) for i in range(26)]
direction=[[1,0],[0,1],[-1,0],[0,-1]]

n=int(input())
a=list(map(int,input().split()))

dp=defaultdict(int)

if n%2==0:
    for i in range(n):
        if i%2==0:
            dp[(i,i//2+1)]=dp[(i-2,i//2)]+a[i]
        else:
            dp[(i,i//2+1)]=max(dp[(i-3,i//2)],dp[(i-2,i//2)])+a[i]
        # print(i)
    # print(dp)
    print(max(dp[(n-1,n//2)],dp[(n-2,n//2)]))
else:
    for i in range(n):
        if i%2==0:
            if i!=0:
                dp[(i,i//2)]=max(dp[(i-4,i//2-1)],dp[(i-3,i//2-1)],dp[(i-2,i//2-1)])+a[i]
            dp[(i,i//2+1)]=dp[(i-2,i//2)]+a[i]
        else:
            dp[(i,i//2+1)]=max(dp[(i-3,i//2)],dp[(i-2,i//2)])+a[i]
    # print(dp)
    print(max(dp[(n-1,n//2)],dp[(n-2,n//2)],dp[(n-3,n//2)]))