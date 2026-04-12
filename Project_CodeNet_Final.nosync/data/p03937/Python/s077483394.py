import sys, math
from functools import lru_cache
from collections import deque
sys.setrecursionlimit(10**9)
MOD = 10**9+7

def input():
    return sys.stdin.readline()[:-1]

def mi():
    return map(int, input().split())

def ii():
    return int(input())

def i2(n):
    tmp = [list(mi()) for i in range(n)]
    return [list(i) for i in zip(*tmp)]

H, W = mi()
A = [input() for i in range(H)]

s = sum(1 for i in range(H) for j in range(W) if A[i][j] == '#')
if s == H+W-1:
    print('Possible')
else:
    print('Impossible')