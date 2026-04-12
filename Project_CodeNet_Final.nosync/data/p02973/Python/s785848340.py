import bisect
N = int(input())
arr = [int(input()) for i in range(N)]
dp = [-1 for _ in range(N)]
for i in arr:
    dp[bisect.bisect_left(dp, i) - 1] = i
print(sum([i >= 0 for i in dp]))
