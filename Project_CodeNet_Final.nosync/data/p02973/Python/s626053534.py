from bisect import bisect_left, bisect_right

N = int(input())
As = [int(input()) for _ in range(N)]


dp = [float('inf')] * (N+1)
for A in reversed(As):
    i = bisect_right(dp, A)
    dp[i] = A

print(dp.index(float('inf')))
