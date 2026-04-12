import sys
import math
import itertools
import bisect
from copy import copy,deepcopy
from collections import deque,Counter
from decimal import Decimal
def s(): return input()
def i(): return int(input())
def S(): return input().split()
def I(): return map(int,input().split())
def L(): return list(map(int,input().split()))
def l(): return list(map(int,input().split()))
def lcm(a,b): return a*b//math.gcd(a,b)
sys.setrecursionlimit(10 ** 9)
INF = 10**9
mod = 10**9+7

n = i()
L = [s() for _ in range(n)]
ans = []
for i in range(ord('a'),ord('z')+1):
    s = chr(i)
    num = 10000
    for j in range(n):
        num = min(num,L[j].count(s))
    if num:
        for i in range(num):
            ans.append(s)
print(''.join(ans))