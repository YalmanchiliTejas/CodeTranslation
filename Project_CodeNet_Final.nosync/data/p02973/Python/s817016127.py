from bisect import bisect_right
N = int(input())
A = list(int(input()) for _ in range(N))
INF = 10 ** 9 + 1

dp = [INF]
for a in A:
    if -a >= dp[-1]:
        dp.append(-a)
    else:
        j = bisect_right(dp, -a)
        dp[j] = -a

print(len(dp))
