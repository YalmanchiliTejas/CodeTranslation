N = int(input())
As = [int(input()) for _ in range(N)]
from bisect import bisect_right
from collections import deque

def LIS(L):
    dp = deque([L[0]])
    length = len(L)
    for i in range(1, length):
        a = L[i]
        if a >= dp[-1]:
            dp.append(a)
        else:
            dp[bisect_right(dp, a)] = a
    return dp

print(len(LIS(As[::-1])))