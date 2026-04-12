N = int(input())
a = [int(c) for c in input().split()]

dp = [[-1] * N for _ in range(N)]
for L in range(N, -1, -1):
    for R in range(L, N):
        if L == R:
            dp[L][R] = a[L]
        else:
            dp[L][R] = max(a[L] - dp[L+1][R], a[R] - dp[L][R-1])


print(dp[0][N-1])
