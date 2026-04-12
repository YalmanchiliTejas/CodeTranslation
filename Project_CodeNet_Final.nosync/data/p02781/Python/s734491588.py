import sys
sys.setrecursionlimit(2147483647)
INF=float("inf")
MOD=10**9+7 # 998244353
input=lambda:sys.stdin.readline().rstrip()
from itertools import product
def resolve():
    dp = [[0]*4 for _ in range(2)] # dp[lt][k] lt:less than, k:num of non-zero
    dp[0][0] = 1
    for a in input():
        a = int(a)
        ndp = [[0]*4 for _ in range(2)]
        for lt, k, d in product([0,1], range(4), range(10)):
            # less than
            if (not lt) and d > a: continue
            nlt = max(lt, d < a)
            # zero
            nk = k + (d>0)
            if nk > 3: continue
            # iterate
            ndp[nlt][nk] += dp[lt][k]
        dp = ndp

    k = int(input())
    print(dp[0][k] + dp[1][k])
resolve()