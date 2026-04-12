import math
import functools
import itertools
import numpy as np
import sys
MAX_INT = int(10e10)
MIN_INT = -MAX_INT
mod = 1000000007
sys.setrecursionlimit(1000000)
def IL(): return list(map(int,input().split()))
def SL(): return input().split()
def I(): return int(sys.stdin.readline())
def S(): return input()

N = I()
H = IL()

tmp = H[0]
cnt = 1
for i in range(1,N):
    if tmp <= H[i]:
        cnt += 1
        tmp = H[i]
print(cnt)