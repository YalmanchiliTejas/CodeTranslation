import sys
from collections import defaultdict, Counter, namedtuple, deque
import itertools
import functools
import bisect
import heapq
import math

# MOD = 10 ** 9 + 7
MOD = 998244353
# sys.setrecursionlimit(10**8)

n, s = map(int, input().split())
A = list(map(int, input().split()))
dp = [[0]*(s+1) for _ in range(n+1)]

for i in range(n+1):
    dp[i][0] = i + 1

ans = 0
for i in range(n):
    for j in range(s + 1):
        if s > j > 0:
            dp[i + 1][j] += dp[i][j]
        if j + A[i] <= s:
            dp[i + 1][j + A[i]] += dp[i][j]
            dp[i + 1][j + A[i]] %= MOD

    ans += dp[i + 1][s] * (n - i)
    ans %= MOD

print(ans)
