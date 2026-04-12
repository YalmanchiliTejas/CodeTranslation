from bisect import bisect_right

N = int(input())
A = [int(input()) for _ in range(N)]
INF = float('inf')

dp = [-A[0]]
cnt = 1
for i in range(1, N):
    a = -A[i]
    idx = bisect_right(dp, a)
    if idx == cnt:
        dp.append(a)
        cnt += 1
    else:
        dp[idx] = a

print(cnt)
