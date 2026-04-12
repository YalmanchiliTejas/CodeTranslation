from collections import Counter,defaultdict,deque
from heapq import heappop,heappush
from bisect import bisect_left,bisect_right 
import sys,math,itertools,fractions
sys.setrecursionlimit(10**8)
mod = 10**9+7
INF = float('inf')
def inp(): return int(sys.stdin.readline())
def inpl(): return list(map(int, sys.stdin.readline().split()))

s = input()
n = len(s)
K = inp()
dp = [[[0 for i in range(5)] for j in range(2)] for k in range(n+1)]
# dp[i][j][k] j:0 kaku j:1 mikaku , k:kosuu
dp[0][1][0] = 1
for i,x in enumerate(s):
    x = int(x)
    for k in range(4):
        dp[i+1][0][k] += dp[i][0][k]
        dp[i+1][0][k+1] += dp[i][0][k]*9 + dp[i][1][k]*max(0,(x-1))

        if x != 0:
            dp[i+1][0][k] += dp[i][1][k]
            dp[i+1][1][k+1] = dp[i][1][k]
            if k == 0: dp[i+1][1][k] = 0
        else:
            dp[i+1][1][k] = dp[i][1][k] 
        for j in range(2):
            dp[i+1][j][k] %= mod

    # print(dp[i+1][0])
    # print(dp[i+1][1])
    # print()
print(dp[-1][0][K] + dp[-1][1][K])
