import sys
from collections import defaultdict, Counter, namedtuple, deque
import itertools
import functools
import bisect
import heapq
import math

MOD = 10 ** 9 + 7
# MOD = 998244353
# sys.setrecursionlimit(10**8)

n = int(input())
A = list(map(int, input().split()))
if n % 2 == 0:
    dp = [[-float("inf")] * 2 for i in range(n)]
    dp[0][0] = A[0]
    dp[1][1] = A[1]
    for i in range(2, n):
        dp[i][0] = dp[i - 2][0] + A[i]
        dp[i][1] = max(dp[i - 2][1], dp[i - 3][0] if i >= 3 else float("-inf")) + A[i]

    # print(dp)
    print(max(dp[-1][1], dp[-2][0]))
else:
    dp = [[-float("inf")]*3 for i in range(n)]
    dp[0][0] = A[0]
    dp[1][1] = A[1]
    for i in range(2, n):
        dp[i][0] = dp[i-2][0] + A[i]
        dp[i][1] = max(dp[i-2][1], dp[i-3][0] if i>=3 else float("-inf")) + A[i]
        dp[i][2] = max(dp[i-2][2], dp[i-3][1] if i>=3 else float("-inf"), dp[i-4][0] if i>=4 else float("-inf")) + A[i]
        if i == 2:
            dp[i][2] = A[2]

    # print(dp)
    print(max(dp[-1][2], dp[-2][1], dp[-3][0]))

