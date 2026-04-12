def LIS(A):
    dp = [-A[0]]
    for a in A[1:]:
        if -a >= dp[-1]:
            dp.append(-a)
        else:
            dp[bisect_right(dp, -a)] = -a
    return len(dp)

##################################################################################################################

import sys
input = sys.stdin.readline
from bisect import *

N = int(input())

A = [int(input()) for _ in range(N)]

print(LIS(A))