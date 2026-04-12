# -*- coding: utf-8 -*-
import sys
from collections import defaultdict, deque
# def input(): return sys.stdin.readline()[:-1] # warning not \n
# def input(): return sys.stdin.buffer.readline()[:-1]


def solve():
    n, m = [int(x) for x in input().split()]
    s = []
    ii = []
    jj = []
    cols = [[] for _ in range(m)]
    for i in range(n):
        r = [x for x in input()]
        if '#' not in set(r):
            ii.append(i)
        for j in range(m):
            cols[j].append(r[j])
        s.append(r)
    for j in range(m):
        if '#' not in set(cols[j]):
            jj.append(j)
    
    for i in range(n):
        if i in ii:
            continue
        for j in range(m):
            if j in jj:
                continue
            print(s[i][j], end='')
        print()


t = 1
# t = int(input())
for case in range(1,t+1):
    ans = solve()

"""

"""

