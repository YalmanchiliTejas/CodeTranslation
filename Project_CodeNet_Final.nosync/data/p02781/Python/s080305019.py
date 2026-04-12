digits = [int(c) for c in input()]
n = len(digits)
m = int(input())

dp = [[[0 for _ in range(2)] for _ in range(m + 2)] for _ in range(n + 1)]
dp[0][0][0] = 1

for i, digit in enumerate(digits):
    for j in range(m + 1):
        for k in range(2):
            for d in range(10 if k else digit + 1):
                dp[i + 1][j + (d > 0)][k or (d < digit)] += dp[i][j][k]

print(sum(dp[n][m]))