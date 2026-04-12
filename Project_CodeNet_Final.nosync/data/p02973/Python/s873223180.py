from bisect import *

N = int(input())
A = [-int(input()) for i in range(N)]

dp = [float("inf")]*N

for i in range(N) :
    ind = bisect_right(dp, A[i])
    dp[ind] = A[i]

ans = bisect_left(dp,float("inf"))
print(ans)
