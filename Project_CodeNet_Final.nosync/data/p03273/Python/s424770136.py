from collections import Counter,defaultdict,deque
from heapq import heappop,heappush,heapify
import sys,bisect,math,itertools,fractions,pprint
sys.setrecursionlimit(10**8)
mod = 10**9+7
INF = float('inf')
def inp(): return int(sys.stdin.readline())
def inpl(): return list(map(int, sys.stdin.readline().split()))

n,m = inpl()
s = [list(input()) for i in range(n)]
ss = []
for i in range(n):
    if s[i].count('.') == m:
        continue
    ss.append(s[i])
sss = [[]for _ in range(len(ss))]
for i in range(m):
    ok = False
    ln = len(ss)
    for j in range(ln):
        if ss[j][i] == '#':
            ok = True
    if ok:
        for j in range(ln):
            sss[j].append(ss[j][i])

for i in sss:
    print(''.join(i))
