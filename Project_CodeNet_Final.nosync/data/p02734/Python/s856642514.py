# coding: utf-8
import sys
#from operator import itemgetter
sysread = sys.stdin.buffer.readline
read = sys.stdin.buffer.read
#from heapq import heappop, heappush
#from collections import defaultdict
sys.setrecursionlimit(10**7)
#import math
#from itertools import product, accumulate, combinations, product
#import bisect# lower_bound etc
#import numpy as np
#from copy import deepcopy
#from collections import deque
def run():
    N, S = map(int, sysread().split())
    A = [0]+ list(map(int,sysread().split()))
    dp = [[0] * (S+1) for _ in range(N+1)]
    if A[1] <= S:
        dp[1][A[1]] = 1
    mod = 998244353
    for r in range(1, N):
        if A[r+1] <= S:
            dp[r+1][A[r+1]] += r+1
            dp[r + 1][A[r + 1]] %= mod
        for s in range(1,S+1):
            dp[r+1][s] += dp[r][s] + dp[r][s] - dp[r-1][s]
            dp[r+1][s] %= mod
            if s + A[r+1] <= S:
                dp[r+1][s+A[r+1]] += dp[r][s] - dp[r-1][s]
                dp[r + 1][s + A[r + 1]] %= mod
    print(dp[N][S] % mod)


if __name__ == "__main__":
    run()
