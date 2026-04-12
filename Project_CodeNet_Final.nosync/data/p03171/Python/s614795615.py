n = int(input())
aaa = list(map(int, input().split()))
dp = [[0] * (n + 1) for _ in range(n + 1)]
for w in range(1, n + 1):
    for l in range(n - w + 1):
        r = l + w
        dpl = -dp[l + 1][r] + aaa[l]
        dpr = -dp[l][r - 1] + aaa[r - 1]
        dp[l][r] = max(dpl, dpr)
print(dp[0][n])
