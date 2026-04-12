# import numpy as np
import sys, math
from itertools import permutations, combinations
from collections import defaultdict, Counter, deque
from math import factorial#, gcd
from bisect import bisect_left #bisect_left(list, value)
sys.setrecursionlimit(10**7)
enu = enumerate
MOD = 10**9+7
def input(): return sys.stdin.readline()[:-1]
pl = lambda x: print(*x, sep='\n')

H, W = map(int, input().split())
aHW = [list(input()) for _ in range(H)]

res = []
for h in aHW:
    if '#' in h:
        res.append(h)

res = list(zip(*res))
res2 = []
for h in res:
    if '#' in h:
        res2.append(h)

res2 = list(zip(*res2))

for h in res2:
    print(''.join(h))