# -*- coding: utf-8 -*-
"""
Created on Mon Apr 27 21:30:42 2020
"""

import sys
#import numpy as np

sys.setrecursionlimit(10 ** 9)
#def input():
#    return sys.stdin.readline()[:-1]
mod = 10**9+7

#N = int(input())
N, X = map(int,input().split())
#A = list(map(int,input().split()))

n = N
eat = X

def dfs(x):
    x

ans = 0
#print(ans,eat,n)
while eat > 0 and n >= 0:
    if eat == (pow(2,n+2) - 3 + 1) //2:
        ans += pow(2,n) - 1 + 1
        eat = 0
        n -= 1
    elif eat > (pow(2,n+2) - 3 + 1) //2:
        ans += pow(2,n) - 1 + 1
        eat -= (pow(2,n+2) - 2) //2
        n -= 1
    else:
        eat -= 1
        n -= 1
#    print(ans,eat,n)

print(ans)
    
