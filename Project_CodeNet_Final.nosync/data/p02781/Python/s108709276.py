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

import functools

@functools.lru_cache(None)
def rec(i, k, is_same):
    if k == 0:
        return 1
    if i == 0:
        if k >= 2:
            return 0
        if is_same == 1:
            return int(S[len(S) - i - 1])
        else:
            return 9

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
    return res

n = len(S)
res = rec(n - 1, K, 1)
print(res)