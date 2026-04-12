import sys
from fractions import gcd
from itertools import groupby as gb
from itertools import permutations as perm
from collections import Counter as C
from collections import defaultdict as dd
sys.setrecursionlimit(10**5)

n,m = map(int,input().split())

coor = [[False for _ in range(n)] for _ in range(n)]
for i in range(n):
    coor[i][i] = True
for i in range(m):
    a,b = map(int,input().split())
    a,b = a-1, b-1
    coor[a][b] = True
    coor[b][a] = True

# n-1頂点のperm
l = range(2,n+1)

res = 0
for p in perm(l):
    p = [1] + list(p)
    for s,g in zip(p,p[1:]):
        if not coor[s-1][g-1]:
            break
    else:
        res += 1
print(res)
