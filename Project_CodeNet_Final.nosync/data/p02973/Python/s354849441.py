def LIS(A):
    dp = [-next(A)]
    for a in A:
        if -a >= dp[-1]:
            dp.append(-a)
        else:
            dp[bisect_right(dp, -a)] = -a
    return len(dp)

##################################################################################################################

import sys
input = sys.stdin.readline
from bisect import bisect_right

A = (int(input()) for _ in range(int(input())))

print(LIS(A))