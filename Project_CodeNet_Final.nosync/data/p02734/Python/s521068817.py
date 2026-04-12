from collections import defaultdict, deque
import sys
import heapq
import bisect
import math
import itertools
import string
import queue
import copy
import time
sys.setrecursionlimit(10**8)
INF = float('inf')
mod = 998244353
eps = 10**-7


def inp(): return int(sys.stdin.readline())


def inpl(): return list(map(int, sys.stdin.readline().split()))


def inpl_str(): return list(sys.stdin.readline().split())


N, S = inpl()
aa = inpl()

dp = [0 for _ in range(3010)]
dp[0] = 0

ans = 0
for i, a in enumerate(aa):

    if S == a:
        ans += (i+1) * (N-i) % mod
    else:
        ans += dp[S-a] * (N-i) % mod
    ans %= mod

    for s in reversed(range(a, S)):
        if s == a:
            dp[s] += i+1
        else:
            dp[s] += dp[s-a]
        dp[s] %= mod


print(ans)
