from collections import Counter,defaultdict,deque
from heapq import heappop,heappush,heapify
import sys,bisect,math,itertools,fractions,pprint
sys.setrecursionlimit(10**8)
mod = 10**9+7
INF = float('inf')
def inp(): return int(sys.stdin.readline())
def inpl(): return list(map(int, sys.stdin.readline().split()))

n,m = inpl()
g = [set() for _ in range(n)]
for i in range(m):
    a,b = inpl()
    a -= 1; b -= 1
    g[a].add(b)
    g[b].add(a)
res = 0
for a in itertools.permutations(range(1,n)):
    a = [0] + list(a)
    for i in range(n-1):
        x = a[i]; y = a[i+1]
        if x in g[y]:
            continue
        else:
            break
    else:
        # print(a)
        res += 1
print(res)