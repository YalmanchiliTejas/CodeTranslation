# -*- coding: utf-8 -*-
# C

import sys
from collections import defaultdict, deque
from heapq import heappush, heappop
import math
import bisect
import itertools

input = sys.stdin.readline
mod = 10**9 + 7

# 再起回数上限変更
# sys.setrecursionlimit(1000000)

N = int(input())
A = list(map(int, input().split()))

cumA = list(itertools.accumulate(A[::-1]))[::-1]
# print(A, cumA)

ans = 0
for i in range(len(A)-1):
    ans += (A[i] * cumA[i+1]) % mod

print(ans % mod)
