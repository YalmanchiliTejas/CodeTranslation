import sys
import copy
import string
import  math
from _bisect import *
from collections import *
from operator import itemgetter
from math import factorial
"""
from fractions import gcd
def lcm(x, y):
    return (x * y) // gcd(x, y)
"""
stdin = sys.stdin
ni = lambda: int(ns())
na = lambda: list(map(int, stdin.readline().split()))
ns = lambda: stdin.readline()

def dfs(v):
    flag = True
    for i in range(n):
        if not visit[i]:
            flag = False
    if flag:
        return 1

    ret = 0

    for i in range(n):
        if not g[v][i]:
            continue
        if visit[i]:
            continue

        visit[i] = True
        ret += dfs(i)
        visit[i] = False

    return ret


    for next in g[v]:
        if visit[next]:
            continue
        else:
            visit[next] = True
            dfs(next)


n, m = na()
g = [[0] * n for _ in range(n)]
for i in range(m):
    a, b = na()
    a -= 1
    b -= 1
    g[a][b] = g[b][a] = True

visit = [False] * n
visit[0] = True
print(dfs(0))





