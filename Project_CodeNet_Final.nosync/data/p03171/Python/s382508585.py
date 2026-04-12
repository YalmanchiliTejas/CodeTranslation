n = int(input())
a = list(map(int, input().split()))
dp = [[0] * n for _ in range(n)]
for L in range(n - 1, -1, -1):
    for R in range(L, n):
        if L == R:
            dp[L][R] = a[L]
        else:
            dp[L][R] = max(a[L] - dp[L + 1][R], a[R] - dp[L][R - 1])
print(dp[0][n - 1])