def LIS(A):
    dp = deque([A[0]])
    for a in A[1:]:
        if a <= dp[0]:
            dp.appendleft(a)
        else:
            dp[bisect_left(dp, a)-1] = a
    return len(dp)

##################################################################################################################

import sys
input = sys.stdin.readline
from collections import deque
from bisect import bisect_left

N = int(input())

A = [int(input()) for _ in range(N)]

print(LIS(A))