import itertools
from collections import deque,defaultdict,Counter
from itertools import accumulate
import bisect
from heapq import heappop,heappush
from fractions import gcd
from copy import deepcopy
import math
import queue
#import numpy as np
#import sympy as syp(素因数分解とか)
Mod = 1000000007
import sys
input = sys.stdin.readline
sys.setrecursionlimit(1000000) 
  
def sieve_of_eratosthenes(n):
    if not isinstance(n,int):
        raise TypeError("n is not int")
    if n<2:
        raise ValueError("n is not effective")
    prime = [1]*(n+1)
    for i in range(2,int(math.sqrt(n))+1):
        if prime[i] == 1:
            for j in range(2*i,n+1):
                if j%i == 0:
                    prime[j] = 0
    res = []
    for i in range(2,n+1):
        if prime[i] == 1:
            res.append(i)
    return res

def factorial(i):
    if i == 1:
        return 1
    else:
        return i*factorial(i-1)
 
class UnionFind:
    def __init__(self,n):
        self.parent = [i for i in range(n+1)]
        self.rank = [0 for i in range(n+1)]
    
    def findroot(self,x):
        if x == self.parent[x]:
            return x
        else:
            y = self.parent[x]
            y = self.findroot(self.parent[x])
            return y
    
    def union(self,x,y):
        px = self.findroot(x)
        py = self.findroot(y)
        if px < py:
            self.parent[py] = px
        else:
            self.parent[px] = py
 
    def same_group_or_no(self,x,y):
        return self.findroot(x) == self.findroot(y)



        
def main(): #startline--------------------------------------------
    n = int(input())
    a = list(map(int,input().split()))
    dp = [[0]*n for i in range(n)]
    for i in range(n):
        dp[i][i] = a[i]

    for i in reversed(range(n-1)):
        for j in range(i+1,n):
            dp[i][j] = max(a[i]-dp[i+1][j],a[j]-dp[i][j-1])

    print(dp[0][n-1])

if __name__ == "__main__":
    main() #endline===============================================
    