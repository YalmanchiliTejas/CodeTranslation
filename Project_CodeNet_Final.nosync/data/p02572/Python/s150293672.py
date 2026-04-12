import sys
import itertools
# import numpy as np
import time
import math
import heapq
from collections import defaultdict
sys.setrecursionlimit(10 ** 7)
 
INF = 10 ** 9 + 7
read = sys.stdin.buffer.read
readline = sys.stdin.buffer.readline
readlines = sys.stdin.buffer.readlines

# map(int, input().split())

N = int(input())
A = list(map(int, input().split()))

MOD= 10 ** 9 + 7

acc = [0] * (N + 1)
for i in range(1, N + 1):
    acc[i] = acc[i - 1] + A[i - 1]

ans = 0
for i in range(N):
    now = (acc[N] - acc[i + 1]) % MOD
    ans += now * A[i]
    ans %= MOD
print(ans % MOD)