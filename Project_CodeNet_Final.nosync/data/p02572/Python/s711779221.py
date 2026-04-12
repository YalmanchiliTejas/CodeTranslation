from collections import Counter,defaultdict,deque
from heapq import heappop,heappush,heapify
import sys,bisect,math,itertools,fractions
sys.setrecursionlimit(10**8)
mod = 10**9+7
INF = float('inf')
def inp(): return int(sys.stdin.readline())
def inpl(): return list(map(int, sys.stdin.readline().split()))

n = inp()
a = inpl()
b = []
now = 0
for i in range(n)[::-1]:
    now += a[i]
    now %= mod
    b.append(now)
b = b[::-1]
res = 0
for i in range(n-1):
    res += a[i]*b[i+1]
    res %= mod
print(res)