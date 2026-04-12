from collections import defaultdict, deque
import sys, heapq, bisect, math, itertools, string, queue, copy, time
from fractions import gcd
import numpy as np
sys.setrecursionlimit(10**8)
INF = float('inf')
MOD = 10**9+7
EPS = 10**-7
def inp(): return int(sys.stdin.readline())
def inpl(): return list(map(int, sys.stdin.readline().split()))
def inpl_str(): return list(sys.stdin.readline().split())

n = int(input())
a_list = list(map(int, input().split()))
a_list = np.array(a_list)

a = a_list.sum() % MOD
b = ( (a_list**2)%MOD ).sum() % MOD
c = ( a**2 - b) % MOD

if c&1:
    c += MOD

print(c//2)