from sys import exit, setrecursionlimit, stderr
from functools import reduce
from itertools import *
from collections import defaultdict
from bisect import bisect

def read():
  return int(input())

def reads():
  return [int(x) for x in input().split()]

(N, K) = reads()

ans = 0
for b in range(K+1, N+1):
    ans += (N + 1) // b * (b - K) + max(0, (N + 1) % b - K)
    ans += 0 if K > 0 else -1
print(ans)
