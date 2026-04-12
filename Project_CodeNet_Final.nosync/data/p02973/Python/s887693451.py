from bisect import bisect_right
N = int(input())
dp = [float("inf") for _ in range(N+1)]

rows = 0
for _ in range(N):
    c = -float(input())
    i = bisect_right(dp, c)
    if i == rows:
        rows += 1
    dp[i] = c
print(len(list(filter(lambda x:x < float("inf"), dp))))