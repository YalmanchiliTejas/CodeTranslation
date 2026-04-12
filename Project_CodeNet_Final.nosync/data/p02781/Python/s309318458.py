from collections import Counter,defaultdict,deque
from heapq import heappop,heappush,heapify
import sys,bisect,math,itertools,pprint,fractions
sys.setrecursionlimit(10**8)
mod = 10**9+7
INF = float('inf')
def inp(): return int(sys.stdin.readline())
def inpl(): return list(map(int, sys.stdin.readline().split()))

n = inp()
K = inp()
s = list(str(n))
l = len(s)

dp = [[[0 for _ in range(2)] for j in range(4)] for i in range(l+5)]
dp[0][0][0] = 1

for i in range(l):
    nd = int(s[i])
    # print(nd)
    for j in range(4):
        for k in range(2):
            for d in range(10):
                ni = i+1; nj = j; nk = k
                if d>0: nj += 1
                if nj >= 4: continue

                if k == 0:
                    if d < nd: nk += 1
                    elif d > nd: continue
                dp[ni][nj][nk] += dp[i][j][k]
# print(dp)
print(sum(dp[l][K]))