import bisect

n = int(input())
a = [int(input()) for _ in range(n)]
dp = [-1 for _ in range(n)]
for i in a:
    dp[bisect.bisect_left(dp, i) - 1] = i

print(sum([i >= 0 for i in dp]))