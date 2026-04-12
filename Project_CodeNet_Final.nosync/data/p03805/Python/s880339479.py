from collections import Counter,defaultdict,deque
from heapq import heappop,heappush,heapify
import sys,bisect,math,itertools,fractions,pprint
sys.setrecursionlimit(10**8)
mod = 10**9+7
mod2 = 998244353
INF = float('inf')
def inp(): return int(sys.stdin.readline())
def inpl(): return list(map(int, sys.stdin.readline().split()))
def inpln(n): return list(int(sys.stdin.readline()) for i in range(n))

n,m = inpl()
g = [[False for j in range(n)] for i in range(n)]
for i in range(m):
    a,b = inpl()
    a -= 1
    b -= 1
    g[a][b] = True
    g[b][a] = True
# print(g)
res = 0
for flag in itertools.permutations(range(1,n)):
    # print(flag)
    for i in range(n-1):
        if i == 0:
            if not g[0][flag[0]]:
                break
            continue
        if not g[flag[i]][flag[i-1]]:
            break
    else:
        res += 1
print(res)