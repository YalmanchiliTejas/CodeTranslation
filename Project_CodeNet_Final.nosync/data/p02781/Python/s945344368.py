import sys
import itertools
# import numpy as np
import time
import math
import heapq
from collections import defaultdict
sys.setrecursionlimit(10 ** 7)
 
INF = 10 ** 18
MOD = 10 ** 9 + 7
read = sys.stdin.buffer.read
readline = sys.stdin.buffer.readline
readlines = sys.stdin.buffer.readlines

# map(int, input().split())

S = input()
K = int(input())

dp = [[[0 for _ in range(2)] for _ in range(4)] for _ in range(102)]

def rec(i, k, is_same):
    if dp[i][k][is_same] != 0:
        return dp[i][k][is_same]
    if k == 0:
        return 1
    if i == 0:
        if k >= 2:
            return 0
        if is_same == 1:
            dp[i][k][is_same] = int(S[len(S) - i - 1])
        else:
            dp[i][k][is_same] = 9
        return dp[i][k][is_same]

    res = 0
    a = int(S[len(S) - i - 1])
    if is_same == 1:
        for x in range(a + 1):
            if x == a and x == 0:
                res += rec(i - 1, k, 1)
            elif x == 0:
                res += rec(i - 1, k, 0)
            elif x == a:
                res += rec(i - 1, k - 1, 1)
            else:
                res += rec(i - 1, k - 1, 0)
    else:
        for x in range(10):
            if x == 0:
                res += rec(i - 1, k, 0)
            else:
                res += rec(i - 1, k - 1, 0)

    dp[i][k][is_same] = res
    return res

n = len(S)
res = rec(n - 1, K, 1)
print(res)