import sys
sys.setrecursionlimit(2147483647)
INF = float("inf")
MOD = 10**9 + 7 # 998244353
input = lambda:sys.stdin.readline().rstrip()
from itertools import product
def resolve():
    k = input()
    modulo = int(input())
    dp = [[0] * 2 for _ in range(modulo)]
    dp[0][0] = 1

    for d in k:
        d = int(d)
        ndp = [[0] * 2 for _ in range(modulo)]
        for r, lt in product(range(modulo), range(2)):
            for x in range(10):
                if (not lt) and x > d:
                    continue
                nlt = max(lt, x < d)
                nr = (r + x) % modulo
                ndp[nr][nlt] += dp[r][lt]
                if ndp[nr][nlt] >= MOD:
                    ndp[nr][nlt] -= MOD
        dp = ndp

    print((dp[0][0] + dp[0][1] - 1) % MOD)
resolve()