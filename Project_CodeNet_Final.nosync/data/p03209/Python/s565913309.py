import sys, re
from collections import deque, defaultdict, Counter
from math import ceil, sqrt, hypot, factorial, pi, sin, cos, radians
from itertools import permutations, combinations, product, accumulate
from operator import itemgetter, mul
from copy import deepcopy,copy
from string import ascii_lowercase, ascii_uppercase, digits
from fractions import gcd

def input(): return sys.stdin.readline().strip()
def INT(): return int(input())
def MAP(): return map(int, input().split())
def LIST(): return list(map(int, input().split()))
sys.setrecursionlimit(10 ** 9)
INF = float('inf')
mod = 10 ** 9 + 7

def main():
    n,x = MAP()
    L = [1]*n
    P = [1]*n

    for  i in range(1,n):
        L[i] = 2* L[i-1] +3
        P[i] = 2* P[i-1] + 1

    def func(N, X):
        if N==0:
            return 0 if X <= 0 else 1

        elif X<= L[N-1] + 1:
            return func(N-1, X-1)

        else:
            return P[N-1] + 1 + func(N-1, X-L[N-1] -2)

    print(func(n,x))

if  __name__=='__main__':
    main()