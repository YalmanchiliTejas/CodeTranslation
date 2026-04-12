from collections import Counter,defaultdict,deque
from heapq import heappop,heappush,heapify
from bisect import bisect_left,bisect_right 
import sys,math,itertools,fractions,pprint
sys.setrecursionlimit(10**8)
mod = 10**9+7
INF = float('inf')
def inp(): return int(sys.stdin.readline())
def inpl(): return list(map(int, sys.stdin.readline().split()))

n = inp()
s = [input() for _ in range(n)]
c = [Counter(s[i]) for i in range(n)]
res = []
for key in list(c[0]):
    m = c[0][key]
    for i in range(1,n):
        m = min(m, c[i][key])
    for _ in range(m):
        res.append(key)
res.sort()
print(''.join(res))