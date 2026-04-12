import sys
import itertools
# import numpy as np
import time
import math
import heapq
from collections import defaultdict
from collections import Counter
sys.setrecursionlimit(10 ** 7)
 
INF = 10 ** 18
MOD = 10 ** 9 + 7
read = sys.stdin.buffer.read
readline = sys.stdin.buffer.readline
readlines = sys.stdin.buffer.readlines

# map(int, input().split())
N = int(input())
A = [int(input()) for _ in range(N)]
A = sorted(A)

def solve(pat):
    ans = []
    for i in range(N // 2):
        if pat:
            ans.append(A[N - 1 - i])
            ans.append(A[i])
        else:
            ans.append(A[i])
            ans.append(A[N - 1 - i])
    if N % 2 == 1:
        ans.append(A[N // 2])

    res = 0
    for i in range(1, N - 1):
        res += abs(ans[i] - ans[i - 1])
    x = abs(ans[-2] - ans[-1])
    y = abs(ans[-1] - ans[0])
    return (max(x, y) + res)

print(max(solve(True), solve(False)))