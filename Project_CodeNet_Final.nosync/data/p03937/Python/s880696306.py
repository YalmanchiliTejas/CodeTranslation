import sys
import math
import numpy as np
import itertools
import bisect
from copy import copy
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

H,W = I()
maze = [list(s()) for _ in range(H)]
visited = [[0]*W for _ in range(H)]
def dfs(x,y):
    if x < 0 or y < 0 or x >= H or y >= W:
        return
    if maze[x][y] == '.':
        return
    visited[x][y] = 1
    dfs(x+1,y)
    dfs(x,y+1)
dfs(0,0)
if visited[H-1][W-1] == 1:
    cnt = 0
    for i in range(H):
        cnt += maze[i].count('#')
    if cnt == H+W-1:
        print('Possible')
    else:
        print('Impossible')
else:
    print('Impossible')