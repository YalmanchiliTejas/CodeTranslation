n = input()
k = int(input())
dp = [[[0] * (k + 2) for i in range(2)] for j in range(len(n) + 1)]
dp[0][0][0] = 1

for i in range(len(n)):
    value = int(n[i])
    for j in range(2):
        for l in range(k + 1):
            for d in range(10 if j == 1 else value + 1):
                dp[i + 1][1 if j == 1 else 1 if (d < value) else 0][l if d == 0 else l + 1] += dp[i][j][l]
print(dp[len(n)][0][k] + dp[len(n)][1][k])