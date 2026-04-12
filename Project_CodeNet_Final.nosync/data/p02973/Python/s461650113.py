# https://atcoder.jp/contests/abc134/tasks/abc134_e　

from bisect import bisect_left
from collections import *

N = int(input())

A = [int(input()) for _ in range(N)]

LIS = deque([A[0]])
cnt = 0

for a in A[1:]:
    if a <= LIS[0]:
        LIS.appendleft(a)
    else:
        ind = bisect_left(LIS, a) -1
        LIS[ind] = a

print(len(LIS))