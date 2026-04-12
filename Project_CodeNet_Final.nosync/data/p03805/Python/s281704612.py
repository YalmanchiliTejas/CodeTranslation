# Author: cr4zjh0bp
# Created: Tue Mar 24 00:01:43 UTC 2020
import sys
 
stdin = sys.stdin
inf = 1 << 60
mod = 1000000007
 
ni      = lambda: int(ns())
nin     = lambda y: [ni() for _ in range(y)]
na      = lambda: list(map(int, stdin.readline().split()))
nan     = lambda y: [na() for _ in range(y)]
nf      = lambda: float(ns())
nfn     = lambda y: [nf() for _ in range(y)]
nfa     = lambda: list(map(float, stdin.readline().split()))
nfan    = lambda y: [nfa() for _ in range(y)]
ns      = lambda: stdin.readline().rstrip()
nsn     = lambda y: [ns() for _ in range(y)]
ncl     = lambda y: [list(ns()) for _ in range(y)]
nas     = lambda: stdin.readline().split()

from itertools import permutations

n, m = na()
ab = nan(m)
g = [[] for _ in range(n)]
for i in range(m):
    a, b = ab[i]
    a -= 1
    b -= 1
    g[a].append(b)
    g[b].append(a)

def dfs(i, c, p):
    if p[c] == i:
        if c == n - 1:
            return 1
    else:
        return 0
    res = 0
    for j in g[i]:
        res = max(res, dfs(j, c + 1, p))
    return res

ans = 0
for p in permutations(range(n)):
    if p[0] == 0:
        ans += dfs(0, 0, p)

print(ans)