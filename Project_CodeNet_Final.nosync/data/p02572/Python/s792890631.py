import sys
read = sys.stdin.readline
import time
from heapq import heappush, heappop, heapify
import math
import itertools as it
from collections import deque 


def inp():
    return int(input())
def inpl():
    return list(map(int, input().split()))
start_time = time.perf_counter()
# ------------------------------


mod = 10**9 + 7

N = inp()
A = inpl()
wa = 0
sm = A[0]
for i in range(1, N):
    wa = (wa + sm * A[i]) % mod
    sm = (sm + A[i]) % mod
print(wa)

# -----------------------------
end_time = time.perf_counter()
print('time:', end_time-start_time, file=sys.stderr)

