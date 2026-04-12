import bisect

N = int(input())
A = [-int(input()) for _ in range(N)]

dp = [float("inf")] * (N+1)
dp[0] = -float("inf")
dp[1] = A[0]

for i in range(1,N):
    dp[bisect.bisect_right(dp, A[i])] = A[i]

for i in reversed(range(N+1)):
    if dp[i] < float("inf"):
        print(i)
        break