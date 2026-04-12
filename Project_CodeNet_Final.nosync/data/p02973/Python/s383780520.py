from bisect import *
N = int(input())
A = [-int(input()) for i in range(N)]
dp = [float("inf")]*N
for a in A :
    ind = bisect_right(dp, a)
    dp[ind] = a
print(bisect_left(dp, float("inf")))