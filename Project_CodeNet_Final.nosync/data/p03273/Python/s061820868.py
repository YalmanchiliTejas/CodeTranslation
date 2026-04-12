import sys
import math
import itertools
import bisect
from copy import copy
from collections import deque,Counter
from decimal import Decimal
def s(): return input()
def i(): return int(input())
def S(): return input().split()
def I(): return map(int,input().split())
def L(): return list(input().split())
def l(): return list(map(int,input().split()))
def lcm(a,b): return a*b//math.gcd(a,b)
sys.setrecursionlimit(10 ** 9)
mod = 10**9+7

H,W = I()
S = []
for i in range(H):
    s1 = list(s())
    if '#' in s1:
        S.append(s1)
L = [1]*W
for i in range(len(S)):
    if 1 not in L:
        break
    for j in range(W):
        if S[i][j] == '#':
            L[j] = 0
for i in range(W-1,-1,-1):
    if L[i] == 1:
        for j in range(len(S)):
            S[j].pop(i)
for i in range(len(S)):
    print(''.join(S[i]))