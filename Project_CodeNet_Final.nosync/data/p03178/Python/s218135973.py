from collections import Counter,defaultdict,deque
from heapq import heappop,heappush,heapify
import sys,bisect,math,itertools,pprint,fractions
sys.setrecursionlimit(10**8)
mod = 10**9+7
INF = float('inf')
def inp(): return int(sys.stdin.readline())
def inpl(): return list(map(int, sys.stdin.readline().split()))

s = input()
D = inp()
n = len(s)
#dp[i][j][k]: i上から桁目まででそれまでの和をDで割ったあまりがj,k=0:Nと一緒 k=1:Nより小さいことが確定
dp = [[[0 for i in range(2)] for j in range(D)] for k in range(n+1)]
dp[0][0][0] = 1

for i in range(n):
    nd = int(s[i])
    for j in range(D):
        for k in range(2):
            for d in range(10):
                ni = i+1; nj = (j+d)%D; nk = k
                if k == 0:
                    if d > nd: continue
                    elif d < nd: nk = 1
                dp[ni][nj][nk] += dp[i][j][k] % mod
# pprint.pprint(dp)
print((sum(dp[n][0])-1)%mod)