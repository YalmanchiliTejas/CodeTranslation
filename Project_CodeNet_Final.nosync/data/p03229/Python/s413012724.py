import bisect
import copy
import heapq
import math
import sys
from collections import *
from functools import lru_cache
from itertools import accumulate, combinations, permutations, product
def input():
    return sys.stdin.readline()[:-1]
def ruiseki(lst):
    return [0]+list(accumulate(lst))
sys.setrecursionlimit(500000)
mod=pow(10,9)+7
al=[chr(ord('a') + i) for i in range(26)]
direction=[[1,0],[0,1],[-1,0],[0,-1]]

n=int(input())
a=[int(input()) for i in range(n)]

a.sort()

ans1=0
if n%2==0:
    for i in range(n):
        if i<n//2:
            ans1-=a[i]*2
        else:
            ans1+=a[i]*2
    ans1-=a[n//2]
    ans1+=a[n//2-1]
    print(ans1)
else:
    for i in range(n):
        if i<n//2:
            ans1-=a[i]*2
        elif i>n//2:
            ans1+=a[i]*2
    print(max(ans1+a[n//2]-a[n//2+1],ans1-a[n//2]+a[n//2-1]))